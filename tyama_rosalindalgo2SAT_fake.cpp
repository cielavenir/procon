// http://codegolf.stackexchange.com/questions/1933/solve-2-sat-boolean-satisfiability
// ghc mtnviewmark.hs
// ./a.out mtnviewmark < rosalind_2sat.txt > rosalind_2sat.ans # bah...

#include <sstream>
#include <iostream>
#include <ext/stdio_filebuf.h>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

//Reactive
int main(int argc, char **argv){
	if(argc<2){
		cerr<<"validator [program]"<<endl;
		cerr<<"program must be chmod +x"<<endl;
		return 0;
	}
	const char *cmd=argv[1];

int K,V,E,s,t;
string st;
for(cin>>K;K;--K){
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
	istream pin(&bin);

{
	FILE *fout=fdopen(fd_in[1],"w");
	__gnu_cxx::stdio_filebuf<char> bout(fout, ios_base::out);
	ostream pout(&bout);
	cin>>V>>E;
	pout<<V<<' '<<E<<endl;
	for(;E--;){
		cin>>s>>t;
		pout<<s<<' '<<t<<endl;
	}
	fclose(fout);
}

	getline(pin,st);
	fclose(fin);
	if(st=="UNSOLVABLE")cout<<0<<endl;
	else{
		cout<<1;
		istringstream ss(st);
		for(s=1;s<=V;s++)ss>>t,cout<<' '<<s*(t*2-1);
		cout<<endl;
	}
}
	return 0;
}