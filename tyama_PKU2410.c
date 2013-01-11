unsigned char a,p;s[3];m[32];main(o,x){for(;;puts("")){
	for(p=0;p<32;m[p]=strtol(s,0,2),p++)if(scanf("%s",s)==-1)return;
	for(a=p=0;;){
		o=m[p]>>5,x=m[p]&31;p=(p+1)&31;
		if(!o)m[x]=a;
		if(o==1)a=m[x];
		if((o==2&&!a)||o==6)p=x;
		if(o==4)a--;
		if(o==5)a++;
		if(o==7)break;
	}
	for(o=7;o>=0;o--)printf("%d",(a>>o)&1);
}}