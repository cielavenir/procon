#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>
//#define _GNU_SOURCE
//#include <fcntl.h>
int main(){
//	int siz=4096;
//	fcntl(fileno(stdout),F_SETPIPE_SZ,&siz);
	signal( SIGPIPE , SIG_IGN );
	int i=0;        
	for(;;){
		if((printf("%d\n",++i)<0||fflush(stdout)<0) && errno==EPIPE)return 0;
		usleep(1000);
	}
}