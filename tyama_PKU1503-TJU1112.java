import java.util.*;import java.math.*;enum Main{A;{
  Scanner x=new Scanner(System.in);
  BigInteger b=x.nextBigInteger();
  while(x.hasNext())b=b.add(x.nextBigInteger());
  System.out.println(b);
}}