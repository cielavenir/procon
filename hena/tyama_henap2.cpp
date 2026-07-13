#include <iostream>
#include <string>
#include <regex>
#include <format>

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
    int ma=0,mi=1<<29;
    std::vector<int>vma,vmi;
    for(int b=0;b<B;b++){
      int val=0;
      for(int i=0;i<n.size();i++)if(n[i]=='1')val+=i;
      if(ma<val){ma=val;vma.clear();}
      if(ma==val)vma.push_back(b);
      if(mi>val){mi=val;vmi.clear();}
      if(mi==val)vmi.push_back(b);
      for(int iViews=0;iViews<views.size();iViews++){
        std::rotate(views[iViews].first, views[iViews].first+(iViews+1), views[iViews].second);
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
