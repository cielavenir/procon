char s[10];main(){for(;~(scanf("%s",s));)
if(s[0]==s[1]&&s[0]==s[2]&&s[0]-'s')printf("%c\n",s[0]);
else if(s[3]==s[4]&&s[3]==s[5]&&s[3]-'s')printf("%c\n",s[3]);
else if(s[6]==s[7]&&s[6]==s[8]&&s[6]-'s')printf("%c\n",s[6]);
else if(s[0]==s[3]&&s[0]==s[6]&&s[0]-'s')printf("%c\n",s[0]);
else if(s[1]==s[4]&&s[1]==s[7]&&s[1]-'s')printf("%c\n",s[1]);
else if(s[2]==s[5]&&s[2]==s[8]&&s[2]-'s')printf("%c\n",s[2]);
else if(s[0]==s[4]&&s[0]==s[8]&&s[0]-'s')printf("%c\n",s[0]);
else if(s[2]==s[4]&&s[2]==s[6]&&s[2]-'s')printf("%c\n",s[2]);
else puts("d");exit(0);}