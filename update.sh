#!/bin/zsh
#git update
is_date='date +%Y.%m.%d'
git add .
git commit -m "${is_date}"
git push cpp master
