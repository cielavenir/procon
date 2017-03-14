// http://qiita.com/Nabetani/items/1c83005a854d2c6cbb69
// http://nabetani.sakura.ne.jp/hena/ord24eliseq/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <functional>
#include <numeric>
#include <experimental/generator>
#include <cstdio>
#include <cmath>
using namespace std;
using namespace std::experimental;

generator<int> generate(){
	int i=1;
	for(;;){
		co_yield i;
		i+=1;
	}
}
generator<int> drop_prev(bool(*check)(int),generator<int> _prev){
	auto prev=_prev.begin();
	int a=*prev;
	++prev;
	int b=*prev;
	for(;;){
		if(!check(b))co_yield a;
		a=b;
		++prev;
		b=*prev;
	}
}
generator<int> drop_next(bool(*check)(int),generator<int> _prev){
	auto prev=_prev.begin();
	int a=*prev;
	++prev;
	int b=*prev;
	co_yield a;
	for(;;){
		if(!check(a))co_yield b;
		a=b;
		++prev;
		b=*prev;
	}
}
generator<int> drop_n(bool(*check)(int,int),int n,generator<int> _prev){
	auto prev=_prev.begin();
	int i=0;
	for(;;){
		i++;
		int a=*prev;
		if(!check(i,n))co_yield a;
		++prev;
	}
}
bool is_sq(int n){
	int x=(int)sqrt(n);
	return x*x==n;
}
bool is_cb(int n){
	int x=(int)cbrt(n);
	return x*x*x==n;
}
bool is_multiple(int i,int n){return i%n==0;}
bool is_le(int i,int n){return i<=n;}

int main(){
	map<char,function<generator<int>(generator<int>)>> f={
		{'S',[&](auto e){return drop_next(&is_sq,move(e));}},
		{'s',[&](auto e){return drop_prev(&is_sq,move(e));}},
		{'C',[&](auto e){return drop_next(&is_cb,move(e));}},
		{'c',[&](auto e){return drop_prev(&is_cb,move(e));}},
		{'h',[&](auto e){return drop_n(&is_le,100,move(e));}},
	};
	vector<int>v(8);
	iota(v.begin(),v.end(),2);
	for(auto &e:v)f[(char)('0'+e)] = [&](int &j){
		return [&](auto e){return drop_n(&is_multiple,j,move(e));};
	}(e);

	string line;
	for(;getline(cin,line);){
		bool first=true;
		//cS => f['S'](f['c'](generate()))
		//auto z=reduce!((s,e)=>f[e](s))(generate(),line);

		auto z=generate();
		for(char e:line)z=f[e](move(z));
		auto it=z.begin();
		for(int i=0;i<10;i++){
			int n=*it;
			++it;
			if(!first)putchar(',');
			first=false;
			printf("%d",n);
		}
		puts("");
		fflush(stdout);
	}
}
