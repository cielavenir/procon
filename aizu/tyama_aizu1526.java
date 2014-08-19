import java.util.*;
import java.util.regex.*;

class Main{
	public static void main(String[]z){
		Scanner cin=new Scanner(System.in);
		String s=cin.next();
		String t=cin.next().replaceAll("_",".");
		Matcher m=Pattern.compile(t).matcher(s);
		System.out.println(m.find()?"Yes":"No");
	}
}