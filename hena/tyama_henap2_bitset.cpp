//usr/bin/true; tmpfile=$(mktemp); g++ -std=c++11 -O3 -Ofast -march=native -o $tmpfile "$0" && $tmpfile; rm -f $tmpfile; exit

//https://nabetani.sakura.ne.jp/ord/p.2_rotpolygonbin/
//https://zenn.dev/nabetani/scraps/486b92465f2214

#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <cassert>

#include <boost/dynamic_bitset.hpp>
#include <boost/lexical_cast.hpp>

std::string unpackN(const std::string &n){
  // Simulate Ruby `n.split(/(\[\d+\])/).map{|e|e[0]=='[' ? '0'*e[1..-2].to_i : e.to_i.to_s(2)}.join`
  static const std::regex re(R"(\[\d+\])");
  std::string r="";
  for(std::sregex_token_iterator it(n.begin(),n.end(),re,{-1,0}),end;it!=end;++it){
    const auto &m=(*it).str();
    if(m[0]=='['){
      r+=std::string(std::stoll(m.substr(1,m.size()-2)),'0');
    }else{
      // r+=std::format("{:b}",std::stoll(m));
      // using boost::dynamic_bitset, C++11 suffices.
      auto v=std::stoll(m);
      auto bitnum=64-__builtin_clzll(v);
      r+=boost::lexical_cast<std::string>(boost::dynamic_bitset<>(bitnum,v));
    }
  }
  return r;
}

int compare(const std::vector<boost::dynamic_bitset<>> &a, const std::vector<boost::dynamic_bitset<>> &b){
  assert(a.size() == b.size());
  for(int i=0;i<a.size();i++){
    if(a[i]<b[i])return -1;
    if(a[i]>b[i])return 1;
  }
  return 0;
}

int main(){
  int B;
  std::string n, n_;
  for(;std::cin>>B>>n_;){
    n=unpackN(n_);
    int depth=1,siz=B;
    for(;siz<n.size();){
      depth+=1;
      siz+=B*depth;
    }
    n=std::string(siz-n.size(),'0')+n;
    siz=B*depth;
    std::vector<boost::dynamic_bitset<>> bits;
    bits.emplace_back(n,0,siz,siz);
    for(int d=depth;d>1;){
      int oldsiz=siz;
      d-=1;
      siz+=B*d;
      bits.emplace_back(n,oldsiz,siz-oldsiz,siz-oldsiz);
    }
    auto ma=bits,mi=bits;
    std::vector<int>vma,vmi;
    for(int b=0;b<B;b++){
      int cma=compare(ma,bits);
      int cmi=compare(mi,bits);
      if(cma<0){ma=bits;vma.clear();}
      if(cma<=0)vma.push_back(b);
      if(cmi>0){mi=bits;vmi.clear();}
      if(cmi>=0)vmi.push_back(b);
      for(int iViews=0;iViews<depth;iViews++){
        int x=depth-iViews;
        bits[iViews] = (bits[iViews]<<x) | (bits[iViews]>>(bits[iViews].size()-x));
      }
    }
    for(int i=0;i<vmi.size();i++){
      if(i>0)std::cout<<',';
      std::cout<<vmi[i];
    }
    std::cout<<'/';
    for(int i=0;i<vma.size();i++){
      if(i>0)std::cout<<',';
      std::cout<<vma[i];
    }
    std::cout<<std::endl;
  }
}
