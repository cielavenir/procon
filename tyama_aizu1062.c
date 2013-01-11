#define zone(h) ( (11<=(h)&&(h)<15)?0:(18<=(h)&&(h)<21)?1:(21<=(h)&&(h)<26)?2:3 )
int a[3],b[3];
char s[9];char *r(int i){strcpy(s,"no guest");if(a[i])sprintf(s,"%d",b[i]*100/a[i]);return s;}
main(n,h,m,H,M){
	for(;scanf("%d",&n),n;){
		a[0]=a[1]=a[2]=b[0]=b[1]=b[2]=0;
		for(;n;n--){
			scanf("%d:%d %d",&h,&m,&M);
			if(h<2)h+=24;
			H=M<m?h+1:h;
			if(zone(h)>2)continue;
			a[zone(h)]++;
			if((H*60+M)-(h*60+m)<=8)b[zone(h)]++;
		}
		printf("lunch %s\n",r(0));
		printf("dinner %s\n",r(1));
		printf("midnight %s\n",r(2));
	}
	return 0;
}