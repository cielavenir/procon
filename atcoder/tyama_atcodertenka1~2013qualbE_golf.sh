#!/bin/bash
set -eu
echo 100
echo 1 0
n=99
while [ $n -ne 1 ]; do
	echo $n 0
	n=$((n - 1))
done
echo 0 0