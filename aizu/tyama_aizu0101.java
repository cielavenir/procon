import java.util.*;
class Main{
  public static void main(String[]z){
    Scanner x=new Scanner(System.in);
    int n=x.nextInt();x.nextLine();
    for(;n>0;n--){
      String s=x.nextLine();
      System.out.println(s.replaceAll("Hoshino","Hoshina"));
    }
  }
}