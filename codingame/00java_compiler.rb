#!/usr/bin/ruby
puts <<EOM
import java.util.Scanner;
import java.io.*;
class Solution{
	static final int SIZE=9999999;
	static byte[] z=new byte[SIZE];

	public static void main(String[]args){try{
EOM

print "		Process p=Runtime.getRuntime().exec(new String[]{\"ruby\",\"-e\",\""
$<.each{|e|
	l=e.strip
	break if l=='__END__'
	print l.gsub('"','\"').gsub("'",'\"')+';' if !l.start_with?('#')
}
puts "\"});"

puts <<EOM
		p.getOutputStream().write(z,0,System.in.read(z,0,SIZE));
		p.getOutputStream().close();
		Scanner sc=new Scanner(p.getInputStream());
		for(;sc.hasNext();)System.out.println(sc.nextLine());
	}catch(IOException e){
		System.out.println(e.getMessage());
	}}
}
EOM