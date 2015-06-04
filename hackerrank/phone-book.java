import java.util.*;
class Solution{
	public static void main(String[]args){
		Map<String,String> se=new HashMap<String,String>();
		Scanner cin=new Scanner(System.in);
		int N=cin.nextInt();cin.nextLine();
		for(;N>0;N--){
			se.put(cin.nextLine(),cin.nextLine());
		}
		for(;cin.hasNext();){
			String s=cin.nextLine();
			if(se.containsKey(s))System.out.println(s+"="+se.get(s));
			else System.out.println("Not found");
		}
	}
}