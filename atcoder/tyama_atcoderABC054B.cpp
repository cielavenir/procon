#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

const int B1=123456789;
const int B2=999999937;
const int P=1000000007;

void gen_hash(const vector<string> &m,int H,int W,int R,int C,vector<vector<long long> >&hash){
	vector<vector<long long> > hash1(H);
	hash.resize(H);

	for(int h=0;h<H;h++){
		hash1[h].resize(W);
		hash[h].resize(W);

		long long c=0;
		long long Brev=1;
		for(int w=0;w<W;w++){
			c=(c*B1+m[h][w])%P;
			if(w<C)Brev=Brev*B1%P;else c=((c-m[h][w-C]*Brev)%P+P)%P;
			hash1[h][w]=c;
		}
	}
	for(int w=0;w<W;w++){
		long long c=0;
		long long Brev=1;
		for(int h=0;h<H;h++){
			c=(c*B2+hash1[h][w])%P;
			if(h<R)Brev=Brev*B2%P;else c=((c-hash1[h-R][w]*Brev)%P+P)%P;
			hash[h][w]=c;
		}
	}
}

int main(){
	int H,W,R,C;
	cin>>H>>R;W=H,C=R;
	vector<string>field(H);
	for(int i=0;i<H;i++)cin>>field[i];
	vector<string>pattern(R);
	for(int i=0;i<H;i++)cin>>pattern[i];
	vector<vector<long long> >hash_field,hash_pattern;
	gen_hash(field,H,W,R,C,hash_field);
	gen_hash(pattern,R,C,R,C,hash_pattern);
	for(int h=R-1;h<H;h++)for(int w=C-1;w<W;w++){
		if(hash_field[h][w]==hash_pattern[R-1][C-1]){puts("Yes");return 0;}
	}
	puts("No");
}
