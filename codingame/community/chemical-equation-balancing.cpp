//ICPC 2009 asia-rational F

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef unordered_map<string,long long> molecule;

// cpp_rational (C) by @cielavenir under 2-clause BSDL.
// https://github.com/cielavenir/cpp_libraries/blob/master/rational/rational.hpp

long long gcd2(long long x,long long y){return y?gcd2(y,x%y):x;}
long long gcd(long long x,long long y){
	if(x<0)x=-x;
	if(y<0)y=-y;
	return gcd2(x,y);
}
long long lcm(long long x,long long y){return y/gcd(x,y)*x;}

/// rational ///
#ifdef BOOST
#include <boost/rational.hpp>
typedef boost::rational<long long> RLL;
#else
#include <ostream>
template<typename I>
class rational{
	I num,den;
public:
	rational(I _num=0,I _den=1){assign(_num,_den);}
	rational& operator=(I n){return assign(n,1);}
	rational& assign(I n,I d){
		if(n==0){
			d=1;
		}else{
			I g=gcd(n,d);
			n/=g;
			d/=g;
			if(d<0){
				n=-n;
				d=-d;
			}
		}
		num=n;
		den=d;
		return *this;
	}

	//utility
	I numerator() const{return num;}
	I denominator() const{return den;}
	rational reverse() const{return rational(den,num);}

	//arithmetic
	//To avoid license issue, we use ruby/rational.c implementation.
	rational& operator+=(const rational<I> &other){
		I g=gcd(den,other.den);
		I a=other.den/g*num;
		I b=den/g*other.num;
		I c=a+b;
		b=den/g;
		g=gcd(c,g);
		num=c/g;
		den=other.den/g*b;
		return *this;
	}
	rational& operator-=(const rational<I> &other){return *this+=-other;}
	rational& operator*=(const rational<I> &other){
		I g1=gcd(num,other.den);
		I g2=gcd(den,other.num);
		num=(num/g1)*(other.num/g2);
		den=(den/g2)*(other.den/g1);
		return *this;
	}
	rational& operator/=(const rational<I> &other){return *this*=other.reverse();}

	//arithmetic with copy
	rational operator+(const rational<I> &other) const{return rational(*this)+=other;}
	rational operator-(const rational<I> &other) const{return rational(*this)-=other;}
	rational operator*(const rational<I> &other) const{return rational(*this)*=other;}
	rational operator/(const rational<I> &other) const{return rational(*this)/=other;}

	//unary
	rational& operator++(){num+=den;return *this;}
	rational& operator--(){num-=den;return *this;}
	operator bool() const{return !!num;}
	bool operator!() const{return !num;}
	rational operator+() const{return *this;}
	rational operator-() const{return rational(-num,den);}

	//comparison
	bool operator==(const rational<I> &other) const{return num==other.num&&den==other.den;}
	bool operator!=(const rational<I> &other) const{return num!=other.num||den!=other.den;}
	bool operator<(const rational<I> &other) const{return num*other.den<other.num*den;}
	bool operator>(const rational<I> &other) const{return num*other.den>other.num*den;}
	bool operator<=(const rational<I> &other) const{return num*other.den<=other.num*den;}
	bool operator>=(const rational<I> &other) const{return num*other.den>=other.num*den;}
};
namespace std{
	//cpp_inspect compat
	template<typename I>
	ostream& operator<<(ostream& out,const rational<I> &r){
		return out<<r.numerator()<<"/"<<r.denominator();
	}
}
template<typename I>
rational<I> abs(const rational<I> &r){
	if(r.numerator()>=0)return r;
	return rational<I>(-r.numerator(),r.denominator());
}
template<typename T,typename I>
T rational_cast(const rational<I> &r){
	return static_cast<T>(r.numerator())/static_cast<T>(r.denominator());
}
typedef rational<long long> RLL;
#endif

/// paiza ///
molecule dfs(const vector<string> &s,int L,int R){
	molecule r;
	int i=L;
	long long n=1;
	for(;i<R;){
		if('0'<=s[i][0]&&s[i][0]<='9'){
			n=strtol(s[i].c_str(),NULL,10);
			i++;
		}else if(s[i]=="("){
			int cnt=1,j=i+1;
			for(;cnt;){
				if(s[j]=="(")
					cnt++;
				else if(s[j]==")")
					cnt--;
				j++;
			}
			auto r0=dfs(s,i+1,j-1);
			for(auto &e:r0){
				r[e.first]+=n*e.second;
			}
			n=1;
			i=j;
		}else{
			r[s[i]]+=n;
			n=1;
			i++;
		}
	}
	return r;
}
vector<string> tokenize_rev(const string &s){
	vector<string> v;
	for(int i=0;i<s.size();){
		if(s[i]=='('){
			v.push_back(")"),i++;
		}else if(s[i]==')'){
			v.push_back("("),i++;
		}else if('0'<=s[i]&&s[i]<='9'){
			int j=i+1;
			for(;'0'<=s[j]&&s[j]<='9';j++);
			v.push_back(s.substr(i,j-i));
			i=j;
		}else if('A'<=s[i]&&s[i]<='Z'){
			int j=i+1;
			for(;'a'<=s[j]&&s[j]<='z';j++);
			v.push_back(s.substr(i,j-i));
			i=j;
		}
	}
	reverse(v.begin(),v.end());
	return v;
}

/// checkio expected-dice ///
bool gauss(vector<vector<RLL> > &a){
	if(a.empty())return false;
	int n=a.size(),i=0;
	for(;i<n;i++){
		if(!a[i][i]){
			int j=i+1;
			for(;j<n;j++){
				if(a[j][i]){
					for(int k=i;k<a[0].size();k++)a[i][k]+=a[j][k];
					break;
				}
			}
			if(j==n)break;
		}
		for(int j=0;j<n;j++)if(i!=j){
			auto r=a[j][i]/a[i][i];
			for(int k=i;k<a[0].size();k++)a[j][k]=a[j][k]-a[i][k]*r;
		}
	}
	for(i--;i>=0;i--){
		auto x=a[i][i];
		for(int j=0;j<a[i].size();j++)a[i][j]/=x;
	}
	return true;
}

int main(){
	string _line;
	for(;getline(cin,_line);){
		vector<int>to_print={0};
		string line;
		for(int i=0;i<_line.size();i++){
			if(_line[i]!=' ')line+=_line[i];
		}
		line+='.';
		unordered_set<string> _elements;
		vector<molecule> formula;
		int prev=0,cur=0,factor=1;
		for(;cur<line.size();cur++){
			if(line[cur]=='+'||line[cur]=='-'||line[cur]=='.'){
				vector<string> token=tokenize_rev(line.substr(prev,cur-prev));
				auto r=dfs(token,0,token.size());
				for(auto &&e:r){
					_elements.insert(e.first);
					e.second*=factor;
				}
				formula.push_back(r);
				if(line[cur]=='-')factor=-1,cur++;
				prev=cur+1;
			}
		}
		vector<string> elements=vector<string>(_elements.begin(),_elements.end());
		//should be formula.size(). otherwise some elements have the same ratio.
		vector<vector<RLL> >a(elements.size()+1);
		for(int i=0;i<a.size();i++){
			a[i].resize(formula.size()+1);
			if(i<a.size()-1){
				for(int j=0;j<formula.size();j++){
					if(formula[j][elements[i]]){
						a[i][j]=formula[j][elements[i]]>0?1:-1;
						a[i][j]*=abs(formula[j][elements[i]]);
					}
				}
			}else{
				for(int j=0;j<formula.size();j++)a[i][j]=1;
				a[i][formula.size()]=1;
			}
		}
		gauss(a);
		long long L=1;
		for(int i=0;i<formula.size();i++)L=lcm(L,a[i][formula.size()].denominator());
		//for(int i=0;i<formula.size();i++)printf(i<formula.size()-1?"%lld ":"%lld\n",L/a[i][formula.size()].denominator()*a[i][formula.size()].numerator());

		long long x=L/a[0][formula.size()].denominator()*a[0][formula.size()].numerator();
		if(x>1)printf("%lld",x);
		for(int i=0,j=1;i<_line.size();i++){
			putchar(_line[i]);
			if(_line[i]==' '){
				if(_line[i+1]!='-'&&_line[i+1]!='+'){
					long long x=L/a[j][formula.size()].denominator()*a[j][formula.size()].numerator();
					if(x>1)printf("%lld",x);
					j++;
				}
			}
		}
		putchar('\n');
	}
}
