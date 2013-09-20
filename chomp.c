#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
int main(){
	DIR *d=opendir(".");
	struct dirent *ent;
	struct stat st;
	for(;ent=readdir(d);){
		//if(!strcmp(ent->d_name,".")||!strcmp(ent->d_name,".."))continue;
		FILE *f=fopen(ent->d_name,"rb+");
		if(f){
			fstat(fileno(f),&st);
			fseek(f,st.st_size-1,SEEK_SET);
			int c=fgetc(f);
			if(c=='\r')fputc('\n',f);
			if(c=='\n')ftruncate(fileno(f),st.st_size-1);
			fclose(f);
		}
	}
	closedir(d);
	return 0;
}