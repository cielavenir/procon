#!/usr/bin/awk -f
{
	if($1){
		for(r=i=0;++i<$1;r%=i)r+=$2
		print (r+$3)%$1+1
	}
}