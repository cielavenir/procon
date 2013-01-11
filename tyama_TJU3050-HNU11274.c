/* change strrchr to strchr / -= to += for encryption */
main(i){
  char c,*p;
  while((c=getchar())!='#'){
    if(c=='\n'){puts("");i=1;continue;}
    p=strrchr("ABCABCDEFDEFGHIGHIJKLJKLMNOMNOPQRSPQRSTUVTUVWXYZWXYZabcabcdefdefghighijkljklmnomnopqrspqrstuvtuvwxyzwxyz",c);
    p-=i%(strchr("PQRSWXYZpqrswxyz",c)?4:3);
    printf("%c",*p);
    i++;
  }
}