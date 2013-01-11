import java.util.*;
class Main{
  public static void main(String[]z){
    String table="ABCDEFGHIJKLMNOPQRSTUVWXYZ";int c=21;
    Scanner cin=new Scanner(System.in);
    String x,s;
    while(!(x=cin.nextLine()).equals("ENDOFINPUT")){
      s=cin.nextLine();
      char []p=s.toCharArray();
      int i=0;
      for(;i<s.length();i++)
        if(table.indexOf(p[i])!=-1)p[i]=table.charAt( (table.indexOf(p[i])+c)%table.length() );
      System.out.println(new String(p));
      cin.nextLine();
    }
  }
}