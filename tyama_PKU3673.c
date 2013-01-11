#define between(a,x,b) ((a)<=(x)&&(x)<=(b))
char x[10],y[10];

int main(){
  int i=0,j=0,c,f=0,p,q,s=0;
  while((c=getchar())!=-1){
    if(between('0',c,'9'))
      if(f)
        y[j++]=c-'0';
      else
        x[i++]=c-'0';
    else
      f=1;
  }
  for(p=0;p<i;p++)
    for(q=0;q<j;q++)
      s+=x[p]*y[q];
  printf("%d",s);
}