char m[7][7]={
  "      ",
  " abcde",
  " fghij",
  " klmno",
  " pqrst",
  " uvwxy",
  " z.?! "
};

main(f,i,j){
  char s[201],z[101];
  for(;~scanf("%s",s);){
    if(strlen(s)&1){puts("NA");goto l;}
    for(i=0;i<strlen(s)/2;i++){
      if(!('1'<=s[2*i]&&s[2*i]<='6'&&'1'<=s[2*i+1]&&s[2*i+1]<='5')){puts("NA");goto l;}
      z[i]=m[s[2*i]-'0'][s[2*i+1]-'0'];
    }
    z[i]=0;
    puts(z);
    l:;
  }
  return 0;
}