#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;

int main(int argc, char **argv){
	//FILE *f=fopen(argv[1],"r");
	char line[1024];
	for(;~fscanf(stdin,"%s",line);putchar('\n')){
		string s=line;
		sort(s.begin(),s.end());
		int i=0;do{
			if(i)putchar(',');
			i++;
			printf("%s",s.c_str());
		}while(next_permutation(s.begin(),s.end()));
	}
	fclose(f);
}