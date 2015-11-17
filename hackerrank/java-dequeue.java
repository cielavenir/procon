import java.util.*;
class test{
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		Deque q=new ArrayDeque<Integer>();
		int []a=new int[10000001];
		int i=0,n=in.nextInt(),m=in.nextInt();
		int r=0,c=0;
		for(;i<m;i++){
			int x=in.nextInt();
			if(a[x]==0){c++;if(r<c)r=c;}
			a[x]++;
			q.addLast(x);
		}
		for(;i<n;i++){
			if(a[(int)q.getFirst()]==1)c--;
			a[(int)q.getFirst()]--;
			q.removeFirst();
			int x=in.nextInt();
			if(a[x]==0){c++;if(r<c)r=c;}
			a[x]++;
			q.addLast(x);
		}
		System.out.println(r);
	}
}