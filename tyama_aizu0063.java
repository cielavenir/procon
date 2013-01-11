import java.util.*;
class Main{
  public static void main(String[]z){
    Scanner x=new Scanner(System.in);
    int i=0;
    while(x.hasNext()){
      String s=x.nextLine();
      if(s.equals(new StringBuilder(s).reverse().toString()))i++;
    }
    System.out.println(i);
  }
}