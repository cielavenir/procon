import java.io.*;
import java.util.*;
class Main{
  public static int gcd(int x,int y){if(x>y)return gcd2(y,x);return gcd2(x,y);}
  public static int gcd2(int x,int y){if(y>0)return gcd2(y,x%y);return x;}

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
    }catch(Exception e){}
  }
}