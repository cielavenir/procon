import java.io.*;
import java.util.regex.*;
class Main{
	public static void main(String[]args){
		try{
			Pattern pat=Pattern.compile("A.*?Z");
			Matcher mat=pat.matcher(new BufferedReader(new InputStreamReader(System.in)).readLine());
			boolean f=false;
			for(;mat.find();){
				f=true;
				System.out.print("AZ");
			}
			System.out.println(f?"":"-1");
		}catch(IOException e){}
	}
}