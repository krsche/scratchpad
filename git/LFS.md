# Git LFS

## Setup
```bash
# Try this
git lfs install

# If it doesnt work, first install lfs traditionally
# Ubuntu:
sudo apt-get install git-lfs

# Now try this again to install in repo
git lfs install

# Mark files for lfs with
git lfs track "*.png"

# add auto-create/updated .gitattributes file
git add .gitattributes
```

## Daily
```bash
# Check if files will be committed properly
# NOTE: all files tracked in the repo will be shown, not only LFS files
#       Check the brackets for '(LFS: ' to see which files are tracked
#       as git-lfs objects!
#       More info: https://github.com/git-lfs/git-lfs/issues/3552
git lfs status

# List all lfs files in repo
git lfs ls-files
```