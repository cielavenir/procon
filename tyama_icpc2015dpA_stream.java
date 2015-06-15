import java.util.Scanner;
import java.util.stream.*;
class Main{public static void main(String[]args){
	Scanner cin=new Scanner(System.in);
	for(;;){
		final int a=cin.nextInt();
		final int b=cin.nextInt();
		if(a==0)break;
		System.out.println(IntStream.range(0,a/2+1).asDoubleStream().map(i->Math.abs(b-Math.hypot(i,a-i))).min().getAsDouble());
	}
}}