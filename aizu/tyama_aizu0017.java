import java.util.*;
class Main{
  public static void main(String []args){
    Scanner x=new Scanner(System.in);
    String table="abcdefghijklmnopqrstuvwxyz";
    loop:while(x.hasNext()){
      String s=x.nextLine();
      int c=0;
      for(;c<table.length();c++){
        char []p=s.toCharArray();
        int i=0;
        for(;i<s.length();i++)
          if(table.indexOf(p[i])!=-1)p[i]=table.charAt( (table.indexOf(p[i])+c)%table.length() );
        String r=new String(p);
        if(r.indexOf("the")!=-1||r.indexOf("this")!=-1||r.indexOf("that")!=-1){
          System.out.println(r);
          continue loop;
        }
      }
    }
  }
}