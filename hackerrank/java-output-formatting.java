import java.util.*;

class Solution{
	public static void main(String[] args){
		Scanner cin=new Scanner(System.in);
		System.out.println("================================");
		for(;cin.hasNext();){
			String s=cin.next();
			int a=cin.nextInt();
			System.out.printf("%-15s%03d\n",s,a);
		}
		System.out.println("================================");
	}
}