import java.util.*;
class Main{
  public static void main(String[]z){
    Scanner x=new Scanner(System.in);
    while(x.hasNext()){
      System.out.println(Integer.toString(x.nextInt(9)+x.nextInt(9),9));
    }
  }
}