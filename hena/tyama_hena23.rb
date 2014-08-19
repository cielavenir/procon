#!/usr/bin/env ruby
#http://qiita.com/Nabetani/items/7ba11167ea28c929fcf2
#http://nabetani.sakura.ne.jp/hena/ord23snakemoinc/
class Hena23
	def initialize(a)
		@a=a
		@memo={}
	end
	def dfs(x,y,nprev)
		return 0 if x<0||@a[0].size<=x || y<0||@a.size<=y || @a[y][x]<=nprev
		return @memo[[x,y]]||=[[-1,0],[1,0],[0,-1],[0,1]].map{|_x,_y|
			dfs(x+_x,y+_y,@a[y][x])+1
		}.max
	end
	def run
		@a.size.times.lazy.map{|y|
			@a[0].size.times.lazy.map{|x|
				dfs(x,y,-1)
			}.max
		}.max
	end
end

if $0==__FILE__
	STDOUT.sync=true
	while gets
		p Hena23.new($_.chomp.split('/').map{|e|e.split('').map(&:to_i)}).run
	end
end