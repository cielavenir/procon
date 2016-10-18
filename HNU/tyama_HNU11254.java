import java.util.*;
import java.util.regex.*;
enum Main{A;public static void main(String[]s){
  Scanner cin=new Scanner(System.in);
  int i=Integer.parseInt(cin.nextLine());
  for(;i>0;i--){
    cin.nextLine();
    Matcher m=Pattern.compile("(.+) \\+ (.+) = (.+)").matcher(cin.nextLine());
    m.matches();
    if(m.group(1).indexOf("machula")!=-1)
      System.out.println((Integer.parseInt(m.group(3))-Integer.parseInt(m.group(2)))+" + "+m.group(2)+" = "+m.group(3));
    else if(m.group(2).indexOf("machula")!=-1)
      System.out.println(m.group(1)+" + "+(Integer.parseInt(m.group(3))-Integer.parseInt(m.group(1)))+" = "+m.group(3));
    else
      System.out.println(m.group(1)+" + "+m.group(2)+" = "+(Integer.parseInt(m.group(1))+Integer.parseInt(m.group(2))));
  }
}}