#!/usr/bin/ruby
#mode=:php
#mode=:ruby
#mode=:ruby_base85
#mode=:perl
#mode=:python
#mode=:python_base85
#mode=:python_checkio
#mode=:java
#mode=:cpp
#mode=:cpp_yukicoder3051
mode=:cpp_yukicoder3051_base85

#code=:base64
code=:base85

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

def base85enc(s)
	t="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!#$%&()*+-;<=>?@^_`{|}~";
	r=''.dup
	n=0
	s.size.times{|i|
		n=(n<<8)+s[i].ord
		if i%4==3
			5.times{|j|
				n0=n
				(4-j).times{n0/=85}
				n0%=85
				r<<t[n0]
			}
			n=0
		end
	}
	if s.size%4>0
		(4-s.size%4).times{|i|n<<=8}
		(s.size%4+1).times{|j|
			n0=n
			(4-j).times{n0/=85}
			n0%=85
			r<<t[n0]
		}
	end
	r
end

def base64enc(s)
	t="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
	r=''.dup
	n=0
	s.size.times{|i|
		n=(n<<8)+s[i].ord
		if i%3==2
			4.times{|j|
				n0=n
				(3-j).times{n0/=64}
				n0%=64
				r<<t[n0]
			}
			n=0
		end
	}
	if s.size%3>0
		(3-s.size%3).times{|i|n<<=8}
		(s.size%3+1).times{|j|
			n0=n
			(3-j).times{n0/=64}
			n0%=64
			r<<t[n0]
		}
		(3-s.size%3).times{|i|r<<='='}
	end
	r
end

arc=getarchive(DATA)
data=arc[mode.to_s]
if code==:base64
	b64=base64enc(data)
elsif code==:base85
	b64=base85enc(data)
end
print data.sub('*',b64)

#http://www.patrickschneider.com/blog/2005/05/how-to-write-a-php-quine/
#fasta-like editable text archive
#PHP: coding-doujo 92
#Ruby: coding-doujo 93
__END__
>php
$dna='*';
echo str_replace(chr(42),$dna,base64_decode($dna));
>ruby
dna='*'
print dna.unpack('m')[0].sub('*',dna)
>ruby_base85
dna='*'
T="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!#$%&()*+-;<=>?@^_`{|}~"
base85dec=->s{n=i=0;r='';f=->i{i.times{|j|r+=((n>>8*(3-j))&255).chr}};s.each_char{|c|x=T.index(c);n=n*85+x;i+=1;(f[4];n=i=0)if i==5};i.upto(4){n=n*85+84};f[i-1];r}
print base85dec[dna].sub('*',dna)
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
print(base64.b64decode(dna).replace('*',dna,1),end='')
>python_base85
from __future__ import print_function
import base64
dna='*'
print(base64.b85decode(dna.encode('utf-8')).decode('utf-8').replace('*',dna,1),end='')
>python_checkio
import base64
dna='*'
quine=lambda:base64.b85decode(dna.encode('utf-8')).decode('utf-8').replace('*',dna,1)
>java
class Main{
	final static String dna="*";
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
		System.out.print(base64_decode(dna).replace(String.valueOf((char)42),dna));
	}
}
>cpp
#include <string>
#include <cstdio>
using namespace std;
string dna_orig="*";
string table="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
string base64_decode(const string &in){
	string ret="";
	int b=0,I=0,idx;
	int x=0;
	for(;I<in.size();I++){
		if(in[I]=='=')break;
		idx=table.find(in[I]);
		if(idx>=0){
			x=(x<<6)+idx;
			b+=6;
			if(b>=8){b-=8;ret+=(char)((x>>b)&0xff);}
		}
	}
	while(b>=8){b-=8;ret+=(char)((x>>b)&0xff);}
	return ret;
}
int main(){
	string dna = base64_decode(dna_orig);
	int pos = dna.find('*');
	dna = dna.substr(0,pos)+dna_orig+dna.substr(pos+1);
	for(auto &e:dna)putchar(e);
}
>cpp_yukicoder3051
#include <string>
#include <cstdio>
using namespace std;
string dna_orig="*";
string table="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
string base64_decode(const string &in){
	string ret="";
	int b=0,I=0,idx;
	int x=0;
	for(;I<in.size();I++){
		if(in[I]=='=')break;
		idx=table.find(in[I]);
		if(idx>=0){
			x=(x<<6)+idx;
			b+=6;
			if(b>=8){b-=8;ret+=(char)((x>>b)&0xff);}
		}
	}
	while(b>=8){b-=8;ret+=(char)((x>>b)&0xff);}
	return ret;
}
int main(){
	string dna = base64_decode(dna_orig);
	int pos = dna.find('*');
	dna = dna.substr(0,pos)+dna_orig+dna.substr(pos+1);

	// due to yukicoder limitation, reading whole string is not applicable.
	string xray;
	for(int c,i=0;i<dna.size();i++){
		c=getchar();
		xray+=c;
	}
	for(int i=0;i<dna.size();i++)if(dna[i]!=xray[i])printf("%d\n\"%c\"\n\"%c\"\n",i,dna[i],xray[i]);
}
>cpp_yukicoder3051_base85
#include <string>
#include <cstdio>
using namespace std;
string dna_orig="*";
string T="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!#$%&()*+-;<=>?@^_`{|}~";
string base85_decode(const string &s){
	int n=0;
	int i=0;
	string r;
	for(;i<s.size();i++){
		int x=T.find(s[i]);
		n=n*85+x;
		if(i%5==4){
			for(int j=0;j<4;j++)r+=((n>>8*(3-j))&255);
			n=0;
		}
	}
	i%=5;
	for(int j=i;j<5;j++){n=n*85+84;}
	for(int j=0;j<i-1;j++)r+=((n>>8*(3-j))&255);
	return r;
}
int main(){
	string dna = base85_decode(dna_orig);
	int pos = dna.find('*');
	dna = dna.substr(0,pos)+dna_orig+dna.substr(pos+1);

	// due to yukicoder limitation, reading whole string is not applicable.
	string xray;
	for(int c,i=0;i<dna.size();i++){
		c=getchar();
		xray+=c;
	}
	for(int i=0;i<dna.size();i++)if(dna[i]!=xray[i])printf("%d\n\"%c\"\n\"%c\"\n",i,dna[i],xray[i]);
}
