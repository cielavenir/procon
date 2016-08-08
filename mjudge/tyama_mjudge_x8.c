int main(){
  char s[11];
  int i;
  while(~scanf("%s",s)){
    int x=0;
    printf("%s: ",s);
    for(i=0;i<10;i++)
      s[i] = s[i]=='X' ? 10 : s[i]-'0';
    for(i=0;i<10;i++)
      x+=s[i]*(10-i);
    printf(x%11 ? "false\n" : "true\n");
  }
  return 0;
}