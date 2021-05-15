#!/bin/bash

# EXO 26 de 2017

for arg in $@
do
	argType=`type -t ${arg}`
	echo "$arg: $argType"
done
