import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
import java.lang.reflect.*;

import static java.lang.System.in;
class Prime{
	boolean chk(int n){
		if(n<2)return false;
		for(int i=2;i*i<=n;i++)if(n%i==0)return false;
		return true;
	}
	void checkPrime(Integer... a){
		boolean f=false;
		for(int i=0;i<a.length;i++){
			if(chk(a[i])){
				if(f)java.lang.System.out.print(" ");
				f=true;
				java.lang.System.out.print(a[i]);
			}
		}
		java.lang.System.out.println();
	}
}

class Solution{
	public static void main(String[] args){
		try{
		BufferedReader br=new BufferedReader(new InputStreamReader(in));
		int n1=Integer.parseInt(br.readLine());
		int n2=Integer.parseInt(br.readLine());
		int n3=Integer.parseInt(br.readLine());
		int n4=Integer.parseInt(br.readLine());
		int n5=Integer.parseInt(br.readLine());
		Prime ob=new Prime();
		ob.checkPrime(n1);
		ob.checkPrime(n1,n2);
		ob.checkPrime(n1,n2,n3);
		ob.checkPrime(n1,n2,n3,n4,n5);	
		Method[] methods=Prime.class.getDeclaredMethods();
		Set<String> set=new HashSet<>();
		boolean overload=false;
		for(int i=0;i<methods.length;i++){
			if(set.contains(methods[i].getName())){
				overload=true;
				break;
			}
			set.add(methods[i].getName());
		}
		if(overload){
			throw new Exception("Overloading not allowed");
		}
		}catch(Exception e){
			System.out.println(e);
		}
	}	
}

//Prime cracker solution - passes 100% of test cases
