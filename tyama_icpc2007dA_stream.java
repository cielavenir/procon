//usr/bin/env java $0 $@;exit
import java.util.*;
import java.util.stream.*;
class Main{
	public static void main(String[]z){
		Scanner c=new Scanner(System.in);
		for(int n;(n=c.nextInt())>0;)System.out.println((int)IntStream.range(0,n).map(e->c.nextInt()).sorted().skip(1).limit(n-2).average().getAsDouble());
	}
}
