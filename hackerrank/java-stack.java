import java.util.*;
class Solution{
	static Map<Character,Character> tbl;
	static boolean solve(String s){
		Stack<Character> arr=new Stack<Character>();
		for(int i=0;i<s.length();i++){
			if(tbl.containsKey(s.charAt(i)))arr.push(s.charAt(i));
			else if(arr.empty() || tbl.get(arr.pop())!=s.charAt(i))return false;
		}
		return arr.empty();
	}
	public static void main(String[]args){
		tbl=new HashMap<Character,Character>();
		tbl.put('[',']');
		tbl.put('{','}');
		tbl.put('(',')');
		Scanner cin=new Scanner(System.in);
		for(;cin.hasNext();){
			System.out.println(solve(cin.nextLine()));
		}
	}
}