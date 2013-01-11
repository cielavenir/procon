#define between(a,x,b) ((a)<=(x)&&(x)<=(b))
char a[99999];
int code(char *s){
  if(!s[0]||!s[1])return 1;
  if(s[1]=='0')return code(s+2);
  switch(s[0]){
    case '1': return code(s+1)+(s[2]!='0'?code(s+2):0);
    case '2': return code(s+1)+((s[2]!='0'&&between('1',s[1],'6'))?code(s+2):0);
    default: return code(s+1);
  }
}
main(){for(;~scanf("%s",a),*a-'0';printf("%d\n",code(a)));}