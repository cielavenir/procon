import java.util.*;
class Main{
  public static void main(String[]z){
    Scanner cin=new Scanner(System.in);
    int n=cin.nextInt(),x;cin.nextLine();
    for(;n>0;n--){
      try{
        String s=cin.nextLine().trim();
        Double.parseDouble(s);
        if(s.charAt(s.length()-1)=='.'||s.charAt(0)=='.'||s.charAt(s.indexOf('.')+1)=='e'||s.charAt(s.indexOf('.')+1)=='E')throw new Exception();
      }catch(Exception e){System.out.print("IL");}
      System.out.println("LEGAL");
    }
  }
}