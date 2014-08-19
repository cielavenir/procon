//copied from PG111002(UVa10054)
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>

#define hi(_x) ((_x)>>16)
#define lo(_x) ((_x)&0xffff)
using namespace std;
#define rotate(v, index) rotate((v).begin(), (v).begin()+(index), (v).end())

inline int unite(vector<int> &u, vector<vector<int>*> &array){
  int _array, _u, _each;
  while(array.size()){
    for(_array=0; _array<array.size(); _array++){//今まで作ったeuler閉路すべてに対しuと結合できるかどうか調べる
      vector<int> each = *(array[_array]); //eachはeuler閉路を構成すると仮定する
      for(_u=0; _u<u.size(); _u++){
        for(_each=0; _each<each.size(); _each++){
          if(lo(u[_u])==hi(each[_each])){
            if(_each)rotate(each,_each); //each[_each]が先頭に来るよう頭だし
            u.insert(u.begin()+_u+1,each.begin(),each.end());
            delete array[_array];
            array.erase(array.begin()+_array);
            goto next;
          }
        }
      }
    }
    //fail
    return 0;
    next:
    /*continue*/;
  }//while
  return 1;
}

inline int sort(vector<int>&s,vector<int>&v){
  int x=hi(v[0]), y=lo(v[0]), i, a=0;
  v.erase(v.begin());
  s.push_back((x<<16)+y);
  while(1){
    for(i=0; i<v.size(); i++){
      if(lo(s[a])==hi(v[i])/*||lo(s[a])==lo(v[i])*/)goto in;//break;
    }
    /*if(i==v.size())*/break;
in:
    x=hi(v[i]), y=lo(v[i]);
    v.erase(v.begin()+i);
    //if(lo(s[a])==y)swap(x,y);
    s.push_back((x<<16)+y);
    a++;
  }//while
  return hi(s[0])==lo(s[a]);
}

char s[99];
int main(){
  int i=0, k;
  int n, l, x, y;
  vector<int> vorig;
  vector<vector<int>*> varray;
  vector<int> vunite;

  //scanf("%d",&n);
  //for(;i<n;i++){
  for(;;){
    //if(i) printf("\n");
    //printf("Case #%d\n",i+1);
    scanf("%d",&l);
    if(!l)return 0;

    for(k=0;k<l;k++){
      //scanf("%d %d",&x, &y);
      scanf("%s",s);
      x=s[0]-96,y=s[strlen(s)-1]-96;
      vorig.push_back((x<<16)+y);
    }

    while(vorig.size()){
      vector<int> *p = new vector<int>;
      if(!sort(*p,vorig))goto fail;
      varray.push_back(p);
    }

    vunite = *(varray[0]);
    delete varray[0];
    varray.erase(varray.begin());
    if(!unite(vunite,varray))goto fail;

    while(vunite.size()){
      //printf("%d %d\n",hi(vunite[0]),lo(vunite[0]));
      vunite.erase(vunite.begin());
    }
    puts("OK");
    continue;

fail:
    while(varray.size()){
      delete varray[0];
      varray.erase(varray.begin());
    }
    //puts("some beads may be lost");
    puts("NG");
    vorig.clear();
    vunite.clear();
  }//for
}//main