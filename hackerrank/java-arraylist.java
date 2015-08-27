import java.util.*;
class Solution{
	public static void main(String[]args){
		Scanner cin=new Scanner(System.in);
		int N=Integer.parseInt(cin.next());
		ArrayList<ArrayList<Integer>> m=new ArrayList<ArrayList<Integer>>();
		for(int n=0;n<N;n++){
			int D=Integer.parseInt(cin.next());
			m.add(new ArrayList<Integer>());
			for(int d=0;d<D;d++){
				int x=Integer.parseInt(cin.next());;
				m.get(n).add(x);
			}
		}
		int Q=Integer.parseInt(cin.next());
		for(int q=0;q<Q;q++){
			int x=Integer.parseInt(cin.next()),y=Integer.parseInt(cin.next());
			if(x>m.size()||y>m.get(x-1).size())System.out.println("ERROR!");
			else System.out.println(m.get(x-1).get(y-1));
		}
	}
}