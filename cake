#!/bin/zsh
a=''
b=''
c=$2

Help() {
   echo "Runs C/C++ files adequately well!"
   echo
   echo "Syntax: cake [-h/-b/-r] [A]"
   echo "Options:"
   echo "-h\\tHelp. Pls. Shows this text when you inevitably forget what this command does. I'm already disappointed in you."
   echo "-b\\tBuilds the specified file (A). DOES NOT RUN, SO DON'T FREAK OUT. I'M NOT YELLING YOU ARE-"
   echo "-r\\tRuns the specified file (A). Removes the executable after running."
   echo " A\\tName of the file. Path is irrelevant. I can look."
   echo
}

Build() {
    find . -type f -name "$c.*" -print0 | while IFS= read -r -d '' file; do
        a="${file#*/}"
        b="${a%.*}"
    done
    clang++ -Wall -std=c++2b $b.cpp -o $b.out
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
