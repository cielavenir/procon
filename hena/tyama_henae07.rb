#!/usr/bin/env ruby
#http://nabetani.sakura.ne.jp/hena/orde07_7seg/
#http://qiita.com/Nabetani/items/6e7a6fadbfaa4ae20e89

A=%w(3f	06	5b	4f	66	6d	7d	27	7f	6f).map(&:hex)
B=%w(40	79	24	30	19	12	02	58	00	10).map(&:hex)

def getfirst(a)
	#無効となる条件は、
	#1) 空の要素がある
	#2) 「何らかの数字を表示しなければならない桁」より右に空白しか表示できない桁がある
	#3) (1桁の場合を除き)先頭桁が0しか表示できない
	return nil if a.any?(&:empty?)
	idx=a.size.times.find{|i|!a[i].include?(nil)}||a.size-1
	# a[idx]はnilを含まないか最終桁である。
	# 最終桁でない場合nilを含まないので、0だけを除去する。
	# 最終桁の場合はnilを含みうるので除去する。逆に0を除去してはならない。
	first_digits=a[idx].reject{|e|idx<a.size-1 ? e==0 : e==nil}
	return nil if first_digits==[]||a[idx+1..-1].any?{|e|e.compact.empty?}
	first_digit=first_digits.first.to_s
	first_digit+a[idx+1..-1].map{|e|e.compact.first}*''
end
def getlast(a)
	#「空白にしかならない桁」より右の、最後の要素
	# たとえば[[nil,1],[0]]の場合に、getfirst()のidxとgetlast()のidxは異なる
	# [[nil,0],[1]]等を正しく処理できないが、入力として作れないのでセーフ
	idx=((a.size-1).downto(0).find{|i|a[i].compact.empty?}||-1)+1
	a[idx..-1].map(&:last)*''
end

while gets
	#前半戦：可能性のある数字を列挙する(空はnil)
	a,b=$_.split(',').map{|e|e.split(':').map(&:hex)}
	a0=a.map{|e|(e==0x00?[nil]:[])+(0..9).select{|i|(e&A[i])==e}}
	b0=b.map{|e|[nil]+(0..9).select{|i|(e&B[i])==e}}
	x=a0.zip(b0).map{|x,y|x&y}
	#後半戦：表示しうる数字を検討する
	if false
		# 組み合わせ全列挙でも1秒未満で終わった…
		a=x.shift.product(*x).map{|e|
			e.map{|f|f ? f.to_s : ' '}.join.lstrip
		}.reject{|e|
			e.empty? || e.include?(' ') || (e.size>1&&e[0]=='0')
		}
		puts a.empty? ? :- : a.map(&:to_i).minmax*','
	else
		first=getfirst(x)
		if !first
			puts :-
		else
			puts '%s,%s'%[
				first,
				getlast(x)
			]
		end
	end
	STDOUT.flush
end