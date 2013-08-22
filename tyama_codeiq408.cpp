#include <iostream>
#include <string>
#include <vector>
//#include <unordered_map>
#include <map>
#include <algorithm>
#include <cstdlib>
using namespace std;
map<string,vector<string> >m;
vector<string> lst_max;
int i_max=0;
void dfs(vector<string>&lst,map<string,int> &visit,string &cur) throw(int){
	vector<string>&v=m[cur];
	int i=0,j;
	//for(;i<v.size();i++){
	for(i=v.size()-1;i>=0;i--){
		if(!visit[v[i]]){
			lst.push_back(v[i]);
			visit[v[i]]=visit[cur]+1;
			dfs(lst,visit,v[i]);
			visit[v[i]]=0;
			lst.pop_back();
		}
	}
	if(lst.size()>i_max){
		//cout<<lst.size()<<endl;
		i_max=lst.size(),lst_max=lst;
	}
	if(i_max==34)throw 0; //fixme...
}
int main(int argc, char **argv){
	int i,j;
	vector<string>v;
	string s;
	for(;getline(cin,s);){
		if(s[s.size()-1]=='\r')s=s.substr(0,s.size()-1);
		v.push_back(s);
	}
	for(i=0;i<v.size();i++)for(j=0;j<v.size();j++){
		if(v[i][v[i].size()-1]==v[j][0]){
			//m[v[i]].push_back(v[j]);
			m[v[j]].push_back(v[i]);
		}
	}
	//i=strtol(argv[1],NULL,10);
	i=81; //fixme...
	//for(i=0;i<v.size();i++)
	try{
		//cout<<"*** "<<i<<endl;
		vector<string>lst;
		lst.push_back(v[i]);
		map<string,int>visit;
		visit[v[i]]=1;
		dfs(lst,visit,v[i]);
	}catch(int){}
	reverse(lst_max.begin(),lst_max.end());
	//cout<<lst_max.size()<<endl;
	for(i=0;i<lst_max.size();i++)cout<<lst_max[i]<<endl;
}
/*
C++を使用した。( http://ideone.com/2kv10M )
CPU時間を15秒にして全探索を行ったところ、else/mutable/template/true/try/typename/whileを始点にした逆方向探索において34個のしりとりを検出することができた。
※閉路がなければ重みを負にしてベルマンフォードを使うべきですが、今回は閉路があるのでなんとも。

alignas
static
class
sizeof
friend
dynamic_cast
template
else
enum
mutable
explicit
true
export
typedef
float
typename
extern
not
typeid
do
operator
reinterpret_cast
this
struct
thread_local
long
goto
or
register
return
new
wchar_t
throw
while

eで始まる単語は5つとも使っているのでこれ以上しりとりを続けることはできない。
・wchar_tとthrow、enumとmutableが閉路をなしていること
・yで始まる単語がないことより、
上に挙げた7候補で終わるしりとりが最長であると考えることができる。
(編注：最長しりとりは35連鎖ですのでこの考察は誤りです)
*/