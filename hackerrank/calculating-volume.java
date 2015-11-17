import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
import java.lang.reflect.*;
import java.security.Permission;

class Volume{
	int main(int a){return a*a*a;}
	int main(int a,int b,int c){return a*b*c;}
	double main(double a){return Math.PI*a*a*a*2/3;}
	double main(double a,double b){return b*Math.PI*a*a;}
}
class Display{
	void display(double x){System.out.printf("%.3f\n",x);}
}
class Calculate{
	Scanner cin;
	Display output;
	Calculate() throws IOException{cin=new Scanner(System.in);output=new Display();if(cin==null)throw new IOException("dummy");}
	int getINTVal(){int x=cin.nextInt();if(x<=0)throw new NumberFormatException("All the values must be positive");return x;}
	double getDoubleVal(){double x=cin.nextDouble();if(x<=0)throw new NumberFormatException("All the values must be positive");return x;}
	static Volume get_Vol(){return new Volume();}
}

class Solution{
	public static void main(String[] args){
		Do_Not_Terminate.forbidExit();		
		try{
			Calculate cal=new Calculate();
			int T=cal.getINTVal();
			while(T-->0){
			double volume = 0.0d;		
			int ch=cal.getINTVal();			
			if(ch==1){
				int a=cal.getINTVal();
				volume=Calculate.get_Vol().main(a);
			}else if(ch==2){
				int l=cal.getINTVal();
				int b=cal.getINTVal();
				int h=cal.getINTVal();
				volume=Calculate.get_Vol().main(l,b,h);
			}else if(ch==3){
				double r=cal.getDoubleVal();
				volume=Calculate.get_Vol().main(r);
			}else if(ch==4){
				double r=cal.getDoubleVal();
				double h=cal.getDoubleVal();
				volume=Calculate.get_Vol().main(r,h);
			}
			cal.output.display(volume);
			}
		}
		catch (NumberFormatException e) {
			System.out.print(e);
		} catch (IOException e) {
			e.printStackTrace();
		}
		catch (Do_Not_Terminate.ExitTrappedException e) {
			System.out.println("Unsuccessful Termination!!");
		}
	}
}
/**
 *This class prevents the user from using System.exit(0)
 * from terminating the program abnormally.
 */
class Do_Not_Terminate {
	public static class ExitTrappedException extends SecurityException {}
 
	public static void forbidExit() {
		final SecurityManager securityManager = new SecurityManager() {
			@Override
			public void checkPermission(Permission permission) {
				if (permission.getName().contains("exitVM")) {
					throw new ExitTrappedException();
				}
			}
		};
		System.setSecurityManager(securityManager);
	}
}