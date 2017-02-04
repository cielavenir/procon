#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include "streambuf_fromfile.h"
using namespace std;

const char *cmd;
istream *ppin;
ostream *ppout;
int testcase=0;

void test(const string &input, const string &expect){
	istream &pin=*ppin;
	ostream &pout=*ppout;
	string answer;
	pout<<input<<endl<<flush;
	getline(pin,answer);
	cout<<"Case "<<testcase++<<": "<<(answer==expect?"OK":"NG")<<endl;
}

int main(int argc, char **argv){
	cin.tie(0);
	ios::sync_with_stdio(false);
	if(argc<2){
		cerr<<"validator program/interpreter..."<<endl;
		return 0;
	}
	cmd=argv[1];

	//Initialize
	int fd_in[2],fd_out[2];
	pipe(fd_in);
	pipe(fd_out);

	int pid=fork();
	if(pid==-1){
		cout<<"InternalError"<<endl;
		return 0;
	}
	if(pid==0){//child
		close(0);
		dup2(fd_in[0],0);
		close(1);
		dup2(fd_out[1],1);
		close(fd_in[0]);
		close(fd_in[1]);
		close(fd_out[0]);
		close(fd_out[1]);
		char **args=(char**)malloc(sizeof(char*)*argc);
		for(int i=1;i<argc;i++)args[i-1]=argv[i];
		args[argc-1]=NULL;
		execvp(cmd,args); //execvp is required; cmd might be interpreter name
		free(args);
		return 0;
	}
	//parent
	close(fd_in[0]);
	close(fd_out[1]);
	FILE *fin=fdopen(fd_out[0],"r");
	streambuf_fromfile_in bin(fin);
	ppin=new istream(&bin);

	FILE *fout=fdopen(fd_in[1],"w");
	streambuf_fromfile_out bout(fout);
	ppout=new ostream(&bout);

	void testloader();
	testloader();

	delete ppin;
	delete ppout;
	fclose(fin);
	fclose(fout);
}
