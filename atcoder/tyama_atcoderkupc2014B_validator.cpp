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

#define lrotl(val,rot) (( (val)<<(rot) )|( (val)>>(sizeof(val)*CHAR_BIT-(rot)) ))
static unsigned int x = 123456789;
static unsigned int y = 362436069;
static unsigned int z = 521288629;
static unsigned int w = 88675123;

unsigned int xor_rand(){
	unsigned int t;
	t=x^(x<<11);
	x=y;y=z;z=w;
	return w=(w^(w>>19)) ^ (t^(t>>8));
}

// http://d.hatena.ne.jp/gintenlabo/20100930/1285859540
void xor_srand(unsigned int seed){
#if 1
	x^=seed;
	y^=lrotl(seed,17);
	z^=lrotl(seed,31);
	w^=lrotl(seed,18);
#else
	x^=lrotl(seed,14);
	y^=lrotl(seed,31);
	z^=lrotl(seed,13);
	w^=seed;
#endif
}

static unsigned int _random(unsigned int max){return xor_rand()%max;}

#define MAX 1000
int _main(ostream &pout,istream &pin){ //actual validator
	xor_srand((unsigned int)time(NULL)^(getpid()<<16));
	string TAG="[Validator] ";

	int answer=_random(MAX)+1;
	int num,test;
	string op;
	cerr<<TAG<<"answer = "<<answer<<endl<<flush;
	for(test=0;;){
		test++;
		if(test>1000){
			cerr<<TAG<<"Verdict:"<<endl<<flush;
			cout<<"QueryLimitExceeded"<<endl;
			return 0;
		}
		pin>>op;
		if(op=="?"){
			cerr<<TAG<<"<Test>"<<flush;
			pin>>num;
			if(num<1||MAX<num){
				cerr<<TAG<<"Verdict:"<<endl<<flush;
				cout<<"RuntimeError"<<endl;
				return 0;
			}
			cerr<<' '<<num<<" ("<<(answer%num?"N":"Y")<<")"<<endl<<flush;
			pout<<(answer%num?"N":"Y")<<endl<<flush;
		}else if(op=="!"){
			cerr<<TAG<<"<Challenge> "<<flush;
			pin>>num;
			cerr<<num<<endl<<flush;
			if(num<1||MAX<num){
				cerr<<TAG<<"Verdict:"<<endl<<flush;
				cout<<"RuntimeError"<<endl;
				return 0;
			}
			if(answer!=num){
				cerr<<TAG<<"Verdict:"<<endl<<flush;
				cout<<"WrongAnswer"<<endl;
				return 0;
			}
			cerr<<TAG<<"Verdict:"<<endl<<flush;
			cout<<(test<=200?"AC (Level2)":"AC (Level1)")<<endl;
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