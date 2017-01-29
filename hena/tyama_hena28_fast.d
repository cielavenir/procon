#!/usr/bin/env rdmd
// http://qiita.com/Nabetani/items/23ebddb44f0234e7fb15
// http://nabetani.sakura.ne.jp/hena/ord28spirwa/

import core.stdc.stdio;

int main(){
	const char* dir="ESWN";
	int n,e,s,w;
	long days;
	for(;~scanf("%d,%d,%d,%d:%lld",&n,&e,&s,&w,&days);){
		days+=1;
		int[] l=[e,s,w,n];
		int f=1;
		for(int i=0;f;i++){
			int[] x=[l[i%4]+(i%4==0),(i/4+1)*2,l[i%4]-(i%4==3)];
			for(int j=0;j<3;j++){
				if(days-x[j]<0){
					printf("%c\n",dir[(i+j)%4]);
					f=0;
					break;
				}
				days-=x[j];
			}
		}
		fflush(stdout);
	}
	return 0;
}
