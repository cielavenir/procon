import java.util.*;
class Solution {
	public static void main(String[] args) {
		Scanner cin=new Scanner(System.in);
		int n=cin.nextInt(),m=cin.nextInt();
		BitSet[] b={new BitSet(n),new BitSet(n)};
		for(int i=0;i<m;i++){
			String s=cin.next();
			int x=cin.nextInt(),y=cin.nextInt();
			if(s.equals("AND")){
				b[x-1].and(b[y-1]);
			}else if(s.equals("OR")){
				b[x-1].or(b[y-1]);
			}else if(s.equals("XOR")){
				b[x-1].xor(b[y-1]);
			}else if(s.equals("FLIP")){
				b[x-1].flip(y);
			}else if(s.equals("SET")){
				b[x-1].set(y);
			}
			System.out.println(b[0].cardinality()+" "+b[1].cardinality());
		}
	}
}