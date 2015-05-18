#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
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

int main(){
	xor_srand((unsigned int)time(NULL)^(getpid()<<16));
	string TAG="[Validator] ";
	ostringstream oanswer;
	oanswer<<setw(9)<<setfill('0')<<xor_rand()%1000000000;
	string answer=oanswer.str(),op,tmp;
	cerr<<TAG<<"Answer: "<<answer<<endl<<flush;

	set<string>s;
	int test=0;

	//cerr<<TAG<<"Listening."<<endl<<flush;
	for(;;test++){
		cin>>op;
		if(op=="?"){
			cerr<<TAG<<"<Test>"<<flush;
			if(test==21){
				cerr<<TAG<<"Verdict:"<<endl<<flush;
				cerr<<"QueryLimitExceeded"<<endl;
				return 1;
			}
			vector<string> arg;
			vector<pair<int,int> >hit_blow;
			int i,j,k;
			for(i=0;i<9;i++){
				cin>>tmp;
				cerr<<" "<<tmp<<flush;
				if(tmp.length()!=9||find(s.begin(),s.end(),tmp)!=s.end()){
					cerr<<endl<<TAG<<"Verdict:"<<endl<<flush;
					cerr<<"RuntimeError"<<endl;
					return -1;
				}
				arg.push_back(tmp);
				s.insert(tmp);
			}
			cerr<<endl<<flush;
			for(i=0;i<9;i++){
				int hit=0,blow=0;
				for(j=0;j<9;j++)
					if(answer[j]==arg[i][j])hit++;
				for(j='0';j<='9';j++){ //modifiable
					int c1=0,c2=0;
					for(k=0;k<9;k++){
						if(answer[k]==j)c1++;
						if(arg[i][k]==j)c2++;
					}
					blow+=min(c1,c2);
				}
				hit_blow.push_back(make_pair(hit,blow-hit));
			}
			random_shuffle(hit_blow.begin(),hit_blow.end(),_random);
			ostringstream x;
			for(i=0;i<9;i++){
				if(i)x<<' ';
				x<<hit_blow[i].first;
				x<<' ';
				x<<hit_blow[i].second;
			}
			cerr<<TAG<<"Result: "<<x.str()<<endl<<flush;
			cout<<x.str()<<endl<<flush;
		}else if(op=="!"){
			cerr<<TAG<<"<Challenge> "<<flush;
			cin>>tmp;
			cerr<<tmp<<endl<<flush;
			cerr<<TAG<<"Verdict:"<<endl<<flush;
			if(answer!=tmp){
				cerr<<"WrongAnswer"<<endl;
				return 2;
			}else if(10<=test){
				cerr<<"Accepted100"<<endl;
			}else{
				cerr<<"Accepted150"<<endl;
			}
			return 0;
		}else{
			cerr<<TAG<<"Verdict:"<<endl<<flush;
			cerr<<"RuntimeError"<<endl;
			return -1;
		}
	}
	return -2;
}