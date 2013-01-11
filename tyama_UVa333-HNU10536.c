main(){
  int c,n[10],f=0,i=0,a=0;
  char s[99];
  for(;~scanf("%s",s);scanf("%*[^\n]")){
    for(a=0;s[a];a++){
      c=s[a];
      if(c=='-'){if(i==0)f=1;if(a&&s[a-1]=='-')f=1;continue;}
      if(i<10&&'0'<=c&&c<='9'||(c=='X'&&i==9)){
        n[i]=c=='X'?10:(c-'0'),i++;
        continue;
      }
      f=1;
    }
    if(i!=10)f=1;
    if(!f){
      for(i=1;i<10;i++)n[i]+=n[i-1];
      for(i=1;i<10;i++)n[i]+=n[i-1];
      f=n[9]%11;
    }
    printf("%s is %scorrect.\n",s,f?"in":"");
    f=i=0;
  }
  return 0;
}