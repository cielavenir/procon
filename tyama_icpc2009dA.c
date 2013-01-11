/*1710-1726*/
int a[50];

main(){
  int n,p,x,c;
  for(;scanf("%d%d",&n,&p),n;printf("%d\n",c)){
    memset(a,0,sizeof(a));
    x=p;
    for(c=0;;c++){
      if(c>=n)c=0;
      if(x){
        x--;
        a[c]++;
        if(!x&&a[c]==p)break;
      }else{
        x+=a[c];
        a[c]=0;
      }
    }
  }
}