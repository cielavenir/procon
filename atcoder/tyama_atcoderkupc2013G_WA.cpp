#include <algorithm>
#include <vector>
int C[40][40],B[40][40],M[40][40],m,z;
main(){
	int N=4;
	std::vector<int>v;
	int I,J,i,j;
	for(i=0;i<N;i++)v.push_back(i);
	do{
		for(I=0;I<1<<N;I++)for(J=0;J<1<<N;J++){
			for(i=0;i<N;i++)for(j=i+1;j<N;j++)C[v[i]][v[j]]=C[v[j]][v[i]]=(I&(1<<v[i]))&&(J&(1<<v[j]));
			memset(B,0,sizeof(B));
			for(z=i=0;i<N;i++){
				for(j=0;j<N;j++){
					if(C[v[i]][v[j]]&&v[i]<v[j]){
						if(B[v[j]][v[i]])goto next;
						B[v[i]][v[j]]=1,z++;
					}
				}
			}
			if(m<z)m=z,memcpy(M,C,sizeof(M));
			next:;
		}
	}while(std::next_permutation(v.begin(),v.end()));
	printf("%d\n",N);
	for(i=0;i<N;i++,puts(""))for(j=0;j<N;j++)putchar(M[i][j]?'Y':'N');
}