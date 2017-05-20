//C99 or C++98
//https://reponroy.wordpress.com/2015/10/13/bitonic-travelling-salesman-problem/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define forn(i,n)               for( int i=0 ; i < n ; i++ )
#define ms(ara_name,value) memset(ara_name,value,sizeof(ara_name))
#define min(a,b)                ((a)>(b) ? (b) : (a) )
#define max(a,b)                ((a)>(b) ? (a) : (b))
#define INF                     1<<29

const int N = 1000;
int n;
double dp[N][N];
int p[N][2];
double d[N][N];
bool vis[N][N];
double calc(int p1,int p2)
{
    int v= max(p1,p2)+1;
    if(v==n-1){
        return d[p1][v] + d[p2][v];
    }
    if(vis[p1][p2]) return dp[p1][p2];
    double r= INF;
    dp[p1][p2] = min( d[p1][v] + calc(v,p2) , d[p2][v] + calc(p1,v));
    vis[p1][p2] = 1;
    return dp[p1][p2];
}
 
int main()
{
 
    while(scanf("%d",&n)==1) {
        for(int i=0;i<n;i++) {
            scanf("%d%d",&p[i][0],&p[i][1]);
        }
        forn(i,n)forn(j,n){
            d[i][j] = sqrt((p[i][0]- p[j][0]) * (p[i][0] - p[j][0]) + (p[i][1]-p[j][1])*(p[i][1]-p[j][1]));
        }
        ms(vis,0);
        printf("%f\n", calc(0,0));
    }
    return 0;
}
