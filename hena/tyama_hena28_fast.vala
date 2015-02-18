#!/usr/bin/env vala
//http://qiita.com/Nabetani/items/23ebddb44f0234e7fb15
//http://nabetani.sakura.ne.jp/hena/ord28spirwa/
static void main(){
	string dir="ESWN";
	int n=0,e=0,s=0,w=0;
	int64 days=0;
	for(;stdin.scanf("%d,%d,%d,%d:%"+int64.FORMAT_MODIFIER+"d",&n,&e,&s,&w,&days)!=-1;){
		days+=1;
		int[] l={e,s,w,n};
		int i=0,j,f=1;
		for(;f!=0;i++){
			int[] x={l[i%4]+(i%4==0?1:0),(i/4+1)*2,l[i%4]-(i%4==3?1:0)};
			for(j=0;j<3;j++){
				if(days-x[j]<0){
					stdout.printf("%c\n",dir[(i+j)%4]);
					f=0;
					break;
				}
				days-=x[j];
			}
		}
		stdout.flush();
	}
}