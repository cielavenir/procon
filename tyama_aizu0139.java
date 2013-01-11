import java.util.*;
class Main{
  public static void main(String[]z){
    Scanner x=new Scanner(System.in);
    String s=x.nextLine();
    while(x.hasNext()){
      s=x.nextLine();
      if(s.matches(">'(=+)#\\1~"))System.out.println("A");
      else if(s.matches(">\\^(Q=)+~~"))System.out.println("B");
      else System.out.println("NA");
    }
  }
}