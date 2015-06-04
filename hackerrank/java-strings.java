import java.util.*;
class Solution{
	public static void main(String[]args){
		Scanner cin=new Scanner(System.in);
		String s=cin.next();
		ArrayList<String>arr=new ArrayList<String>();
		int n=cin.nextInt();
		for(int i=0;i<=s.length()-n;i++)arr.add(s.substring(i,i+n));
		Collections.sort(arr);
		System.out.println(arr.get(0));
		System.out.println(arr.get(arr.size()-1));
	}
}