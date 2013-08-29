#!/usr/bin/ruby
require 'base64'
def getarchive(f)
	arc={}
	seq=''
	line=f.gets
	line.chomp!
	name=line[1..-1]
	while line=f.gets
		line.chomp!
		if line[0,1]=='>'
			arc[name]=seq.strip
			seq=''
			name=line[1..-1]
		else
			seq+=line+"\n"
		end
	end
	arc[name]=seq.strip
	arc
end

arc=getarchive(DATA)
data=arc['perl']
b64=Base64.strict_encode64(data)
print data.sub('*',b64)

#http://www.patrickschneider.com/blog/2005/05/how-to-write-a-php-quine/
#fasta-like editable text archive
#PHP: coding-doujo 92
#Ruby: coding-doujo 93
__END__
>php
$dna = '*';
echo str_replace(chr(42), $dna, base64_decode($dna));
>ruby
require 'base64'
dna='*'
print Base64.decode64(dna).sub('*',dna)
>perl
use MIME::Base64;
$dna='*';
$dec=decode_base64($dna);
$dec=~s/\*/$dna/;
print $dec;
>python
from __future__ import print_function
import base64
dna='*'
print(base64.b64decode(dna).replace(chr(42),dna),end='')
>java
class Main{
	final static String table="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	public static String base64_decode(String in){
		String ret="";
		int b=0,I=0,idx;
		int x=0;
		for(;I<in.length();I++){
			if(in.charAt(I)=='='){
				break;
			}
			idx=table.indexOf(in.charAt(I));
			if(idx>=0){
				x=(x<<6)+idx;
				b+=6;
				if(b>=8){b-=8;ret+=(char)((x>>b)&0xff);}
			}
		}
		while(b>=8){b-=8;ret+=(char)((x>>b)&0xff);}
		return ret;
	}
	public static void main(String[]z){
		String dna="*";
		System.out.print(base64_decode(dna).replace(String.valueOf((char)42),dna));
	}
}