import java.util.*;
class Main{
  public static void main(String []args){
    String table="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    Scanner cin=new Scanner(System.in);
    int c=21,i;

    while(cin.hasNext()){
      String s=cin.nextLine();
      if(s.equals("ENDOFINPUT"))return;
      s=cin.nextLine();
      char []p=s.toCharArray();
      for(i=0;i<s.length();i++)
        if(table.indexOf(p[i])!=-1)p[i]=table.charAt( (table.indexOf(p[i])+c)%table.length() );
      System.out.println(p);
      cin.nextLine();
    }
  }
}