main(){
	int m=99,n=0,c=0;
	for(;~c;){
		c=getchar();
		if(c=='\n'||!(~c)){
			if(m>n)m=n;
			printf("%d\n",m);
			n=0;
			m=99;
		}else if(c=='.'){
			n++;
		}else if(c==','){
			if(m>n)m=n;
			n=0;
		}
	}
}