#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<pair<string,int>>v(N);
    for(int i=0;i<N;i++)cin>>v[i].first,v[i].second=i+1;
    sort(v.begin(),v.end());
    for(int i=0;i<N;i++)cout<<v[i].second<<' ';
}