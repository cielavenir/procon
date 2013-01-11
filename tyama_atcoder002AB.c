#define C(y)(y%4?0:!(y%400)?1:!(y%100)?0:1)
a[13]={0,31,0,31,30,31,30,31,31,30,31,30,31};
main(y,m,d){
	scanf("%d/%d/%d",&y,&m,&d);
	a[2]=C(y)?29:28;
	for(;d<=a[m];d++)if(!(y%(m*d)))goto P;
	for(m++;m<13;m++)for(d=1;d<=a[m];d++)if(!(y%(m*d)))goto P;
	y++,m=d=1;
	P:printf("%04d/%02d/%02d\n",y,m,d);
	exit(0);
}
//main(x){scanf("%d",&x);puts(C(x)?"YES":"NO");exit(0);}