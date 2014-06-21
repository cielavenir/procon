char s[99];
main(){
	long long v=-1;
	int c,n,d=0,f=0;
	for(;;){
		c=getchar();
		if(c=='0'){
			if(f)s[d++]=v;
			else v++;
		}else if(c==' '){
			f^=1;
			if(!f)v=-1;
		}else{
			if(d){
				for(v=f=0;f<d;f++){v=v*2+s[f];}
				printf("%lld\n",v);
			}
			if(c<0)break;
			v=-1;d=0;f=0;
		}
	}
}