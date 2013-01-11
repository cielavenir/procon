import java.util.*;
import java.math.*;
enum Main{A;{
  Scanner cin=new Scanner(System.in);
  int n=cin.nextInt(),i=0;
  BigInteger a,b,one=BigInteger.ONE,two=new BigInteger("2");
  while(++i<=n){
    System.out.println("Scenario #"+i+":");
    b=cin.nextBigInteger().subtract(one);a=cin.nextBigInteger();
    System.out.println(a.multiply(a.add(one)).subtract(b.multiply(b.add(one))).divide(two).toString()+"\n");
  }
}}