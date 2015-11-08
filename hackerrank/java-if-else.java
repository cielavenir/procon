import java.util.*;
class Solution{
	public static void main(String[]args){
		Scanner cin=new Scanner(System.in);
		int n=cin.nextInt();
		System.out.println(n%2==1||(6<=n&&n<=20) ? "Weird" : "Not Weird");
	}
}