int score[100];
int table[100];
char map[100][51];

int main(){
  int n,m,i,j,a,b;
  char str[51],c;
  scanf("%d%d",&n,&m);
  for(i=0;i<m;i++)
    table[i]=i;
  for(i=0;i<m;i++){
    scanf("%s",map[i]);
    strcpy(str,map[i]);
    for(a=0;a<n;a++)
      for(b=a+1;b<n;b++)
        if(str[a]>str[b])score[i]++;
    score[i]=score[i]*m+i;
  }
  for(i=0;i<m;i++)
    for(j=i+1;j<m;j++)
      if(score[table[i]]>score[table[j]])
        {a=table[j];table[j]=table[i];table[i]=a;}
  for(i=0;i<m;i++)
    printf("%s\n",map[table[i]]);
}

/* bootstrap for ZJU1188 */
/*
int main(){
  int n;
  scanf("%d",&n);
  for(;n;n--){
    memset(score,0,sizeof(score));
    memset(table,0,sizeof(table));
    memset(map,0,sizeof(map));
    _main();
    if(n>1)puts("");
  }
}
*/