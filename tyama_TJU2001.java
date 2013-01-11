import java.util.*;
import java.io.*;
class Main{
  public static void main(String[]a){
    BufferedReader b = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer t;
    try{
      int i=1,n=Integer.parseInt(b.readLine());
      for(;i<=n;i++){
        int s=0;
        b.readLine();
        t=new StringTokenizer(b.readLine()," ");
        while(t.hasMoreTokens())
          if(t.nextToken().equals("sheep"))s++;
        System.out.println("Case "+i+": This list contains "+s+" sheep.");
        if(i<n)System.out.println();
      }
    }catch(Exception e){}
  }
}