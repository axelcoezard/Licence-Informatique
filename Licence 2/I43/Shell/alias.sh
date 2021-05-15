#!/bin/bash

# EXO 26 de 2018

for arg in $@
do
	argType=`type -t ${arg}`
	echo "$arg: $argType"
done
