/*
tyama070604bicolor.c

チームについて:私は足を引っ張ること請け合いなんですが(^^;大会どうでもいい人集まれw
私なんてレポートに追われつつもiPodLinuxとRockboxで遊んでる人なんでw
というかiPodLinuxが原因でiPodをリストア…それも二回目w
最近はGnuDIP2のPerlクライアント書いてたりもしましたw

ちなみに今週はこれ以外の提出は予定していません(何

というかアルゴリズムの解説書きすぎるとプレゼンがしにくくなる希ガス (^^ゞ
#やっぱり下を向き続けるのはイクナイw
まあ今回はそれほどしにくくなることもないでしょうがwww

あと、これはPG.comでは通りますがUVaでは弾かれました
*/

#include <stdio.h>
#include <string.h>

#define hi(x) ((x)>>16)
#define lo(x) ((x)&0xffff)

int check[200]; //やっぱりmallocはやめて固定しよう。∴vertexは不要。

int solve(/*int vertex,*/ /*int siz,*/ int *edges){ //char*じゃないのはhiとloを使うためw
  int i=0, x, y;
  memset(check, 0, /*vertex*/sizeof(check)); //やっぱりこれはロスかなぁ
  for(;/*i<siz*/edges[i];i++){
    x=hi(edges[i]); y=lo(edges[i]);
	if(!check[x]&&!check[y])
	  check[x]=1,check[y]=2;
	else if(!check[x])
	  check[x] = check[y]==1 ? 2 : 1;
	else if(!check[y])
	  check[y] = check[x]==1 ? 2 : 1;
	else if(check[x]==check[y]) //既存のedgeをつなぐ入力はあることが非常にうけるw
	  break; //「後で」つながるなんてことはないと仮定します。さらにその仮定は正しいw
  }
  return /*i==siz;*/ !edges[i];
}

int main(){
  int /*vertex,*/ siz, edges[200]; //適当に固定するのが高速化の戦略w //解析により最大edge数は198と定まりましたw
  int i, x, y;
  
  while(1){
    scanf("%d", /*&vertex*/&i);
	if(/*!vertex*/!i)return 0;
	scanf("%d", &siz);

	for(i=0; i<siz; i++){
	  scanf("%d %d", &x, &y); //edges[i]のhiとloをうまく指定すればさらに高速化できるか
	  edges[i]=(x<<16)+y;
	}
	edges[i]=0;
	printf(solve(/*vertex,*/ /*siz,*/ edges) ? "BICOLORABLE.\n" : "NOT BICOLORABLE.\n");
  }
}