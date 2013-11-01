#include <iostream>
#include <ext/stdio_filebuf.h>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const char *cmd;
istream *ppin;
ostream *ppout;
int testcase=0;

void test(string input, string expect){
	istream &pin=*ppin;
	ostream &pout=*ppout;
	string answer;
	pout<<input<<endl<<flush;
	getline(pin,answer);
	cout<<"Case "<<testcase++<<": "<<(answer==expect?"OK":"NG")<<endl;
}

int main(int argc, char **argv){
	if(argc<2){
		cerr<<"validator [program]"<<endl;
		cerr<<"program must be chmod +x"<<endl;
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
		execl(cmd,cmd,NULL);
		return 0;
	}
	//parent
	close(fd_in[0]);
	close(fd_out[1]);
	FILE *fin=fdopen(fd_out[0],"r");
	__gnu_cxx::stdio_filebuf<char> bin(fin, ios_base::in);
	ppin=new istream(&bin);

	FILE *fout=fdopen(fd_in[1],"w");
	__gnu_cxx::stdio_filebuf<char> bout(fout, ios_base::out);
	ppout=new ostream(&bout);

	void testloader();
	testloader();

	delete ppin;
	delete ppout;
	fclose(fin);
	fclose(fout);
}