import java.util.*;
import java.math.*;
enum Main{A;
  public void print(BigInteger b){
    if(b.compareTo(BigInteger.ZERO)>=0)System.out.print("+");
    System.out.print(b.toString(16).toUpperCase());
  }

  {
    Scanner x=new Scanner(System.in);
    while(true){
      BigInteger a=new Scanner(x.next()).useRadix(16).useDelimiter("\\+").nextBigInteger();
      BigInteger b=new Scanner(x.next()).useRadix(16).useDelimiter("\\+").nextBigInteger();
      if(a.compareTo(BigInteger.ZERO)==0&&b.compareTo(BigInteger.ZERO)==0)break;
      if(a.compareTo(b)<0){
        print(a);System.out.print(" ");print(b);System.out.println();
      }else{
        print(b);System.out.print(" ");print(a);System.out.println();
      }
      print(a.add(b));
      System.out.println();
    }
  }
}