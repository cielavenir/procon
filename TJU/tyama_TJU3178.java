import java.util.*;

class Main{
  public static int banknum(String s)
    {return Integer.parseInt(s.substring(s.lastIndexOf('/')+1));}
  public static int parse(String s)
    {return Integer.parseInt(s.substring(0,s.length()-3)+s.substring(s.length()-2));}
  public static void main(String[]w){
    Scanner cin=new Scanner(System.in);
    String o,a,b,x;
    int n;
    Z:while((n=cin.nextInt())>0){
      Map<String,Integer> m=new HashMap<String,Integer>();
      for(;n>0;n--)m.put(cin.next(),parse(cin.next()));
      for(;;){
        o=cin.next();
        switch(o.charAt(0)){
          case 'e':
          System.out.println("end\n");continue Z;
          case 'c':
          a=cin.next();
          System.out.print("create: ");
          if(m.containsKey(a))
            System.out.println("already exists");
          else{
            m.put(a,0);System.out.println("ok");
          }
          break;
          case 'd':
          a=cin.next();x=cin.next();
          System.out.print("deposit "+x+": ");
          if(m.containsKey(a)){
            m.put(a,m.get(a)+parse(x));
            System.out.println("ok");
          }else
            System.out.println("no such account");
          break;
          case 'w':
          a=cin.next();x=cin.next();
          System.out.print("withdraw "+x+": ");
          if(m.containsKey(a)){
            if(m.get(a)<parse(x))
              System.out.println("insufficient funds");
            else{
              m.put(a,m.get(a)-parse(x));
              System.out.println("ok");
            }
          }else
            System.out.println("no such account");
          break;
          case 't':
          a=cin.next();b=cin.next();x=cin.next();
          System.out.print("transfer "+x+": ");
          if(m.containsKey(a)&&m.containsKey(b)){
            if(a.equals(b))
              System.out.println("same account");
            else if(m.get(a)<parse(x))
              System.out.println("insufficient funds");
            else{
              m.put(a,m.get(a)-parse(x));
              m.put(b,m.get(b)+parse(x));
              System.out.println(banknum(a)==banknum(b)?"ok":"interbank");
            }
          }else
            System.out.println("no such account");
          break;
        }
      }
    }
    System.out.println("goodbye");
  }
}