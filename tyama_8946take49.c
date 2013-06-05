#include <unistd.h>
#include <stdio.h>
#include <string.h>
char s[10]="tanaka  @",*z="89B1pK00C26w6";
int main(){
	for(s[6]='a';s[6]<='z';s[6]++)
	for(s[7]='a';s[7]<='z';s[7]++){
		if(!strcmp(crypt(s,"89"),z))puts(s);
	}
}