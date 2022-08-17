#!/bin/zsh
outputName="${1}/${3}.csv"
echo "n, g(n), f(n)" > ${outputName}

# generation
folder="inputs"
counts=("10" "100" "1000" "10000" "100000" "200000" "300000" "500000")
for count in $counts;
do
  # ./run.sh $1 $2 < ./${folder}/ascending_${count}.txt >> ${outputName}
  ./run.sh $1 $2 < ./${folder}/array_${count}.txt >> ${outputName}
done
# for count in $counts;
# do
  # ./run.sh $1 $2 < ./${folder}/array_${count}.txt >> ${outputName}
  # ./run.sh $1 $2 < ./${folder}/descending_${count}.txt >> ${outputName}
# done
