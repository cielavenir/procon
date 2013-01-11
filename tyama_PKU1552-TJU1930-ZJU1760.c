int table[100];

int main(){
  int n;
  loop:
    scanf("%d",&n);
    if(n==-1)return 0;
    if(n==0){
      int i=1,s=0;
      for(;i<50;i++)
        if(table[i]&&table[2*i])s++;
      printf("%d\n",s);
      memset(table,0,sizeof(table));
      goto loop;
    }
    table[n]++;
    goto loop;
}