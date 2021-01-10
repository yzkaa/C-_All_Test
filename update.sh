#!/bin/zsh
#git update
is_date=`date "+%Y.%m.%d"`
cd ~/C++
git add .
git commit -m "${is_date}"
git push cpp master

cd ~/Nutstore Files/
git add .
git commit -m "${is_date}"
git push note master

