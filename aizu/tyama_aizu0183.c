char s[10];main(){for(;scanf("%s%s%s",s,s+3,s+6)>2;)
if(s[0]==s[1]&&s[0]==s[2]&&s[0]-'+')printf("%c\n",s[0]);
else if(s[3]==s[4]&&s[3]==s[5]&&s[3]-'+')printf("%c\n",s[3]);
else if(s[6]==s[7]&&s[6]==s[8]&&s[6]-'+')printf("%c\n",s[6]);
else if(s[0]==s[3]&&s[0]==s[6]&&s[0]-'+')printf("%c\n",s[0]);
else if(s[1]==s[4]&&s[1]==s[7]&&s[1]-'+')printf("%c\n",s[1]);
else if(s[2]==s[5]&&s[2]==s[8]&&s[2]-'+')printf("%c\n",s[2]);
else if(s[0]==s[4]&&s[0]==s[8]&&s[0]-'+')printf("%c\n",s[0]);
else if(s[2]==s[4]&&s[2]==s[6]&&s[2]-'+')printf("%c\n",s[2]);
else puts("NA");exit(0);}