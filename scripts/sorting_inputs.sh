#!/bin/zsh
counts=("10" "100" "1000" "10000" "100000" "200000" "300000" "500000")
for count in $counts;
do
  # python scripts/generate.py $count inc $1
  python scripts/random1.py $count $1
done
for count in $counts;
do
  # python scripts/generate.py $count dec $1
  python scripts/random1.py $count $1
done
