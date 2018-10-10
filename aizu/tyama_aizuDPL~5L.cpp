#include <vector>
#include <cstdio>
int main(){
    int N,S,i;
    scanf("%d%d",&S,&N);
    if(S<0)puts("0");
    else{
        std::vector<int>bag(S+1);
        bag[0]=1;
        for(int i=1;i<=N;i++)for(int j=i;j<=S;j++)bag[j]=(bag[j-i]+bag[j])%1000000007;
        printf("%d\n",bag[S]);
    }
}
