import java.util.*;
import java.math.*;
import javafx.util.Pair;

class Solution{
	public static void main(String[] args){
		Scanner cin=new Scanner(System.in);
		int T=cin.nextInt();
		ArrayList<Pair<BigDecimal,String> > a=new ArrayList<Pair<BigDecimal,String> >();
		for(int i=0;i<T;i++){
			String s=cin.next();
			a.add(new Pair<BigDecimal,String>(new BigDecimal(s),s));
		}
		Collections.sort(a,(x,y)->x.getKey().compareTo(y.getKey()));
		for(int i=T-1;i>=0;i--)System.out.println(a.get(i).getValue());
	}
}