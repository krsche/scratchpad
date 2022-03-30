#!/bin/bash

xmlstarlet ed -P -N s=http://www.w3.org/2000/svg -s "s:svg/s:g/s:svg[@id='compo1']" -t elem -n gTEMP -v "SOMETHING_INSIDE" \
    -i //gTEMP -t attr -n x -v 0 \
    -i //gTEMP -t attr -n y -v 0 \
    -i //gTEMP -t attr -n height -v "100%" \
    -i //gTEMP -t attr -n width -v "100%" \
    -i //gTEMP -t attr -n filter -v "url(#f1)" \
    -r //gTEMP -v g \
    template.svg