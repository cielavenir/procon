import java.io.*;
import java.util.*;
class Main{
  public static int gcd(int x,int y){return y>0 ? gcd(y,x%y) : x;}

  public static void main(String[]a){
    BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer token;
    int n,l,x;
    try{
      n=Integer.parseInt(br.readLine());
      for(;n>0;n--){
        l=1;
        token=new StringTokenizer(br.readLine()," ");
        while(token.hasMoreTokens()){
          x=Integer.parseInt(token.nextToken());
          l=l/gcd(l,x)*x;
        }
        System.out.println(l);
      }
    }catch(IOException e){}
  }
}