#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

char *table=" AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
int main(){
	int i,n,l;
	char p[99];
	scanf("%d",&n);
	for(;n;n--){
		scanf("%s",p);
		l=strlen(p);
		for(i=0;i<l;i++)p[i]=strchr(table,p[i])-table;
		sort(p,p+l);
		do{
			for(i=0;i<l;i++)putchar(table[p[i]]);
			puts("");
		}while(next_permutation(p,p+l));
	}
}