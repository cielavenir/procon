char x[100][100];
correction(n){
  int i=0,j,a,l=0,m=0;
  for(;i<n;i++)
    for(j=0;j<n;j++){
      scanf("%d",&a);
      x[i][j]=a-'0';
    }

  for(i=0;i<n;i++){
    a=0;
    for(j=0;j<n;j++){
      a+=x[i][j];
    }
    if(a&1)
      if(l){puts("Corrupt");return;}
      else l=i;
  }

  for(j=0;j<n;j++){
    a=0;
    for(i=0;i<n;i++){
      a+=x[i][j];
    }
    if(a&1)
      if(m){puts("Corrupt");return;}
      else m=j;
  }

  if(!m)puts("OK");
  else printf("Change bit (%d,%d)\n",l+1,m+1);
}

main(n){for(;scanf("%d",&n),n;correction(n));}