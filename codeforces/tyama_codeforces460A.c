main(n,m,i,j){
scanf("%d%d",&n,&m);
for(i=n,j=1;i;j++,i--)i+=j%m==0;
printf("%d\n",j-1);
return 0;
}