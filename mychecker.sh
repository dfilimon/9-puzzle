#!/bin/bash

for i in {1..12}; do	
	$1 "in-t$i.txt" out
	$2 "in-t$i.txt" out 
done
