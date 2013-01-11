int isx(int x){
  if(!(x%7))return x;
  while(x){
    if(x%10==7)return x;
    x/=10;
  }
  return 0;
}

int main(){
  int v[101]={0},m=0,i=1;
  for(;i<800;i++){
    if(!isx(i)){m=0;continue;}
    m++;
    if(!v[m])v[m]=i-m+1;
  }
  scanf("%d",&m);
  for(;m;m--){
    scanf("%d",&i);
    printf("%d\n",v[i]);
  }
}