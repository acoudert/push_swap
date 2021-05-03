#!/bin/bash

function generate_nb()
{
	arr+=(${RANDOM:0:5})
	while [ ${#arr[@]} -lt $1 ]
	do
		nb=${RANDOM:0:5}
		for j in "${arr[@]}"
		do
			if [ $j == $nb ]
			then
				break
			fi
			if [ $j == ${arr[-1]} ]
			then
				arr+=($nb)
			fi
		done
	done
}


if [ $# -ne 2 ]
then
	echo "Usage: ./tester.sh [stack_nb_elems] [nb_of_tests]"
	echo "Example: ./tester.sh 500 5"
	exit
fi

sum=()
total=0
for (( i=1; i<=$2; i++))
do
	arr=()
	generate_nb $1
	string=""
	for j in "${arr[@]}"
	do
		string+="$j "
	done
	res=$(./push_swap -q $string | wc -l)
	#./push_swap -q $string
	total=$(expr $total + $res)
	sum+=($res)
done
echo $(expr $total / ${#sum[@]})
