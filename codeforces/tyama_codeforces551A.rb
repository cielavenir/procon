#!/usr/bin/ruby
#coding:utf-8
#derived from 3年C組の成績表
gets
m=gets.split.map(&:to_i).each_with_index.to_a
1.times{|i| # 各列を順位に変換
	m.sort_by!{|e|-e[i]}
	a=[] # 順位
	rank=1
	add=0
	a<<rank
	(1...m.size).each{|j|
		add+=1
		if m[j-1][i]>m[j][i] # 点数が異なっていたら、同じだった人数を順位に加える
			rank+=add
			add=0
		end
		a<<rank
	}
	m.size.times{|j|m[j][i]=a[j]} # 行列を順位で上書き
}
m.sort_by!{|e|e.last}
m.size.times{|i|m[i].pop}
puts m*' '