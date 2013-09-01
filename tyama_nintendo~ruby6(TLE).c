#include <stdio.h>
#define MM 5
#define M 5
int m[MM*MM][MM*MM],f[MM*MM][MM*MM],z[MM*MM];
int grid(int I,int J){
	int i,j,x,y;
	for(j=0;j<M*M;j++)z[j]=0;
	for(j=0;j<M*M;j++)if(m[I][j]!=25&&++z[m[I][j]]>1)return 0;
	for(j=0;j<M*M;j++)z[j]=0;
	for(i=0;i<M*M;i++)if(m[i][J]!=25&&++z[m[i][J]]>1)return 0;
	i=I/M+J/M*M;
	for(j=0;j<M*M;j++)z[j]=0;
	for(j=0;j<M*M;j++)if(m[x=i%M*M+j/M][y=i/M*M+j%M]!=25&&++z[m[x][y]]>1)return 0;
	return 1;
}
int dfs(int n){
	int i,j,k;
	if(n==M*M*M*M){
		for(i=0;i<M*M;i++)for(j=0;j<M*M;j++){
			printf(j==M*M-1?"%c\n":"%c",m[i][j]+'A');
		}
		return 1;
	}
	i=n/(M*M),j=n%(M*M);
	if(!f[i][j])return dfs(n+1);
	for(k=0;k<M*M;k++){
		m[i][j]=k;
		if(grid(i,j))dfs(n+1);//return 1;
	}
	m[i][j]=25;
	return 0;
}
int main(){
	int i,j,n,N,c;
	//scanf("%d",&N);for(;getchar()!='\n';);
	//for(n=1;n<=N;n++){
	//	printf("Scenario #%d:\n",n);
		for(i=0;i<M*M;i++){
			for(j=0;j<M*M;j++){
				m[i][j]=getchar()-'A';
				f[i][j]=m[i][j]==25;
			}
			for(;(c=getchar())!='\n'&&~c;);
		}
		if(!dfs(0))return 1;

	//	puts("");
	//	for(;(c=getchar())!='\n'&&~c;);
	//}
}
/*
input:
AZZPZZTZZZZZZWFZZZOZCZZZE
ZZZXFQBZZZASJZZUYZZLTZZZR
ZJDLUPOCZZKZNZZQHZZZSZZZZ
ZKZZZZZZZZEZBHZTZGZWMZJZZ
ZWZZZZFZZUTYPZZVEMZZZZZQI
ZZZZTZZKVZZZZZZBFOZEZZZXZ
ZXYVMBSZZZUDZZZZZZZZZZZZZ
WZZZZFQZXZZZLZZNRZZYZZZZZ
ZZZSPECZATMKYOZZZZZZJZZVW
ZIZZAMZZZZZZZZZZCVZZZZEZZ
DZNAZZZZZSZUZZZZZZPZVIZHG
ZZZZZLZZZAQPZZVZZZZRZZCZZ
ZZKZZZGBOZZZZZZZMNHULZZZZ
FZUZHZZTQYJZZCAIVZZZZDZKB
ZQZZZZZZHPOZZRZWGTCSZMUNY
MATZZJPZLZHZZZZZQWZZZNZRZ
RZZJSZZYZCZQZEZZZUZHZZZZZ
IFCZZTZEZZZZKMRPZZZZZZZOH
QZZDZVZINZBZXSOYZAEZZZGZT
BLEOVZZSZZZZZYUJTZKZZZWPX
YDFKCWZAZIZZZZZMZZZGNEZUP
GZZZQZUZZZNZZZZZZLZZZZYZZ
XMZWZZZFZKZZZZZZZZZZDZZZZ
ZEZIZZZZRDZHZZZOZZZAGJBZK
SZPZBZZNZZZGZUZZKCZZZARIZ
*/