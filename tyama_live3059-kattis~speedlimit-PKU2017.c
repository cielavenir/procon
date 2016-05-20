#include <stdio.h>
int main(){
	int n=0;
	for(;scanf("%d",&n),~n;){
		int i=0,before=0,total=0,a,b;
		for(;i<n;i++){
			scanf("%d%d",&a,&b);
			b=b-before;
			before=before+b;
			total=total+a*b;
		}
		printf("%d miles\n",total);
	}
	return 0;
}