#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;

// 最初のsampleではpref_m[’a’] は BAC... (先頭N文字だけ使い,他はnull)
char pref_m[128][128]={{0}}, pref_f[128][128]={{0}};
// 女性f が,男性aを男性bを好む場合に真
bool better(char f, char a, char b){
	int orda = find(pref_f[f], pref_f[f]+128, a)-pref_f[f]; // a のリスト内の順位
	int ordb = find(pref_f[f], pref_f[f]+128, b)-pref_f[f]; // b
	return orda < ordb;
}

int N;
void solve(string &name_m, string &name_f) {
	char m2f[128]={0}, f2m[128]={0};
	int proposed[128]={0};
	int man_id = 0; // 何人目の男性
	for(;;){
		char man = name_m[man_id]; // 男性の名前
		if(m2f[man]){ // 割り当て済
			++man_id; // 次の人へ
			if(man_id==N)break;
		}else{
			for(;!m2f[man];){
				char f = pref_m[man][ proposed[man] ];
				proposed[man]++;
				char mate = f2m[f];
				if(!mate || better(f, man, mate)){
					if(mate)m2f[mate]=0; // mateとfはペアでなくなった
					m2f[man]=f,f2m[f]=man;
					man_id=0; // 初めから見直す
				}
			}
		}
	}
	for(int i=0;i<N;++i)printf("%c %c\n",name_m[i],m2f[name_m[i]]);
}

int main(){
	int t=0,T,i;
	scanf("%d", &T);
	for(;t<T;++t){
		scanf("%d",&N);
		string name_m, name_f;
		char c;
		for(i=0;i<N;++i){
			scanf(" %c", &c);
			name_m += c;
		}
		for(i=0; i<N; ++i){
			scanf(" %c", &c);
			name_f += c;
		}
		sort(name_m.begin(), name_m.end());
		for(i=0;i<N;++i){
			scanf(" %c:", &c);
			scanf("%s", pref_m[(int)c]);
		}
		for(i=0;i<N;++i){
			scanf(" %c:", &c);
			scanf("%s", pref_f[(int)c]);
		}
		if(t)puts("");
		solve(name_m,name_f);
	}
}