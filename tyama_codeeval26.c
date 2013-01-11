#include <stdio.h>
#include <sys/stat.h>
int main(int argc, char **argv){
	struct stat st;
	stat(argv[1],&st);
	printf("%d\n",st.st_size);
	return 0;
}