#!/bin/zsh
a=''
b=''
c=$1
find . -type f -name "$1.*" -print0 | while IFS= read -r -d '' file; do
    a="${file#*/}"
    b="${a%.*}"
done

clang++ -std=c++2b $b.cpp -o $b.out $2 && $b.out
echo "\n"

rm **/*.out
