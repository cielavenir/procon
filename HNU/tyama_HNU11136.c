char *t="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void b64(){
  int x=0,o=0,c;
  while((c=getchar())!='\n'){
    x=(x<<8)+c;
    o++;
    if(o==3){
      printf("%c%c%c%c",t[(x>>18)&0x3f],t[(x>>12)&0x3f],t[(x>>6)&0x3f],t[x&0x3f]);o=0;
    }
  }
  if(o==1)printf("%c%c==",t[(x>>2)&0x3f],t[(x&0x3)<<4]);
  if(o==2)printf("%c%c%c=",t[(x>>10)&0x3f],t[(x>>4)&0x3f],t[(x&0xf)<<2]);
  puts("");
}

int main(){
  int n;
  scanf("%d",&n);
  getchar();
  for(;n;n--)b64();
}