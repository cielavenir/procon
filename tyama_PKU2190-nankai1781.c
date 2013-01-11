int main(){
  char s[11];
  int i,x=0,p,r=0;
  scanf("%s",s);
  for(i=0;i<10;i++){
      if(s[i]=='?'){p=i;continue;}
      x += (s[i]=='X' ? 10 : s[i]-'0') * (10-i);
  }
  while(x%11){x+=10-p;r++;}
  if(r>10||(r==10&&p!=9))
    printf("-1\n",p);
  else if(r==10)
    printf("X\n");
  else
    printf("%d\n",r);
  return 0;
}