#!/usr/bin/ruby
#coding:utf-8

require 'zlib'
require 'base64'
require 'stringio'
Encoding.default_external=Encoding::UTF_8

#多項式加減乗算
#mul([2,1,1],[1,4,3]) => [2, 9, 11, 7, 3]
#(2+x+x^2)*(1+4x+3x^2) is 2+9x+11x^2+7x^3+3x^4
def add(a,b) [a.size,b.size].max.times.map{|i|(a[i]||0)+(b[i]||0)} end
def sub(a,b) add(a,b.map{|e|-e}) end
def mul(a,b) b.size.times.reduce([]){|s,i|add(s,[0]*i+a.map{|e|b[i]*e})} end

#構文解析(stage2)
#POJ 2252(Java)をポート
AddSub = Regexp.compile(/^(.*?)([0-9,-]+)([+Z])([0-9,-]+)(.*)$/)
MulDiv = Regexp.compile(/^(.*?)([0-9,-]+)([*])([0-9,-]+)(.*)$/)

def process(s)
=begin
	#analyze parens
	bidx=s.index("(")
	while bidx
		count=1
		eidx=bidx+1
		while count!=0
			count+=1 if s[eidx,1]=='('
			count-=1 if s[eidx,1]==')'
			eidx+=1
		end
		s=s[0,bidx]+process(s[bidx+1...eidx-1])+s[eidx..-1]
		bidx=s.index("(")
	end
=end

	while m=MulDiv.match(s)
		if m[3]=='*'
			s=m[1]+mul(m[2].split(',').map(&:to_i),m[4].split(',').map(&:to_i))*','+m[5]
		end
	end

	while m=AddSub.match(s)
		if m[3]=='+'
			s=m[1]+add(m[2].split(',').map(&:to_i),m[4].split(',').map(&:to_i))*','+m[5]
		else
			s=m[1]+sub(m[2].split(',').map(&:to_i),m[4].split(',').map(&:to_i))*','+m[5]
		end
	end
	s
end

#構文解析(stage1)
def tokenize(expr,regexp)
	result=''
	previdx=0
	idx=0
	while expr[idx,1]
		if ['+','-','='].include?(expr[idx,1])
			raise if !m=regexp.match(expr[previdx...idx])
			result<<(yield m)
			result<< expr[idx,1]
			previdx=idx+1
		end
		idx+=1
	end
	raise if !m=regexp.match(expr[previdx..-1])
	result<<(yield m)
	result.gsub('-','Z')
end
def calc_helper(a,units)
	if x=a.each_with_index.find{|e,i|e=='□'}
		'0,'+units[x[1]].to_s
	else
		a.each_with_index.reduce(0){|s,(e,i)|s+(e||'0').to_i*units[i]}.to_s
	end
end
def calc(expr)
	# expr => "3m20cm-3m10cm-□mm=5mm"
	if expr=~/g/ #重さ
		result=tokenize(expr,/^(([0-9□]+)kg)?(([0-9□]+)g)?(([0-9□]+)mg)?$/){|match|
			calc_helper([match[2],match[4],match[6]],[1000000,1000,1])
		}
	elsif expr=~/m/ #長さ
		result=tokenize(expr,/^(([0-9□]+)km)?(([0-9□]+)m)?(([0-9□]+)cm)?(([0-9□]+)mm)?$/){|match|
			calc_helper([match[2],match[4],match[6],match[8]],[1000000,1000,10,1])
		}
	else #時間
		result=tokenize(expr,/^(([0-9□]+)日)?(([0-9□]+)時間)?(([0-9□]+)分)?(([0-9□]+)秒)?$/){|match|
			calc_helper([match[2],match[4],match[6],match[8]],[86400,3600,60,1])
		}
	end
	# result => "3200Z3100Z0,1=5"
	a,b=result.split('=')
	r,s=process(process(a)+'Z'+process(b)).split(',').map(&:to_i)
	# => [95,-1]
	raise if r%s>0
	-r/s
end

f=StringIO.new(Zlib.inflate(Base64.decode64($<.read)).force_encoding(Encoding.default_external))
while f.gets
	id,expr1,expr2=$_.split
	#break if id[0,1]!='T'
	puts id if calc(expr1)!=calc(expr2)
end

__END__
【解答】
111,112,222,223,333,334,444,445,555,556,666,667,777,778,888,889,999
【感想・工夫した点など】
一番低い単位に合わせた後、正規表現による多項式演算で0次の項と1次の項を求め、割ることで未知数を求めた。

calc()の中は手抜きだったので直しました。
mul()はわかりにくいコードになってしまっていますが、reduceが使えることがわかったのでそうしました。
【言語と処理系】
Ruby 2.0 (マルチバイト文字列を含むのでRuby 1.9以降専用)
【ソースコード】