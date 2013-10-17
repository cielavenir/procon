#define between(a,x,b) ((a)<=(x)&&(x)<=(b))
#define M 5001
char a[M];
int f[M];
int code(char *s){
  int c=0,r=1;
  for(;*s;s++){
    if(s[0]=='1'){
      if(s[1]=='0'){r*=f[c];c=0;continue;}
      c++;
    }else if(s[0]=='2'){
      if(s[1]=='0'){r*=f[c];c=0;continue;}
      if(between('1',s[1],'6')){c++;continue;}
      r*=f[c+1];
      c=0;
    }else{
      r*=f[c+1];
      c=0;
    }
  }
  r*=f[c];
  return r;
}
main(i){f[0]=f[1]=1;for(i=2;i<M;i++)f[i]=f[i-1]+f[i-2];for(;~scanf("%s",a),*a-'0';printf("%d\n",code(a)));}