#!/usr/bin/ruby
load File.expand_path(File.dirname(__FILE__))+'/000.rb'
puts <<EOM
import java.util.Scanner;
import java.io.*;
class Solution{
	static final int SIZE=9999999;
	static byte[] z=new byte[SIZE];

	public static void main(String[]args){try{
EOM

print "		Process p=Runtime.getRuntime().exec(new String[]{\"#{COMMAND}\",\"-e"
first=true
$<.each{|e|
	l=e.strip
	break if l=='__END__'
	if !l.empty? && !l.start_with?('#')
		print ';' if !first
		first=false
		print l.gsub('"','\"').gsub("'",'\"')
	end
}
print "\"});"

puts <<EOM
		p.getOutputStream().write(z,0,System.in.read(z,0,SIZE));
		p.getOutputStream().close();
		Scanner sc=new Scanner(p.getInputStream());
		for(;sc.hasNext();)System.out.println(sc.nextLine());
	}catch(IOException e){
		System.out.println(e.getMessage());
	}}
EOM
print '}'