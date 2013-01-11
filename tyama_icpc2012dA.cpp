#include <iostream>
using namespace std;
int main(){int y,m,d;for(cin>>y;cin>>y>>m>>d;cout<<(196471-(--y)*195-y/3*5-(--m)*20+(y%3-2?m/2:0)-d)<<endl);}