#!/bin/bash

# EXO 22

count=0
for annee in `seq $1 $2`; do
	jour=`date +"%A" -d 05/01/${annee}`
	if [[ "$jour" == "samedi" || "$jour" == "dimanche" ]]; then
		let count++
	fi
done	
echo $count

