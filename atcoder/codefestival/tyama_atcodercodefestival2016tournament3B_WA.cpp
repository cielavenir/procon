#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;
#define MAX_N 1000001
char s[MAX_N];
// 入力
int n, k; int a[MAX_N];
int b[MAX_N];
int deq[MAX_N]; // デック
void solve() {
int s=0,t=0; // デックの先頭と末尾
for (int i = 0; i < n; i++) {
// デックにiを追加
while (s < t && a[deq[t - 1]] <= a[i]) t--; deq[t++] = i;
if (i - k + 1 >= 0) {
b[i - k + 1] = a[deq[s]];
if (deq[s] == i - k + 1) { // デックの先頭を取り出す
s++;
} }
}
printf("%d\n",*min_element(b,b+(n-k+1)));
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	scanf("%s",s);
	for(;s[k]=='M';k++);
	solve();
}
