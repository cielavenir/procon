#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

char m[14][9];

void dfs(int i, int j, vector<pair<int,int> >&v, vector<pair<int,int> >&w){
  v.push_back(make_pair(i,j));
  if(m[i-1][j]==m[i][j]&&find(v.begin(),v.end(),make_pair(i-1,j))==v.end())dfs(i-1,j,v,w);
  if(m[i+1][j]==m[i][j]&&find(v.begin(),v.end(),make_pair(i+1,j))==v.end())dfs(i+1,j,v,w);
  if(m[i][j-1]==m[i][j]&&find(v.begin(),v.end(),make_pair(i,j-1))==v.end())dfs(i,j-1,v,w);
  if(m[i][j+1]==m[i][j]&&find(v.begin(),v.end(),make_pair(i,j+1))==v.end())dfs(i,j+1,v,w);
  if(m[i-1][j]=='O'&&find(w.begin(),w.end(),make_pair(i-1,j))==w.end())w.push_back(make_pair(i-1,j));
  if(m[i+1][j]=='O'&&find(w.begin(),w.end(),make_pair(i+1,j))==w.end())w.push_back(make_pair(i+1,j));
  if(m[i][j-1]=='O'&&find(w.begin(),w.end(),make_pair(i,j-1))==w.end())w.push_back(make_pair(i,j-1));
  if(m[i][j+1]=='O'&&find(w.begin(),w.end(),make_pair(i,j+1))==w.end())w.push_back(make_pair(i,j+1));
}

main(){
  int i,j,k,r=0,f;
  memset(m,'X',sizeof(m)); //Iron Puyo
  for(i=1;i<13;i++)scanf("%s",m[i]+1);
  for(i=0;i<14;i++)m[i][7]='X',m[i][8]=0;
  for(i=1;i<7;i++)m[0][i]='.';
  for(;;){
    f=0;
    vector<pair<int,int> >v,w;
    for(i=1;i<13;i++)
      for(j=1;j<7;j++){
        if(m[i][j]=='R'||m[i][j]=='G'||m[i][j]=='B'||m[i][j]=='Y'||m[i][j]=='P'){
          dfs(i,j,v,w);
          if(v.size()>3){
            f=1;
            for(k=0;k<v.size();k++)
              m[v[k].first][v[k].second]='.';
            for(k=0;k<w.size();k++)
              m[w[k].first][w[k].second]='.';
          }
          v.clear(),w.clear();
        }
      }
    if(f){
      for(j=1;j<7;j++)
        for(i=12;i;i--){
          for(k=i;k&&m[k][j]=='.';k--);
          swap(m[i][j],m[k][j]);
        }
      r++;
      continue;
    }
    break;
  }
  printf("%d\n",r);
}