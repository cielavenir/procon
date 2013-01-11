import java.util.*;
class Main{
	public static void main(String[]z){
		Scanner c=new Scanner(System.in);
		int i,n,s;
		for(;(n=c.nextInt())>0;System.out.println(s/(n-2))){
			List<Integer> l=new ArrayList<Integer>();
			for(s=i=0;i<n;i++)l.add(c.nextInt());
			Collections.sort(l);
			l.remove(n-1);l.remove(0);
			for(int x:l)s+=x;
		}
	}
}