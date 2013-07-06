#include <sstream>
#include <iostream>
#include <iomanip>
#include <ext/stdio_filebuf.h>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <ctime>
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

int _main(ostream &pout,istream &pin){ //actual validator
	xor_srand((unsigned int)time(NULL)^(getpid()<<16));
	string TAG="[Validator] ";

	string line;
	int x,M,i,s,g,p,q;
	vector<int>dice,N;
	cin>>M;pout<<M<<endl;
	for(i=0;i<6;i++){
		if(i>0)pout<<' ';
		cin>>x,dice.push_back(x);
		pout<<x;
	}
	pout<<endl;
	cin>>s>>g;pout<<s<<' '<<g<<endl;s--,g--;
	for(i=0;i<M;i++){
		if(i>0)pout<<' ';
		cin>>x,N.push_back(x);
		pout<<x;
	}
	pout<<endl;
	pout<<flush;

	int test,action;

	//cerr<<TAG<<"Listening."<<endl<<flush;
	for(test=0;test<3000;test++){
		int rnd=xor_rand()%6;
		pout<<(rnd+1)<<endl<<flush;
		pin>>action;
		cerr<<TAG<<"dice="<<(rnd+1)<<" action="<<action<<endl<<flush;
		if(action==-1){
			s-=dice[rnd];
			if(s<0||M<=s)goto wa;
			s+=N[s];
		}else if(action==1){
			s+=dice[rnd];
			if(s<0||M<=s)goto wa;
			s+=N[s];
		}else if(action)goto wa;
		cerr<<TAG<<"new coor="<<(s+1)<<endl<<flush;
		if(s==g)break;
	}
	if(test<3000){
		cerr<<TAG<<"Verdict:"<<endl<<flush;
		cout<<"Accepted"<<endl;
	}else{
		cerr<<TAG<<"Verdict:"<<endl<<flush;
		cout<<"QueryLimitExceeded"<<endl;
	}
	return 0;
wa:
	cerr<<TAG<<"Verdict:"<<endl<<flush;
	cout<<"WrongAnswer"<<endl;
	return 0;
}

//Reactive
int main(int argc, char **argv){
	if(argc<2){
		cerr<<"<input.txt validator [program]"<<endl;
		cerr<<"program must be chmod +x"<<endl;
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
		execl(cmd,cmd,NULL);
		return 0;
	}
	//parent
	close(fd_in[0]);
	close(fd_out[1]);
	FILE *fout=fdopen(fd_in[1],"w");
	FILE *fin=fdopen(fd_out[0],"r");
	__gnu_cxx::stdio_filebuf<char> bout(fout, ios_base::out);
	__gnu_cxx::stdio_filebuf<char> bin(fin, ios_base::in);
	ostream pout(&bout);
	istream pin(&bin);
	_main(pout,pin);
	fclose(fout);
	fclose(fin);
	return 0;
}