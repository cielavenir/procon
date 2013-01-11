import java.util.*;
import java.io.*;
enum Main{A;
  public String reverse(String s){return new StringBuffer(s).reverse().toString();}
  {
    BufferedReader b = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer t;
    try{
      int i=0,n=Integer.parseInt(b.readLine());
      for(;i<n;i++){
        boolean first=true;
        t=new StringTokenizer(b.readLine()," ");
        while(t.hasMoreTokens()){
          if(!first)System.out.print(" ");
          first=false;
          System.out.print(reverse(t.nextToken()));
        }
        System.out.println();
      }
    }catch(Exception e){}
  }
}