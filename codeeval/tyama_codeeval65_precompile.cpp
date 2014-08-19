#include <set>
#include <string>
using namespace std;
set<string> h;
int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
int M[3][4];
char s[19],*m[]={"ABCE","SFCS","ADEE"};
void D(int x,int y,int d){
	int i=0;
	s[d]=m[y][x];
	//printf("%s\n",s);
	h.insert(s);
	for(;i<4;i++)if(0<=x+dx[i]&&x+dx[i]<4 && 0<=y+dy[i]&&y+dy[i]<3){
		if(!M[y+dy[i]][x+dx[i]]){
			M[y+dy[i]][x+dx[i]]=1;
			D(x+dx[i],y+dy[i],d+1);
			M[y+dy[i]][x+dx[i]]=0;
		}
	}
	s[d]=0;
}
main(){
	int i,j;
	for(j=0;j<3;j++)for(i=0;i<4;i++){
		M[j][i]=1;
		D(i,j,0);
		M[j][i]=0;
	}
	puts("#include <set>");
	puts("#include <string>");
	puts("#include <iostream>");
	puts("using namespace std;");
	puts("main(){set<string> s;string t;");
	set<string>::iterator it=h.begin();
	for(;it!=h.end();it++){
		printf("s.insert(\"%s\");",it->c_str());
	}
	puts("for(;cin>>t;)cout<<(s.find(t)!=s.end()?\"True\":\"False\")<<endl;}");
}