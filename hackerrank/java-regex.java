import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.Scanner;

class Solution{
	public static void main(String []args){
		Scanner in = new Scanner(System.in);
		while(in.hasNext()){
			String IP = in.next();
			System.out.println(IP.matches(new myRegex().pattern));
		}
	}
}

class myRegex{
	String pattern="(\\d{1,2}|[01]\\d{2}|2[0-5]\\d)\\.(\\d{1,2}|[01]\\d{2}|2[0-5]\\d)\\.(\\d{1,2}|[01]\\d{2}|2[0-5]\\d)\\.(\\d{1,2}|[01]\\d{2}|2[0-5]\\d)";
}