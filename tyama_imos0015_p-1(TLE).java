import java.util.*;
import java.math.BigInteger;

class Main{
  final int IN_MAX=31622777;
  final int PRIME=1952000;
  byte table[];
  int prime[];

  void Run(){
    int i=3,j,k=1;
    table=new byte[IN_MAX+1];
    prime=new int[PRIME];
    prime[0]=2;
    for(;i<=IN_MAX;i+=2)
      if(table[i]==0){
        prime[k++]=i;
        for(j=i*2;j<=IN_MAX;j+=i)
          table[j]=1;
      }

    Scanner s=new Scanner(System.in);
    BigInteger n,x,g,three=new BigInteger("3");
    for(;(n=s.nextBigInteger()).compareTo(BigInteger.ZERO)!=0;){
      x=three;
      for(i=0;i<PRIME;i++){
        x=x.modPow(new BigInteger(new Integer(prime[i]).toString()),n);
        g=n.gcd(x.subtract(BigInteger.ONE));
        if(g.compareTo(BigInteger.ONE)>0){
          x=n.divide(g);
          System.out.println(g.compareTo(x)<0?g:x);
          break;
        }
      }
    }
  }

  public static void main(String[]z){
    new Main().Run();
  }
}