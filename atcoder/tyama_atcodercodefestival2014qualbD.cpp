#include <stack>
#include <cstdio>
int H[100002],D1[100002],D2[100002];
int main(){
	int n,i,j,r;
	scanf("%d",&n);
	H[0]=H[n+1]=9999999;
	for(i=1;i<=n;i++)scanf("%d",H+i);
	{
		std::stack<int> st;
		st.push(0);
		for(i=1;i<=n;i++){
			for(;H[i]>=H[st.top()];)st.pop();
			D1[i]=st.top();
			st.push(i);
		}
	}
	{
		std::stack<int> st;
		st.push(n+1);
		for(i=n;i>=1;i--){
			for(;H[i]>=H[st.top()];)st.pop();
			D2[i]=st.top();
			st.push(i);
		}
	}
	for(i=1;i<=n;i++){
		printf("%d\n",D2[i]-D1[i]-2);
	}
	return 0;
}