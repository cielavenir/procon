read x
read y
if [ $x -gt $y ];then
	echo X is greater than Y
elif [ $x -lt $y ];then
	echo X is lesser than Y
else
	echo X is equal to Y
fi