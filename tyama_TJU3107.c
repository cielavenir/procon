int x[5000];
int d[5000];
int c[5000];

void lds(n){
  int i,j,I,C;
  for(i=0;i<n;i++){
    I=0;C=1;
    for(j=i-1;~j;j--){
      if(x[j]>x[i]){
        if(I==d[j])C+=c[j];
        if(I<d[j])I=d[j],C=c[j];
      }
    }
    d[i]=I+1;
    c[i]=C;
  }
  for(C=1,i=j=0;i<n;i++){
    if(d[i]==d[j]&&C<c[j])C=c[j];
    if(d[i]>d[j])
      j=i,C=c[i];
  }
  printf("%d %d\n",d[j],C);
}

main(i,n){scanf("%d",&n);for(i=0;i<n;i++)scanf("%d",x+i);lds(n);}