#include <algorithm>
#include <cstdio>
#include <cstring>
int pal(int n){
	char s[9],t[9];
	sprintf(s,"%d",n);
	strcpy(t,s);
	std::reverse(t,t+strlen(t));
	return strcmp(t,s);
}
main(){
	int n,i;
	scanf("%d",&n);
	for(i=0;;i++){
		if(!pal(n-i)){printf("%d\n",n-i);return 0;}
		if(!pal(n+i)){printf("%d\n",n+i);return 0;}
	}
}