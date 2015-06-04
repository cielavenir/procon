import java.util.*;
class Solution{
	public static void main(String[]args){
		Set<String> se=new HashSet<String>();
		Scanner cin=new Scanner(System.in);
		for(cin.nextLine();cin.hasNext();){
			se.add(cin.nextLine());
			System.out.println(se.size());
		}
	}
}