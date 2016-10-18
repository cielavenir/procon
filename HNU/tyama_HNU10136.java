import java.util.*;
class Main{
  public static void main(String[]z){
    String a,b;
    Scanner x=new Scanner(System.in);
    while(x.hasNext()){
      a=x.nextLine().toLowerCase();
      System.out.println(a.equals(new StringBuffer(a).reverse().toString())?"yes":"no");
    }
  }
}