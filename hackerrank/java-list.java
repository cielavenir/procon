import java.util.*;
class Solution {
	public static void main(String[] args) {
		Scanner cin=new Scanner(System.in);
		int n=cin.nextInt();
		List l=new ArrayList();
		for(int i=0;i<n;i++)l.add(cin.nextInt());
		n=cin.nextInt();
		for(int i=0;i<n;i++){
			String s=cin.next();
			if(s.equals("Insert")){
				int x=cin.nextInt(),y=cin.nextInt();
				l.add(x,y);
			}else{
				int x=cin.nextInt();
				l.remove(x);
			}
		}
		for(int i=0;i<l.size();i++)System.out.print(l.get(i)+" ");
	}
}