import java.util.*;
enum Main{A;
  {
     Scanner x=new Scanner(System.in);
     while(true){
       String s=x.nextLine();
       if(s.equals("-"))break;
       System.out.println(x.nextLine().matches(s) ? "Yes" : "No");
     }
  }
}