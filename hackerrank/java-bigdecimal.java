import java.util.*;
import java.math.*;

class Solution{
	public static void main(String[] args){
		Scanner cin=new Scanner(System.in);
		int T=cin.nextInt();
		ArrayList<javafx.util.Pair<BigDecimal,String> > a=new ArrayList<javafx.util.Pair<BigDecimal,String> >();
		for(int i=0;i<T;i++){
			String s=cin.next();
			a.add(new javafx.util.Pair<BigDecimal,String>(new BigDecimal(s),s));
		}
		Collections.sort(a,(x,y)->-x.getKey().compareTo(y.getKey()));
		for(int i=0;i<T;i++)System.out.println(a.get(i).getValue());
	}
}
