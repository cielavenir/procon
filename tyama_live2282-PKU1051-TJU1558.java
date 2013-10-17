//without linebreaks/spaces 755Bytes
import java.util.*;
enum Main{A;{
	String[]a={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","_",",",".","?"},b={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","..--",".-.-","---.","----"};
	List<String>ch=Arrays.asList(a),code=Arrays.asList(b);
	Stack<Integer>st=new Stack();
	Scanner cin=new Scanner(System.in);
	int i=0,n=cin.nextInt(),j,k;
	while(i<n){
		String s=cin.next(),t="",d="",x;
		for(k=j=0;j<s.length();j++)
			{x=code.get(ch.indexOf(s.substring(j,j+1)));t+=x;st.push(x.length());}
		while(st.size()>0)
			{j=k;k+=st.pop();d+=ch.get(code.indexOf(t.substring(j,k)));}
		System.out.println(++i+": "+d);
	}
}}