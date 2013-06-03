#include <unistd.h>
#include <stdio.h>
#include <string.h>
char s[9],*z="89B1pK00C26w6";
int main(){
	s[0]='t';//for(s[0]='a';s[0]<='z';s[0]++)
	s[1]='a';//for(s[1]='a';s[1]<='z';s[1]++)
	s[2]='n';//for(s[2]='a';s[2]<='z';s[2]++)
	for(s[3]='a';s[3]<='z';s[3]++)
	for(s[4]='a';s[4]<='z';s[4]++)
	for(s[5]='a';s[5]<='z';s[5]++)
	for(s[6]='a';s[6]<='z';s[6]++)
	for(s[7]='a';s[7]<='z';s[7]++){
		if(!strcmp(crypt(s,"89"),z))puts(s);
	}
}