#!/bin/zsh
a=''
b=''
c=$2

Help() {
   echo "Runs the C/C++ file very nicely if I do say so myself!"
   echo
   echo "Syntax: cake [A]"
   echo "options:"
   echo "A     Name of the file. Path is irrelevant as I have a brain and I can search."
   echo
}

Build() {
    find . -type f -name "$c.*" -print0 | while IFS= read -r -d '' file; do
        a="${file#*/}"
        b="${a%.*}"
    done
    clang++ -std=c++2b $b.cpp -o $b.out
}

Run() {
    $b.out
    echo "\n"
    rm **/*.out
}

while getopts "hr:b:" option; do
   case $option in
      r)
         Build
         Run
         exit;;
      b)
         Build
         exit;;
      h)
         Help
         exit;;
     \?)
         echo "Error: Invalid option"
         exit;;
   esac
done
