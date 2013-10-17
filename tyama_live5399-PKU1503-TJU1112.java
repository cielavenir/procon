import java.util.*;import java.math.*;enum Main{A;{
  Scanner x=new Scanner(System.in);
  BigInteger b=BigInteger.ZERO,n=x.nextBigInteger();
  for(;!n.equals(BigInteger.ZERO);n=x.nextBigInteger())b=b.add(n);
  System.out.println(b);
}}