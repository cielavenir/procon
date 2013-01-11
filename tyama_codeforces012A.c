char s[3][4];
main(i){
  for(i=0;i<3;i++)scanf("%s",s[i]);
  puts(s[0][0]==s[2][2]&&s[0][1]==s[2][1]&&s[0][2]==s[2][0]&&s[1][0]==s[1][2]?"YES":"NO");
  return 0;
}