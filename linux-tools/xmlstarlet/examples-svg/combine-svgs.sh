#!/bin/bash

# What I'm trying to achieve:
# Show the differences of two schematics, exported as svgs, by combining them into a pre-defined `template.svg` which 
# changes the colors and makes the diffs visible. 
# [KiCad-Diff](https://github.com/Gasman2014/KiCad-Diff) is a nice tools which can be used for that already, but does
# not produce a combined svg (yet).
# The goal is to generate and add the combined svg to a GitHub PR automatically via a workflow.
#
# `left.svg` and `right.svg` are two schmatic images exported from kicad-diff, with slight differences
# `template.svg` is the template used by kicad-diff to display both svgs in the browser, referencing them with image 
# tags.
# --> Using only bash/linux stuff: Replace the image tags with the actual image contents producing a similar result.
#
# At the end the svg can be optimized to shrink its size and remove inline styles which can cause CORS errors when
# served by GH.

set -eou pipefail

FILE_LEFT=${1:-left.svg}
FILE_RIGHT=${2:-right.svg}
FILE_TEMPLATE=${3:-template.svg}
FILE_RESULT=${4:-result.svg}

LEFT=
RIGHT=
RESULT=

# delete all <image/> elements
RESULT=`xmlstarlet ed -N s=http://www.w3.org/2000/svg -d "s:svg/s:g/s:svg/s:image" $FILE_TEMPLATE`

# extract image data
LEFT=`xmlstarlet sel -N s=http://www.w3.org/2000/svg -t -c "//s:svg" $FILE_LEFT`
RIGHT=`xmlstarlet sel -N s=http://www.w3.org/2000/svg -t -c "//s:svg" $FILE_RIGHT`

# add containers with filter and insert image data
# left (compo1)
RESULT=`echo "$RESULT" | xmlstarlet ed -P -N s=http://www.w3.org/2000/svg \
    -s "s:svg/s:g/s:svg[@id='compo1']" -t elem -n gTEMP -v "$LEFT" \
    -i //gTEMP -t attr -n x -v 0 \
    -i //gTEMP -t attr -n y -v 0 \
    -i //gTEMP -t attr -n height -v "100%" \
    -i //gTEMP -t attr -n width -v "100%" \
    -i //gTEMP -t attr -n filter -v "url(#f1)" \
    -r //gTEMP -v g`

# right (compo2)
RESULT=`echo "$RESULT" | xmlstarlet ed -P -N s=http://www.w3.org/2000/svg \
    -s "s:svg/s:g/s:svg[@id='compo2']" -t elem -n gTEMP -v "$RIGHT" \
    -i //gTEMP -t attr -n x -v 0 \
    -i //gTEMP -t attr -n y -v 0 \
    -i //gTEMP -t attr -n height -v "100%" \
    -i //gTEMP -t attr -n width -v "100%" \
    -i //gTEMP -t attr -n filter -v "url(#f2)" \
    -r //gTEMP -v g`

# replace &lt; and &gt; substituted by xmlstarlet with < and > respectively
RESULT=`echo "$RESULT" | sed -e 's/&lt;/</g' -e 's/&gt;/>/g'`

# save to file
echo "$RESULT" > $FILE_RESULT
