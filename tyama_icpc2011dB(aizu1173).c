#include<stdio.h>
char S[999],v[999];main(T,C,i){
for(;fgets(S,999,stdin),S[2];puts(T?"no":"yes")){
	for(T=C=i=0;i<strlen(S);i++)
	switch(S[i]){
		case'(':v[C++]=1;break;
		case'[':v[C++]=2;break;
		case')':if(!C||v[--C]!=1)goto F;break;
		case']':if(!C||v[--C]!=2)goto F;break;
	}
	if(!C)continue;
	F:T=1;
}exit(0);}