/* Do I have to optimize so highly? */
int p[1000001],q[1000001];

void createtable(){
  int i,j,k;

  p[0]=p[1]=1;
  for(i=2;i<=1000000;i++)
    if(!p[i])
      for(j=i*2;j<=1000000;j+=i)
        p[j]=1;
  for(i=1;i<=1000;i++)
    for(j=1;(k=i*i+j*j)<=1000000;j++)
      if(!p[k])
        q[k]=1;

  for(i=j=k=0;i<=1000000;i++){
    j+=!p[i];p[i]=j;
    k+=q[i];q[i]=k;
  }
}

int main(){
  int l,u;
  createtable();
  while(scanf("%d%d",&l,&u),~l||~u){
    printf("%d %d ",l,u);
    if(l<0)l=0;
    if(u<0)u=0;
    printf("%d %d\n",p[u]-p[l-1],q[u]-q[l-1]);
  }
}