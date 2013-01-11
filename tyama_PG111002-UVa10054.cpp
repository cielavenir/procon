//tyama070616necklace.cpp
//チームの皆さんvector使ってごめんなさい^^;
//こんなに豪勢にvector使うとC版はムリポですね^^;
//というかforeachのありがたみを実感したw

#include <algorithm>
#include <vector>
//#include <iostream> //goodbye, cin and cout!
#include <stdio.h>

#define hi(_x) ((_x)>>16)
#define lo(_x) ((_x)&0xffff)
using namespace std;

/*
void rotate(vector<int> &v,const int index){
  int i;
  vector<int> x=v;
  v.clear();
  for(i=0; i<x.size()-index; i++)
    v.push_back(x[i+index]);
  for(i=0; i<index; i++)
    v.push_back(x[i]);
}
*/

#define rotate(v, index) rotate((v).begin(), (v).begin()+(index), (v).end())

//__stdcallは使えないの?しょうがないんでinline。
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
    //fail //Case #8を通すにはfail判定はここでする必要がある。
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
      if(lo(s[a])==hi(v[i])||lo(s[a])==lo(v[i]))goto in;//break;
    }
    /*if(i==v.size())*/break;
in:
    x=hi(v[i]), y=lo(v[i]);
    v.erase(v.begin()+i);
    if(lo(s[a])==y)swap(x,y);
    s.push_back((x<<16)+y);
    a++;
  }//while
  return hi(s[0])==lo(s[a]);
}

int main(){
  int i=0, k;
  int n, l, x, y;
  vector<int> vorig;
  vector<vector<int>*> varray;
  vector<int> vunite;

  //stdout->_bufsiz=0x10000; //^^; //使えないんかい。

  scanf("%d",&n);//cin >> n;
  for(;i<n;i++){
    if(i) printf("\n");//cout << endl;
    printf("Case #%d\n",i+1);//cout << "Case #" << i+1 << endl;
    scanf("%d",&l);//cin >> l;

    for(k=0;k<l;k++){
      scanf("%d %d",&x, &y);//cin >> x >> y;
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
      printf("%d %d\n",hi(vunite[0]),lo(vunite[0]));
      //cout << hi(vunite[0]) << " " << lo(vunite[0]) << endl;
      vunite.erase(vunite.begin());
    }
    continue;

fail:
    while(varray.size()){
      delete varray[0];
      varray.erase(varray.begin());
    }
    printf("some beads may be lost\n");//cout << "some beads may be lost" << endl;
    vorig.clear();
    vunite.clear();
  }//for
}//main

/* Good Testset
9
5
3 1
3 4
2 4
2 1
2 2
6
3 1
2 4
2 1
3 4
5 2
5 2
14
3 1
3 4
2 4
2 1
6 2
5 2
3 6
5 3
4 7
7 8
4 2
9 8
2 7
7 9
14
3 1
3 4
2 4
2 1
6 2
5 2
3 6
5 7
4 7
7 8
4 2
9 8
2 7
7 9
8
1 3
5 6
8 6
6 5
3 5
8 9
6 9
5 1
9
14 6
17 6
18 13
6 18
14 17
18 17
5 18
17 13
6 5
5
17 25
27 13
14 25
13 17
27 14
22
1 3
5 6
8 6
6 5
3 5
8 9
6 9
5 1
17 25
27 13
14 25
13 17
27 14
14 6
17 6
18 13
6 18
14 17
18 17
5 18
17 13
6 5
12
1 2
2 2
2 3
3 3
3 4
4 1
11 12
12 12
12 13
14 11
1 11
11 1

You should pass except Case #4.
Especially, Case #8 is the addition of Case #5, #7, #6 :)
*/