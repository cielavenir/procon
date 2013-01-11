import java.util.*;
class Main{
  public static String reverse(String s){return new StringBuffer(s).reverse().toString();}
  public static void main(String[]a){
    Scanner cin=new Scanner(System.in);
    int i=0,n=cin.nextInt();
    cin.nextLine();
    for(;i<n;i++)System.out.println(reverse(cin.nextLine()));
  }
}