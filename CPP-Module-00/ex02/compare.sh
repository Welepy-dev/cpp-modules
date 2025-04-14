#!/bin/bash


if [ "$#" -ne 2 ]; then
	echo "Usage: $0 file1 file2"
	exit 1
fi

file1="$1"
file2="$2"


if [ ! -f "$file1" ]; then
	echo "File not found: $file1"
	exit 1
fi

if [ ! -f "$file2" ]; then
	echo "File not found: $file2"
	exit 1
fi


line_number=1
while IFS= read -r line1 || [ -n "$line1" ]; do
	IFS= read -r line2 <&3 || line2=""

	
	cmp1="${line1:18}"
	cmp2="${line2:18}"

	if [ "$cmp1" != "$cmp2" ]; then
		echo "Difference at line $line_number:"
		echo "File1: $line1"
		echo "File2: $line2"
		echo "----------------------"
	fi

	line_number=$((line_number + 1))
done <"$file1" 3<"$file2"
