int main(){
  int n,i,a,b,d,v;
  while(scanf("%d",&n),n){
    v=0;
    for(i=0;i<n;i++){
      scanf("%d%d",&a,&b);
      a+=b;
      if(v<a){v=a;d=i;}
    }
    printf("%d\n",v<9?0:d+1);
  }
}