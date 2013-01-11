/* replace 10001 with 1000001 for ZJU1180 */
int x[10001];

int createtable(){
  int i=1;
  memset(x,0,sizeof(x));
  for(;i<10001;i++){
    int n=i,s=0;
    while(n){s+=n%10;n/=10;}
    if(s&&i+s<10001)x[i+s]=i;
  }
}

int main(){
  int i=1;
  createtable();
  for(;i<10001;i++)
    if(!x[i])
      printf("%d\n",i);
}