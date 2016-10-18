/*
RとGとBに分け、それぞれの色の枚数が3の倍数でなかったら0
各色について、
・1の枚数が3以上なら3で割ったあまりにする
∵1の枚数が3というのは、1 1 1のセットと1 2 3の一部という2通りの解釈があるが、
　1 2 3 1 2 3 1 2 3は1 1 1 2 2 2 3 3 3とも解釈できるため1 1 1としてよい。
・それで1の枚数が1か2なら、その分だけ2の枚数および3の枚数から引く->引けなければ0
・以下2-9も同様
∵2が3枚あるのは2 2 2なのか1 2 3の一部なのか2 3 4の一部なのか判断できないが、最初に1 2 3を引けるだけ引いておくことで
　1のときと同様に処理できる
*/

int check(char a[12]){
  int i=1;
  for(;i<10;i++){
    if(a[i]<0)return 0;
    a[i]%=3;
    if(a[i]>0){
      if(a[i+1]-a[i]<0 || a[i+2]-a[i]<0)return 0;
      a[i+1]-=a[i];a[i+2]-=a[i];a[i]=0;
    }
  }
  return 1;
}

int rummy(){
  char x[256][12];
  int hai[9];
  char color[9],c[256];
  int i;

  memset(x['R'],0,sizeof(x['R']));
  memset(x['G'],0,sizeof(x['G']));
  memset(x['B'],0,sizeof(x['B']));
  memset(hai,0,sizeof(hai));
  memset(color,0,sizeof(color));
  memset(c,0,sizeof(c));

  { //input
    for(i=0;i<9;i++)scanf("%d",hai+i); //ghaa! %d cannot be used with char array; hai has to be int array! What a shame!!! Thx K.Inaba.
    for(i=0;i<9;i++)scanf(" %c",color+i);
    for(i=0;i<9;i++){
      x[color[i]][hai[i]]++;
      c[color[i]]++;
    }
    if(c['R']%3!=0 || c['G']%3!=0 || c['B']%3!=0)return 0;
  }

  return check(x['R']) & check(x['G']) & check(x['B']);
}

int main(){
  int i=0,n,x;
  scanf("%d",&n);
  for(;i<n;i++){
    x=rummy();
    printf(x ? "1\n" : "0\n");
  }
  return 0;
}