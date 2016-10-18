main(){
  char s[80],d[80],*p;
  gets(d);
  for(;gets(s);){
   p=strtok(s,d);
    puts(p);
    for(;p=strtok(0,d);)
    puts(p);
    puts("END");
  }
}