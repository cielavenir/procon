//nuko admitted there is specification bug that it doesn't have "swap".
//#define EXTENDED

#define PUSHINT0  "00.-"
#define PUSHINT1  "01.-"
#define PUSHINT2  "02.-"
//#define PUSHINT1000  "ak.-d.!"
#define PUSHINTL  "zz.!"
//#define PUTSPACE  "0P.-.o"
//#define PUTCOLON  "0j.-.o"
#define PUTLF     "ak.-.o"
#define INCREMENT PUSHINT1".+"
#define DECREMENT PUSHINT1".-"
#define PXEM      ".pxem"

//after using these subroutines, temporary area will be overwritten.
#define ROTATEL   ".t.v.m.v"
#define ROTATER   ".v.t.v.m"
#define PEEKT     ".c.t"
#define PEEKB     ".v.c.t.v"
//#define POPB      ".v.t.v"

#ifdef EXTENDED
//._.c.w.c.v00.-zz.!00.-.v.c.w._.c.t.v.c.m.h.x.s.m00.a.m.h.t.v.m.v.t.c.m.h.y.s.m00.a.m.h.t.v.m.v.+.v.t.v.m.v.t.v.m.v.s01.-.-.c.a.s02.-.-.t.-.-.m.$.nak.-.o._.c.a.s.pxem
char *FILENAME=
"._.c.w" //n while n
	".c" //i,n
	".v" //n,i
	PUSHINT0 PUSHINTL PUSHINT0 //max,min,sum,n,i
	".v.c.w"       //i,n,sum,min,max while i
		"._" PEEKT //x,i,n,sum,min,max t==x
		".v"       //max,min,sum,n,i,x t==x
		".c.m.h"

		//max,x,max,min,sum,n,i,x t==x
		".x"       // while max < x
		".s.m"
		"00.a"
		//max,min,sum,n,i,x t==x
		".m.h"     //max,x,min,sum,n,i,x
		ROTATEL    //x,min,sum,n,i,x,max
		".t.c.m.h"

		//min,x,min,sum,n,i,x,max t==x
		".y"       // while min > x
		".s.m"
		"00.a"

		//min,sum,n,i,x,max t==x
		".m.h"     //min,x,sum,n,i,x,max
		ROTATEL    //x,sum,n,i,x,max,min
		".+"       //sum,n,i,x,max,min
		ROTATER ROTATER ".v.s" //i,n,sum,min,max
	DECREMENT".c.a"

	".s" PUSHINT2 ".-.t" //sum,min,max t==n-2
	".-.-.m.$.n"PUTLF
"._.c.a.s"PXEM;
char *CONTENT="";
#else
//._.c.w.c.v00.-zz.!00.-.v.c.w._.c.t.v.t.v.m.v.e.t.v.m.v.e.v.t.v.m.v.t.v.m.v.c.t.v.x.s.m00.a.t.v.m.v.e.t.v.m.v.t.v.m.v.e.t.v.m.v.e.v.t.v.m.v.t.v.m.v.c.t.v.y.s.m00.a.t.v.m.v.e.+.v.t.v.m.v.t.v.m.s.v.t.v.m.v.s01.-.-.c.a.s02.-.-.t.-.-.m.$.nak.-.o._.c.a.s.pxem
char *FILENAME=
"._.c.w" //n while n
	".c" //i,n
	".v" //n,i
	PUSHINT0 PUSHINTL PUSHINT0 //max,min,sum,n,i
	".v.c.w"       //i,n,sum,min,max while i
		"._" PEEKT //x,i,n,sum,min,max t==x
		".v"       //max,min,sum,n,i,x t==x
		ROTATEL    //min,sum,n,i,x,max
		".e"       //x,min,sum,n,i,x,max
		ROTATEL    //min,sum,n,i,x,max,x
		".e"       //max,min,sum,n,i,x,max,x
		ROTATER ROTATER PEEKB

		//max,x,max,min,sum,n,i,x t==x
		".x"       // while max < x
		".s.m"     // max<-t(==x)
		"00.a"     // break
		//max,min,sum,n,i,x t==x
		ROTATEL    //min,sum,n,i,x,max
		".e"       //x,min,sum,n,i,x,max
		ROTATEL ROTATEL //sum,n,i,x,max,x,min
		".e"       //x,sum,n,i,x,max,x,min
		ROTATEL    //sum,n,i,x,max,x,min,x
		".e"       //min,sum,n,i,x,max,x,min,x
		ROTATER ROTATER PEEKB

		//min,x,min,sum,n,i,x,max,x t==x
		".y"       // while min > x
		".s.m"     // min<-t(==x)
		"00.a"     // break

		//min,sum,n,i,x,max,x t==x
		ROTATEL    //sum,n,i,x,max,x,min
		".e"       //x,sum,n,i,x,max,x,min
		".+"       //sum,n,i,x,max,x,min
		ROTATER ROTATER ".s" ROTATER ".v.s" //i,n,sum,min,max
	DECREMENT".c.a"

	".s" PUSHINT2 ".-.t" //sum,min,max t==n-2
	".-.-.m.$.n"PUTLF
"._.c.a.s"PXEM;
char *CONTENT=".v.s.t.s.s.s.s.s.s.m"; //return second-last element
#endif

// http://cfs.maxn.jp/neta/pxem.php
#include <cstdio>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;
class Pxem{
	private:
		stack<int>	pStack;		// stack
		char		*fName;		// file name
		char		*fCont;		// file contents
		int		temp;		// temporary area
		bool		used;		// used temp?
		void	print();		// print stack
		bool	out();			// output
		void	numOut();		// output(number)
		void	input();		// input
		void	numInput();		// number input
		void	copy();			// x,y,z -> x,x,y,z
		void	throwAway();		// x,y,z -> y,z
		void	inverse();		// x,y,z -> z,y,x
		void	fileRead();		// input from file contents
		void	emu();			// run pxem using file contents
		void	getRand();		// create random number from stack[0]
		void	toTemp();		// temp = stack[0];
		void	fromTemp();		// if(used) stack.push(temp);
		void	addition();		// x,y,z -> (x+y),z
		void	subtraction();		// x,y,z -> abs(x-y),z
		void	multiplication();	// x,y,z -> (x*y),z
		void	getQuotient();		// x,y,z -> (x>y?int(x/y):int(y/x)),z
		void	getSurplus();		// x,y,z -> (x>y?int(x%y):int(y%x)),z
		void	addStr(char*);		// addStr("ab"); -> pStack.push(98);pStack.push(97);

		void	getXor();	// x,y,z -> x^y,z
		void	excHange();		// x,y,z -> y,x,z
	public:
		Pxem(char*,char*);			// constructor from main()
		Pxem(char*,char*,stack<int>);		// constructor from Pxem
		void	run();				// run pxem
		stack<int>	getStack() const;	// get stack
};
Pxem::Pxem(char *f, char *g):fName(f),fCont(g){srand((unsigned)time(NULL));}
Pxem::Pxem(char *f, char *g,stack<int> hoge):fName(f),fCont(g){
	srand((unsigned)time(NULL));
	stack<int>fuga;
	while(!hoge.empty()){
		fuga.push((int)hoge.top());
		hoge.pop();
	}
	while(!fuga.empty()){
		pStack.push(fuga.top());
		hoge.push(fuga.top());
		fuga.pop();
	}
}
void Pxem::run(){
	long ps		= 0;
	long slen	= strlen(fName);
	string buf;
	while(ps<slen){
		if(fName[ps]=='.'&&ps+1<slen){
			int cnt;
			int ccp;
			switch(fName[++ps]){
				case 'p':
				case 'P':
					// print stack
					addStr((char*)buf.c_str());
					buf = "";
					print();
					break;
				case 'o':
				case 'O':
					// output
					addStr((char*)buf.c_str());
					buf = "";
					out();
					break;
				case 'n':
				case 'N':
					// output(number)
					addStr((char*)buf.c_str());
					buf = "";
					numOut();
					break;
				case 'i':
				case 'I':
					// input
					addStr((char*)buf.c_str());
					buf = "";
					input();
					break;
				case '_':
					// input(number)
					addStr((char*)buf.c_str());
					buf = "";
					numInput();
					break;
				case 'c':
				case 'C':
					// x,y,z -> x,x,y,z
					addStr((char*)buf.c_str());
					buf = "";
					copy();
					break;
				case 's':
				case 'S':
					// x,y,z -> x,y
					addStr((char*)buf.c_str());
					buf = "";
					throwAway();
					break;
				case 'v':
				case 'V':
					// x,y,z -> z,y,x
					addStr((char*)buf.c_str());
					buf = "";
					inverse();
					break;
				case 'f':
				case 'F':
					// input from file contents
					addStr((char*)buf.c_str());
					buf = "";
					fileRead();
					break;
				case 'e':
				case 'E':
					// run pxem using file contents
					addStr((char*)buf.c_str());
					buf = "";
					emu();
					break;
				case 'r':
				case 'R':
					// create random number from stack[0]
					addStr((char*)buf.c_str());
					buf = "";
					getRand();
					break;
				case 'w':
				case 'W':
					addStr((char*)buf.c_str());
					buf="";
					if(!pStack.empty()){
						cnt=pStack.top();
						pStack.pop();
						if(cnt==0){
							ps++;
							cnt=1;
							while(cnt){
								if(fName[ps]=='.'){
									switch(fName[++ps]){
										case 'w':
										case 'W':
										case 'x':
										case 'X':
										case 'y':
										case 'Y':
										case 'z':
										case 'Z':
											cnt++;
											break;
										case 'a':
										case 'A':
											cnt--;
											break;
									}
								}
								ps++;
							}
							ps--;
						}
					}
					break;
				case 'x':
				case 'X':
					addStr((char*)buf.c_str());
					buf="";
					if(pStack.size()>1){
						cnt=pStack.top();
						pStack.pop();
						ccp=pStack.top();
						pStack.pop();
						if(cnt>=ccp){
							ps++;
							cnt=1;
							while(cnt){
								if(fName[ps]=='.'){
									switch(fName[++ps]){
										case 'w':
										case 'W':
										case 'x':
										case 'X':
										case 'y':
										case 'Y':
										case 'z':
										case 'Z':
											cnt++;
											break;
										case 'a':
										case 'A':
											cnt--;
											break;
									}
								}
								ps++;
							}
							ps--;
						}
					}
					break;
				case 'y':
				case 'Y':
					addStr((char*)buf.c_str());
					buf="";
					if(pStack.size()>1){
						cnt=pStack.top();
						pStack.pop();
						ccp=pStack.top();
						pStack.pop();
						if(cnt<=ccp){
							ps++;
							cnt=1;
							while(cnt){
								if(fName[ps]=='.'){
									switch(fName[++ps]){
										case 'w':
										case 'W':
										case 'x':
										case 'X':
										case 'y':
										case 'Y':
										case 'z':
										case 'Z':
											cnt++;
											break;
										case 'a':
										case 'A':
											cnt--;
											break;
									}
								}
								ps++;
							}
							ps--;
						}
					}
					break;
				case 'z':
				case 'Z':
					addStr((char*)buf.c_str());
					buf="";
					if(pStack.size()>1){
						cnt=pStack.top();
						pStack.pop();
						ccp=pStack.top();
						pStack.pop();
						if(cnt==ccp){
							ps++;
							cnt=1;
							while(cnt){
								if(fName[ps]=='.'){
									switch(fName[++ps]){
										case 'w':
										case 'W':
										case 'x':
										case 'X':
										case 'y':
										case 'Y':
										case 'z':
										case 'Z':
											cnt++;
											break;
										case 'a':
										case 'A':
											cnt--;
											break;
									}
								}
								ps++;
							}
							ps--;
						}
					}
					break;
				case 'a':
				case 'A':
					addStr((char*)buf.c_str());
					buf="";
					ps-=2;
					cnt=-1;
					while(cnt){
						if(fName[ps]=='.'){
							switch(fName[ps+1]){
								case 'w':
								case 'W':
								case 'x':
								case 'X':
								case 'y':
								case 'Y':
								case 'z':
								case 'Z':
									cnt++;
									break;
								case 'a':
								case 'A':
									cnt--;
									break;
							}
						}
						ps--;
					}
					break;
				case 't':
				case 'T':
					addStr((char*)buf.c_str());
					buf = "";
					toTemp();
					break;
				case 'm':
				case 'M':
					addStr((char*)buf.c_str());
					buf = "";
					fromTemp();
					break;
				case 'd':
				case 'D':
					addStr((char*)buf.c_str());
					buf = "";
					return;
				case '+':
					addStr((char*)buf.c_str());
					buf = "";
					addition();
					break;
				case '-':
					addStr((char*)buf.c_str());
					buf = "";
					subtraction();
					break;
				case '!':
					addStr((char*)buf.c_str());
					buf = "";
					multiplication();
					break;
				case '$':
					addStr((char*)buf.c_str());
					buf = "";
					getQuotient();
					break;
				case '%':
					addStr((char*)buf.c_str());
					buf = "";
					getSurplus();
					break;
#ifdef EXTENDED
				case '^':
					addStr((char*)buf.c_str());
					buf = "";
					getXor();
					break;
				case 'h':
				case 'H':
					addStr((char*)buf.c_str());
					buf = "";
					excHange();
					break;
#endif
				default:
					buf += fName[--ps];
			}
		}else
			buf += fName[ps];
		ps++;
	}
	if(strlen((char*)buf.c_str())>0)addStr((char*)buf.c_str());
}
inline stack<int> Pxem::getStack() const{	return pStack;}
inline void Pxem::print(){while(out());}
inline bool Pxem::out(){
	if(pStack.empty())return false;
	int aaa=pStack.top();
	putchar(aaa);
	pStack.pop();
	return true;
}
inline void Pxem::numOut(){
	if(pStack.empty())return;
	int aaa=pStack.top();
	printf("%d",aaa);
	pStack.pop();
}
inline void Pxem::input(){
	int aaa=getchar();
	pStack.push(aaa);
}
inline void Pxem::numInput(){
	int aaa;
	scanf("%d",&aaa);
	pStack.push(aaa);
}
inline void Pxem::copy(){
	int i=pStack.top();
	pStack.push(i);
}
inline void Pxem::throwAway(){if(!pStack.empty())pStack.pop();}
void Pxem::inverse(){
	queue<int>fuga;
	while(!pStack.empty()){
		fuga.push((int)pStack.top());
		pStack.pop();
	}
	while(!fuga.empty()){
		pStack.push(fuga.front());
		fuga.pop();
	}
}
inline void Pxem::fileRead(){addStr(fCont);}
void Pxem::emu(){
	Pxem newPxem(fCont,fCont,pStack);
	newPxem.run();
	stack<int>aaa=newPxem.getStack();
	stack<int>bbb;
	while(!aaa.empty()){
		bbb.push((int)aaa.top());
		aaa.pop();
	}
	while(!bbb.empty()){
		pStack.push(bbb.top());
		bbb.pop();
	}
}
inline void Pxem::getRand(){
	int aaa=rand()%pStack.top();
	pStack.pop();
	pStack.push(aaa);
}
inline void Pxem::toTemp(){
	if(pStack.empty())return;
	temp=pStack.top();
	pStack.pop();
	used=true;
}
inline void Pxem::fromTemp(){
	if(used)pStack.push(temp);
}
void Pxem::addition(){
	if(pStack.size()<2)return;
	int aa=pStack.top();
	pStack.pop();
	int bb=pStack.top();
	pStack.pop();
	pStack.push(aa+bb);
}
void Pxem::subtraction(){
	if(pStack.size()<2)return;
	int aa=pStack.top();
	pStack.pop();
	int bb=pStack.top();
	pStack.pop();
	pStack.push(abs(aa-bb));
}
void Pxem::multiplication(){
	if(pStack.size()<2)return;
	int aa=pStack.top();
	pStack.pop();
	int bb=pStack.top();
	pStack.pop();
	pStack.push(aa*bb);
}
void Pxem::getQuotient(){
	if(pStack.size()<2)return;
	int aa=pStack.top();
	pStack.pop();
	int bb=pStack.top();
	pStack.pop();
	pStack.push(aa>bb?aa/bb:bb/aa);
}
void Pxem::getSurplus(){
	if(pStack.size()<2)return;
	int aa=pStack.top();
	pStack.pop();
	int bb=pStack.top();
	pStack.pop();
	pStack.push(aa>bb?aa%bb:bb%aa);
}
void Pxem::getXor(){
	if(pStack.size()<2)return;
	int aa=pStack.top();
	pStack.pop();
	int bb=pStack.top();
	pStack.pop();
	pStack.push(aa^bb);
}
void Pxem::excHange(){
	if(pStack.size()<2)return;
	int aa=pStack.top();
	pStack.pop();
	int bb=pStack.top();
	pStack.pop();
	pStack.push(aa);
	pStack.push(bb);
}
void Pxem::addStr(char* str){
	int leng=strlen(str);
	while(leng--)pStack.push((int)str[leng]);
}
int main(){
	//puts(FILENAME),puts(CONTENT);
	Pxem(FILENAME,CONTENT).run();
}