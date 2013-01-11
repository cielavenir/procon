import java.util.*;
class Main{
  public static void main(String[]z){
    Scanner x=new Scanner(System.in);
    while(x.hasNext()){
      System.out.println(x.nextBigInteger().multiply(x.nextBigInteger()));
    }
  }
}