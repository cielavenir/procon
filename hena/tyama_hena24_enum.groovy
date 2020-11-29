#!/usr/bin/env groovy

// http://qiita.com/Nabetani/items/1c83005a854d2c6cbb69
// http://nabetani.sakura.ne.jp/hena/ord24eliseq/
import java.util.Map;
import java.util.HashMap;
import java.util.Scanner;
import java.util.Iterator;
import java.util.function.Function;
import java.util.function.BiFunction;

class Hena24{
	static int isqrt(int n){
		if(n<=0)return 0;
		if(n<4)return 1;
		int x=0,y=n;
		for(;x!=y&&x+1!=y;){x=y;y=(n/y+y)/2;}
		return x;
	}
	static int icbrt(int n){
		if(n<0)return -icbrt(-n);
		if(n==0)return 0;
		if(n<8)return 1;
		int x=0,y=n;
		for(;x!=y&&x+1!=y;){x=y;y=(n/y/y+y*2)/3;}
		return x;
	}
	class generate implements Iterator<Integer>{
		int i=0;
		public boolean hasNext(){return true;}
		public Integer next(){
			i+=1;
			return i;
		}
	}
	class drop_prev implements Iterator<Integer>{
		Iterator<Integer> prev;
		Function<Integer,Boolean> check;
		int a=0;
		int b=0;
		drop_prev(Function<Integer,Boolean> check_, Iterator<Integer> prev_){
			check = check_;
			prev = prev_;
			b = prev.next();
		}
		public boolean hasNext(){return true;}
		public Integer next(){
			for(;;){
				a = b;
				b = prev.next();
				if(!check.apply(b)){
					return a;
				}
			}
		}
	}
	class drop_next implements Iterator<Integer>{
		Iterator<Integer> prev;
		Function<Integer,Boolean> check;
		boolean first = true;
		int a=0;
		int b=0;
		drop_next(Function<Integer,Boolean> check_, Iterator<Integer> prev_){
			check = check_;
			prev = prev_;
		}
		public boolean hasNext(){return true;}
		public Integer next(){
			for(;;){
				a = b;
				b = prev.next();
				if(first||!check.apply(a)){
					first = false;
					return b;
				}
			}
		}
	}
	class drop_n implements Iterator<Integer>{
		Iterator<Integer> prev;
		BiFunction<Integer,Integer,Boolean> check;
		int n=0;
		int i=0;
		drop_n(BiFunction<Integer,Integer,Boolean> check_, int n_, Iterator<Integer> prev_){
			check = check_;
			prev = prev_;
			n = n_;
		}
		public boolean hasNext(){return true;}
		public Integer next(){
			for(;;){
				i++;
				int a = prev.next();
				if(!check.apply(i,n)){
					return a;
				}
			}
		}
	}
	static boolean is_sq(int n){
		int x=isqrt(n);
		return x*x==n;
	}
	static boolean is_cb(int n){
		int x=icbrt(n);
		return x*x*x==n;
	}
	static boolean is_multiple(int i,int n){return i%n==0;}
	static boolean is_le(int i,int n){return i<=n;}

	public void Run(){
		Map<Character,Function<Iterator<Integer>,Iterator<Integer>>> f=[
			('S' as char):(e)->new drop_next(Hena24::is_sq,e),
			('s' as char):(e)->new drop_prev(Hena24::is_sq,e),
			('C' as char):(e)->new drop_next(Hena24::is_cb,e),
			('c' as char):(e)->new drop_prev(Hena24::is_cb,e),
			('h' as char):(e)->new drop_n(Hena24::is_le,100,e),
		] as HashMap
		for(int i=2;i<=9;i++){
			int j=i;
			f.put(String.valueOf(i).charAt(0),(e)->new drop_n(Hena24::is_multiple,j,e));
		}

		Scanner cin = new Scanner(System.in);
		for(;cin.hasNext();){
			String line = cin.nextLine();
			boolean first=true;

			Iterator<Integer> z=new generate();
			for(char e:line.toCharArray()){z=f.get(e)(z);}
			for(int i=0;i<10;i++){
				int n=z.next();
				if(!first)System.out.print(',');
				first=false;
				System.out.print(n);
			}
			System.out.print('\n');
			System.out.flush();
		}
	}
	public static void main(String[]z){new Hena24().Run();}
}
