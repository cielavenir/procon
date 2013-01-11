char a[101];main(i,j,k,l,c,m){scanf("%s",a);l=strlen(a);
for(i=m=0;i<l;i++)
  for(j=i+1;j<l;j++,m=c>m?c:m)
    for(c=k=0;j+k<l;k++,c++)
      if(a[i+k]!=a[j+k])break;
printf("%d\n",m);exit(0);}