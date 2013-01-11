#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int m[30][30][30];
int main(){
  int x,y,z,sx,sy,sz,ex,ey,ez,i,j,k,w;
  for(;scanf("%d%d%d",&z,&y,&x),x;){
    memset(m,0,sizeof(m));
    for(i=0;i<z;i++)
      for(j=0;j<y;j++)
        for(k=0;k<x;k++){
          retry:
          w=getchar();
          switch(w){
            case '.':break;
            case '#':m[k][j][i]=-1;break;
            case 'S':sz=i,sy=j,sx=k;m[k][j][i]=1;break;
            case 'E':ez=i,ey=j,ex=k;break;
            default:goto retry;
          }
        }

    queue<pair<int,pair<int,int> > >q;
    q.push(make_pair(sx,make_pair(sy,sz)));
    while(!m[ex][ey][ez]&&q.size()){
      i=q.front().first;
      j=q.front().second.first;
      k=q.front().second.second;
      q.pop();
      if(i>0  &&!m[i-1][j][k]){m[i-1][j][k]=m[i][j][k]+1;q.push(make_pair(i-1,make_pair(j,k)));}
      if(i<x-1&&!m[i+1][j][k]){m[i+1][j][k]=m[i][j][k]+1;q.push(make_pair(i+1,make_pair(j,k)));}
      if(j>0  &&!m[i][j-1][k]){m[i][j-1][k]=m[i][j][k]+1;q.push(make_pair(i,make_pair(j-1,k)));}
      if(j<y-1&&!m[i][j+1][k]){m[i][j+1][k]=m[i][j][k]+1;q.push(make_pair(i,make_pair(j+1,k)));}
      if(k>0  &&!m[i][j][k-1]){m[i][j][k-1]=m[i][j][k]+1;q.push(make_pair(i,make_pair(j,k-1)));}
      if(k<z-1&&!m[i][j][k+1]){m[i][j][k+1]=m[i][j][k]+1;q.push(make_pair(i,make_pair(j,k+1)));}
    }

    printf(m[ex][ey][ez]?"Escaped in %d minute(s).\n":"Trapped!\n",m[ex][ey][ez]-1);
  }
}