#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int i,n,t,x,a;
    vector< pair<int,int> > v;
    for(scanf("%d%d",&n,&t),i=0;i++<n;v.push_back(make_pair(x*2-a,x*2+a)))scanf("%d%d",&x,&a);
    sort(v.begin(),v.end());
    for(i=0,a=2;i<n-1;i++)a+=(v[i+1].first-v[i].second>=t*2)+(v[i+1].first-v[i].second>t*2);
    printf("%d\n",a);
}