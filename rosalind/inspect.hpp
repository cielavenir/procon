// cpp_inspect by @cielavenir under Boost Software License.

#include <iostream>
#include <sstream>
#include <string>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
namespace std{
#ifndef NDEBUG
	ostream& operator<<(ostream &out,const char &c){
		out.rdbuf()->sputc('\'');
		out.rdbuf()->sputc(c);
		out.rdbuf()->sputc('\'');
		return out;
	}
	ostream& operator<<(ostream &out,const string &s){
		out.rdbuf()->sputc('"');
		for(auto &c:s)out.rdbuf()->sputc(c);
		out.rdbuf()->sputc('"');
		return out;
	}
#endif
	template<typename T, typename S>
	ostream& operator<<(ostream &out,const pair<T,S> &e){
		return out<<"{"<<e.first<<","<<e.second<<"}";
	}
	template<typename T, size_t N>
	ostream& operator<<(ostream &out,const array<T,N> &v){
		out<<"{{";
		for(auto &e:v)out<<e<<",";
		out<<"}}";
		return out;
	}
	template<typename T>
	ostream& operator<<(ostream &out,const vector<T> &v){
		out<<"{";
		for(auto &e:v)out<<e<<",";
		out<<"}";
		return out;
	}
	template<typename T>
	ostream& operator<<(ostream &out,const deque<T> &v){
		out<<"{";
		for(auto &e:v)out<<e<<",";
		out<<"}";
		return out;
	}
	template<typename T>
	ostream& operator<<(ostream &out,const list<T> &v){
		out<<"{";
		for(auto &e:v)out<<e<<",";
		out<<"}";
		return out;
	}
	template<typename T>
	ostream& operator<<(ostream &out,const forward_list<T> &v){
		out<<"{";
		for(auto &e:v)out<<e<<",";
		out<<"}";
		return out;
	}
	template<typename T>
	ostream& operator<<(ostream &out,const set<T> &v){
		out<<"{";
		for(auto &e:v)out<<e<<",";
		out<<"}";
		return out;
	}
	template<typename T>
	ostream& operator<<(ostream &out,const unordered_set<T> &v){
		out<<"{";
		for(auto &e:v)out<<e<<",";
		out<<"}";
		return out;
	}
	template<typename T>
	ostream& operator<<(ostream &out,const multiset<T> &v){
		out<<"{";
		for(auto &e:v)out<<e<<",";
		out<<"}";
		return out;
	}
	template<typename T>
	ostream& operator<<(ostream &out,const unordered_multiset<T> &v){
		out<<"{";
		for(auto &e:v)out<<e<<",";
		out<<"}";
		return out;
	}
	template<typename T,typename S>
	ostream& operator<<(ostream &out,const map<T,S> &v){
		out<<"{";
		for(auto &e:v)out<<e<<",";
		out<<"}";
		return out;
	}
	template<typename T,typename S>
	ostream& operator<<(ostream &out,const unordered_map<T,S> &v){
		out<<"{";
		for(auto &e:v)out<<e<<",";
		out<<"}";
		return out;
	}
	template<typename T,typename S>
	ostream& operator<<(ostream &out,const multimap<T,S> &v){
		out<<"{";
		for(auto &e:v)out<<e<<",";
		out<<"}";
		return out;
	}
	template<typename T,typename S>
	ostream& operator<<(ostream &out,const unordered_multimap<T,S> &v){
		out<<"{";
		for(auto &e:v)out<<e<<",";
		out<<"}";
		return out;
	}
}
template<typename T>
std::string inspect(const T &e){
	std::ostringstream ss;
	ss<<e;
	return ss.str();
}
