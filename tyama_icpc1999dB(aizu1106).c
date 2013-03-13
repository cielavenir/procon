main(a,b,c,p,q,r,s,i,j){for(;scanf("%d%d%d",&a,&b,&c),a;){
if(!c)a==1&&b<0?printf("1 0 %d %d\n",a,b):printf("%d %d 1 0\n",a,b);
else{
	for(r=1;r*r<=a;r++)if(a%r==0)for(p=a/r,s=1;s*s<=abs(c);s++)if(c%s==0)for(j=0;j<2;j++,s=c/s)for(i=0;i<2;i++,s=-s)if(q=c/s,p*s+q*r==b)
		{p==r&&q<s?printf("%d %d %d %d\n",r,s,p,q):printf("%d %d %d %d\n",p,q,r,s);goto next;}
	puts("Impossible");
}next:;}exit(0);}