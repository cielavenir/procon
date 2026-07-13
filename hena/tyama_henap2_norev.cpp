//usr/bin/true; tmpfile=$(mktemp); g++ -std=c++20 -O3 -Ofast -march=native -ltbb -o $tmpfile "$0" && $tmpfile; rm -f $tmpfile; exit

//https://nabetani.sakura.ne.jp/ord/p.2_rotpolygonbin/
//https://zenn.dev/nabetani/scraps/486b92465f2214

#include <iostream>
#include <string>
#include <regex>
#include <format>
#include <cassert>
#include <cstring>

#include <execution>

std::string unpackN(const std::string &n){
  // Simulate Ruby `n.split(/(\[\d+\])/).map{|e|e[0]=='[' ? '0'*e[1..-2].to_i : e.to_i.to_s(2)}.join`
  static const std::regex re(R"(\[\d+\])");
  std::string r="";
  for(std::sregex_token_iterator it(n.begin(),n.end(),re,{-1,0}),end;it!=end;++it){
    const auto &m=(*it).str();
    if(m[0]=='['){
      r+=std::string(std::stoll(m.substr(1,m.size()-2)),'0');
    }else{
      r+=std::format("{:b}",std::stoll(m));
    }
  }
  return r;
}

// (at least glibc) has highly-optimized memcmp implementation
// https://sourceware.org/git/?p=glibc.git;a=blob;f=sysdeps/x86_64/multiarch/memcmp-sse2.S
int compare(const std::string &a, const std::string &b){
  assert(a.size() == b.size());
#if 0
  for(int i=0;i<a.size();i++){
    if(a[i]<b[i])return -1;
    if(a[i]>b[i])return 1;
  }
#else
  return memcmp(a.data(),b.data(),a.size());
#endif
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
    auto views=std::vector({std::make_pair(n.begin(),n.begin()+siz)});
    for(int d=depth;d>1;){
      int oldsiz=siz;
      d-=1;
      siz+=B*d;
      views.push_back(std::make_pair(n.begin()+oldsiz,n.begin()+siz));
    }
    std::string ma=n,mi=n;
    std::vector<int>vma,vmi;
    for(int b=0;b<B;b++){
      int cma=compare(ma,n);
      int cmi=compare(mi,n);
      if(cma<0){ma=n;vma.clear();}
      if(cma<=0)vma.push_back(b);
      if(cmi>0){mi=n;vmi.clear();}
      if(cmi>=0)vmi.push_back(b);
//#pragma omp parallel for
      for(int iViews=0;iViews<depth;iViews++){
        auto first = views[iViews].first;
        auto middle = views[iViews].first+(depth-iViews);
        auto last = views[iViews].second;
        //std::rotate(first, middle, last);
        std::reverse(std::execution::par, first, middle);
        std::reverse(std::execution::par, middle, last);
        std::reverse(std::execution::par, first, last);
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
