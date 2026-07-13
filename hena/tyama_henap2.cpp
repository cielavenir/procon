//usr/bin/true; tmpfile=$(mktemp); g++ -std=c++20 -O3 -Ofast -march=native -o $tmpfile "$0" && $tmpfile; rm -f $tmpfile; exit

//https://nabetani.sakura.ne.jp/ord/p.2_rotpolygonbin/

//BITSUMは塗られた数値の合計の大小比較と誤読して作ってしまったやつ。かっこわるいね。

#include <iostream>
#include <string>
#include <regex>
#include <format>
#include <cassert>

std::string unpackN(const std::string &n){
  // n.split(/(\[\d+\])/).map{|e|e[0]=='[' ? '0'*e[1..-2].to_i : e.to_i.to_s(2)}.join
  const std::regex re(R"(\[\d+\])");
  std::string r="";
  for(std::sregex_token_iterator it(n.begin(),n.end(),re,{-1,0}),end;it!=end;++it){
    auto &&m=(*it).str();
    if(m[0]=='['){
      r+=std::string(std::stoll(m.substr(1,m.size()-2)),'0');
    }else{
      r+=std::format("{:b}",std::stoll(m));
    }
  }
  return r;
}

#ifndef BITSUM
int compare(std::string a, std::string b){
  assert(a.size() == b.size());
  for(int i=a.size()-1;i>=0;i--){
    if(a[i]<b[i])return -1;
    if(a[i]>b[i])return 1;
  }
  return 0;
}
#endif

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
    std::reverse(n.begin(),n.end());
    depth=1,siz=B;
    auto views=std::vector({std::make_pair(n.begin(),n.begin()+siz)});
    for(;siz<n.size();){
      int oldsiz=siz;
      depth+=1;
      siz+=B*depth;
      views.push_back(std::make_pair(n.begin()+oldsiz,n.begin()+siz));
    }
#ifdef BITSUM
    int ma=0,mi=1<<29;
#else
    std::string ma(n.size(),'0'),mi(n.size(),'1');
#endif
    std::vector<int>vma,vmi;
    for(int b=0;b<B;b++){
#ifdef BITSUM
      #define VAL val
      int val=0;
      for(int i=0;i<n.size();i++)if(n[i]=='1')val+=i;
      int cma = ma<val ? -1 : ma>val ? 1 : 0;
      int cmi = mi<val ? -1 : mi>val ? 1 : 0;
#else
      #define VAL n
      int cma = compare(ma,n);
      int cmi = compare(mi,n);
#endif
      if(cma<0){ma=VAL;vma.clear();}
      if(cma<=0)vma.push_back((B-b)%B);
      if(cmi>0){mi=VAL;vmi.clear();}
      if(cmi>=0)vmi.push_back((B-b)%B);
      for(int iViews=0;iViews<views.size();iViews++){
        std::rotate(views[iViews].first, views[iViews].first+(iViews+1), views[iViews].second);
      }
    }
    sort(vma.begin(),vma.end());
    sort(vmi.begin(),vmi.end());
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
