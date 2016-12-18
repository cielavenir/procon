import java.util.*;
import java.io.*;

class Solution{
   public static void main(String []args)
   {
      HashMap db = new HashMap();
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      sc.nextLine();
      for(int i=0;i<n;i++)
      {
         String name = sc.nextLine();
         int phone = sc.nextInt();
         db.put(name,""+phone);
         sc.nextLine();
      }
      while(sc.hasNext())
      {
         String s=sc.nextLine();
         String phone = (String)db.get(s); 
         System.out.println(phone==null?"Not found":s+"="+phone);
      }
   }
}
