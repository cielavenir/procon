#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include "streambuf_fromfile.h"
using namespace std;

map<long long,string>memo;
string dfs(int n,int k){
	if(n==1&&k==0)return "b";
	if(n==2&&k==0)return "a";
	long long x=((long long)n)<<32|k;
	map<long long,string>::iterator it=memo.find(x);
	if(it!=memo.end())return it->second;
	if(k&1)return memo[x]=dfs(n-2,k/4)+dfs(n-1,k/2);
	return memo[x]=dfs(n-1,k/2)+dfs(n-2,k/4);
}

int _main(ostream &pout,istream &pin){ //actual validator
	string TAG="[Validator] ";
	string input;
	getline(cin,input);
	pout<<input<<endl<<flush;
	int n,k;
	pin>>n>>k;

	cerr<<TAG<<"Verdict: ";
	if(dfs(n,k)==input){
		cout<<"Accepted"<<endl;
	}else{
		cout<<"WrongAnswer"<<endl;
	}
	return 0;
}

//Reactive
int main(int argc, char **argv){
	cin.tie(0);
	ios::sync_with_stdio(false);
	if(argc<2){
		cerr<<"validator program/interpreter..."<<endl;
		return 0;
	}
	const char *cmd=argv[1];

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
	FILE *fout=fdopen(fd_in[1],"w");
	FILE *fin=fdopen(fd_out[0],"r");
	streambuf_fromfile_out bout(fout);
	streambuf_fromfile_in bin(fin);
	ostream pout(&bout);
	istream pin(&bin);
	_main(pout,pin);
	fclose(fout);
	fclose(fin);
	return 0;
}