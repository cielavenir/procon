#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <unistd.h>
#include "streambuf_fromfile.h"
using namespace std;

int _main(ostream &pout,istream &pin){ //actual validator
	int N,x11,y11,x12,y12,x21,y21,x22,y22;
	cin>>N>>x11>>y11>>x12>>y12>>x21>>y21>>x22>>y22;
	pout<<N<<endl<<flush;
	string TAG="[Validator] ";

	int num,test;
	string op;
	for(test=0;;){
		test++;
		if(test>200){
			cerr<<TAG<<"Verdict:"<<endl<<flush;
			cout<<"QueryLimitExceeded"<<endl;
			return 0;
		}
		pin>>op;
		if(op=="?"){
			cerr<<TAG<<"<Test> "<<flush;
			int X11,Y11,X12,Y12,n=0;
			pin>>X11>>Y11>>X12>>Y12;
			cerr<<X11<<' '<<Y11<<' '<<X12<<' '<<Y12<<flush;
			if(X11>X12 || Y11>Y12){
				cerr<<TAG<<"Verdict:"<<endl<<flush;
				cout<<"WrongAnswer (invalid range)"<<endl;
				return 0;
			}
			if(X11<=x11&&x11<=X12 && X11<=x12&&x12<=X12 && Y11<=y11&&y11<=Y12 && Y11<=y12&&y12<=Y12)n++;
			if(X11<=x21&&x21<=X12 && X11<=x22&&x22<=X12 && Y11<=y21&&y21<=Y12 && Y11<=y22&&y22<=Y12)n++;
			cerr<<':'<<n<<endl<<flush;
			pout<<n<<endl<<flush;
		}else if(op=="!"){
			cerr<<TAG<<"<Challenge> "<<flush;
			int X11,Y11,X12,Y12,X21,Y21,X22,Y22;
			pin>>X11>>Y11>>X12>>Y12>>X21>>Y21>>X22>>Y22;
			cerr<<X11<<' '<<Y11<<' '<<X12<<' '<<Y12<<','<<X21<<' '<<Y21<<' '<<X22<<' '<<Y22<<endl<<flush;
			if(
				(X11==x11&&Y11==y11&&X12==x12&&Y12==y12&&X21==x21&&Y21==y21&&X22==x22&&Y22==y22) ||
				(X11==x21&&Y11==y21&&X12==x22&&Y12==y22&&X21==x11&&Y21==y11&&X22==x12&&Y22==y12)
			){
				cerr<<TAG<<"Verdict:"<<endl<<flush;
				cout<<"Accepted"<<endl;
				return 0;
			}
			cerr<<TAG<<"Verdict:"<<endl<<flush;
			cout<<"WrongAnswer"<<endl;
			return 0;
		}else{
			cerr<<TAG<<"Verdict:"<<endl<<flush;
			cout<<"RuntimeError"<<endl;
			return 0;
		}
	}
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
