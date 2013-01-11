int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}

int main(){
  int (*f)(int,int);
  int n,m,r,i;
  char s[9];

  scanf("%d",&n);
  for(;n;n--){
    scanf("%s",s);
    f=(s[0]=='F')?min:max;
    r=(s[0]=='F')?2008:0;
    scanf("%d",&m);
    for(;m;m--){
      scanf("%d",&i);
      r=f(r,i);
    }
    printf("%d\n",r);
  }
}