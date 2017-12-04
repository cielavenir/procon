//C99 or C++98
#include <stdio.h>
#include <string.h>

int a[26][26];
char s[99],t[99];
int main(){
loop:
    const int INF=1<<29;
    int m,n;
    for(int i=0;i<26;i++)for(int j=0;j<26;j++)a[i][j]=(i!=j ? INF : 0);
	if(scanf("%d%d",&m,&n)<0)return 0;
    for(;m--;){
        scanf("%s%s",s,t);
        a[*s-'a'][*t-'a']=1;
    }
    for(int k=0;k<26;k++)for(int i=0;i<26;i++)for(int j=0;j<26;j++){
        if(a[i][j]>a[i][k]+a[k][j])a[i][j]=a[i][k]+a[k][j];
    }
    for(;n--;){
        scanf("%s%s",s,t);
        if(strlen(s)!=strlen(t))puts("no");
        else{
            int i=0;
            for(;i<strlen(s)&&a[s[i]-'a'][t[i]-'a']<INF;i++);
            puts(i<strlen(s) ? "no" : "yes");
        }
    }
goto loop;
}
