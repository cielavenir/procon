#include <stdio.h>
#include <sys/stat.h>
int main(){
	struct stat st;
	fstat((fileno(stdin)),&st);
	printf("%d\n",st.st_size);
	return 0;
}