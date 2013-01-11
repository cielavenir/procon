int main(){
int i,x,y;
scanf("%d",&i);
for(;i;i--){
  int a;
  scanf("%d%d",&x,&y);
  if(x-y!=0&&x-y!=2){
    printf("No Number\n");
    continue;
  }
  a=2*(y-(y&1));
  if(y&1)a+=1;
  if(x-y==2)a+=2;
  printf("%d\n",a);
}
return 0;
}