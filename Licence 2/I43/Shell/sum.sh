#!/bin/bash

# EXO 25 de 2017

somme=0
for i in `seq 1 $1`
do
	if [ $(( $i % 2 )) == 1 ]; then
		somme=$(($somme+$i))  	
	fi	
done
echo $somme
