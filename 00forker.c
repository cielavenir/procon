#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv){
	if(argc<3){
		fprintf(stderr,"forker program(chmod+x) validator args...\n");
		return 0;
	}
	const char *cmd=argv[2];

	//Initialize
	int fd_in[2],fd_out[2];
	pipe(fd_in);
	pipe(fd_out);

	int pid1=fork();
	if(pid1==-1){
		printf("InternalError\n");
		return 0;
	}
	if(pid1==0){//validator
		close(1);
		dup2(fd_in[1],1);
		close(0);
		dup2(fd_out[0],0);
		close(fd_in[0]);
		close(fd_in[1]);
		close(fd_out[0]);
		close(fd_out[1]);
		char **args=(char**)malloc(sizeof(char*)*argc);
		for(int i=2;i<argc;i++)args[i-2]=argv[i];
		args[argc-2]=NULL;
		execvp(cmd,args); //execvp is required; cmd might be interpreter name
		free(args);
		return 0;
	}
	int pid2=fork();
	if(pid2==-1){
		printf("InternalError\n");
		return 0;
	}
	if(pid2==0){//program
		close(0);
		dup2(fd_in[0],0);
		close(1);
		dup2(fd_out[1],1);
		close(fd_in[0]);
		close(fd_in[1]);
		close(fd_out[0]);
		close(fd_out[1]);
		char **args=(char**)malloc(sizeof(char*)*2);
		args[0]=argv[1];
		args[1]=NULL;
		execvp(argv[1],args); //argv[1] must be chmod +x
		free(args);
		return 0;
	}
	close(fd_in[0]);
	close(fd_in[1]);
	close(fd_out[0]);
	close(fd_out[1]);
	
	int st1,st2;
	waitpid(pid1,&st1,WUNTRACED);
	waitpid(pid2,&st2,WUNTRACED);
	//status=0 == AC
	if(WIFEXITED(st1))printf("status=%d\n",WEXITSTATUS(st1));
	else printf("status=255\n");
}
