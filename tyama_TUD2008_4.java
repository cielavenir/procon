import java.util.*;
import java.math.*;
class Main{
  public static String reverse(String s){
    return new StringBuilder(s).reverse().toString();
  }
  public static void main(String[]z){
    int I=0,N,b,i,l,r;
    BigInteger s,e;
    Scanner cin=new Scanner(System.in);
    for(N=cin.nextInt();I<N;I++){
      b=cin.nextInt();l=cin.nextInt();
      s=cin.nextBigInteger(b);e=cin.nextBigInteger(b);
      r=0;
      NEXT: for(;s.compareTo(e) <= 0;s=s.add(BigInteger.ONE)){
        String st1=s.toString(b),st2;
        if(st1.equals(reverse(st1))){continue NEXT;}
        for(i=0;i<l;i++){
          st2=reverse(st1);
          st1=new BigInteger(st1,b).add(new BigInteger(st2,b)).toString(b);
          if(st1.equals(reverse(st1))){continue NEXT;}
        }
        r++;
      }
      //System.out.println("Scenario "+(I+1)+":");
      System.out.println(r);
    }
  }
}