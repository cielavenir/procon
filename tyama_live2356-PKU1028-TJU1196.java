import java.util.*;
class Main{
  public static void main(String[]a){
    Scanner cin=new Scanner(System.in);
//for(int t=cin.nextInt();t>0;t--){
    ArrayList<String> list=new ArrayList<String>();
    list.add("http://www.acm.org/");
    String s;
    int i=0;
    while(true){
      s=cin.next();
      if(s.equals("QUIT"))break;
      if(s.equals("FORWARD")){
        if(i==list.size()-1){System.out.println("Ignored");continue;}
        i++;
        System.out.println(list.get(i));
      }
      if(s.equals("BACK")){
        if(i==0){System.out.println("Ignored");continue;}
        i--;
        System.out.println(list.get(i));
      }
      if(s.equals("VISIT")){
        i++;
        while(list.size()>i)list.remove(i);
        list.add(cin.next());
        System.out.println(list.get(i));
      }
    }
//if(t>1)System.out.println();
//}
  }
}