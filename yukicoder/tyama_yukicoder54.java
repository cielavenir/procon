import java.util.*;
import java.util.AbstractMap.SimpleEntry;
class Main{
	public static void main(String[]args){
		Scanner cin=new Scanner(System.in);
		int n=cin.nextInt(),vmax=0,tmax=0;
		List<SimpleEntry<Integer,Integer>> v=new ArrayList<>();
		for(int i=0;i<n;i++){
			int a=cin.nextInt(),b=cin.nextInt();
			v.add(new SimpleEntry<>(a,b));
			if(vmax<a)vmax=a;
			if(tmax<b)tmax=b;
		}
		Collections.sort(v,
			(x,y) -> new Integer(x.getKey()+x.getValue()).compareTo(y.getKey()+y.getValue())
			/*new PairComparator<Integer,Integer>()*/
		);
		int[] bag=new int[tmax+vmax+1];
		bag[0]=1;
		for(int i=0;i<n;i++){
			for(int j=v.get(i).getValue()-1;j>=0;j--)bag[j+v.get(i).getKey()]|=bag[j];
		}
		for(int i=tmax+vmax;i>=0;i--)if(bag[i]>0){
			System.out.println(i);
			break;
		}
	}
}
/*
class PairComparator<T extends Comparable<? super T>,S extends Comparable<? super S>>
implements Comparator<Pair<T,S>>{
	@Override
	public int compare(Pair<T,S> arg0, Pair<T,S> arg1) {
		int c=arg0.getKey().compareTo(arg1.getKey());
		if(c!=0)return c;
		return arg0.getValue().compareTo(arg1.getValue());
	}
}
*/
