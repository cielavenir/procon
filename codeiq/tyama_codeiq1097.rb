#!/usr/bin/ruby
#coding:utf-8

#require 'zlib'
#require 'base64'
#require 'stringio'
Encoding.default_external=Encoding::UTF_8

def solve(_expr)
	expr=Hash[*_expr.split(',').flat_map{|e|
		a,b=e.split('=')
		[a.chars.to_a.sort.join,b.chomp('m').chomp('c').chomp('度').to_i]
	}]
	angles=['A角','B角','C角']
	edges=['AB','BC','AC']

	#内周の和は180度
	angles.size.times{|i|
		if !expr.has_key?(angles[i]) &&
			expr.has_key?(angles[(i+1)%angles.size]) &&
			expr.has_key?(angles[(i+2)%angles.size])
		then
			expr[angles[i]]=180-expr[angles[(i+1)%angles.size]]-expr[angles[(i+2)%angles.size]]
		end
	}

	#3辺か3角が等しい
	if [angles,edges].any?{|category|
		category.all?{|e|expr.has_key?(e)&&expr[category[0]]==expr[e]}
	}
		return 'あ'
	end
	#2辺か2角が等しい
	if [angles,edges].any?{|category|
		category.combination(2).any?{|x,y|expr.has_key?(x)&&expr.has_key?(y)&&expr[x]==expr[y]}
	}
		return 'あ' if angles.any?{|e|expr.has_key?(e)&&expr[e]==60} # 2辺が等しく、角の1つが60度
		return 'い'
	end
	'う'
end

#f=StringIO.new(Zlib.inflate(Base64.decode64($<.read)).force_encoding(Encoding.default_external))
f=$<
while f.gets
	id,expr,ans=$_.split
	#break if id[0,1]!='T'
	puts id if solve(expr)!=ans
end

__END__
【解答】
31,41,59,265,358,444,555,666,777,888,979,999
※ゾロ目以外の解答を連結すると円周率になる
【感想・工夫した点など】
2角がわかっているときにもう1角を計算することで、最後の条件判断を減らした。
辺の書き方は2通りあるが、ソートすることで1通りになるようにした。
【言語と処理系】
Ruby 2.0 (マルチバイト文字列を含むのでRuby 1.9以降専用)
【ソースコード】