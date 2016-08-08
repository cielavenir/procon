#!/usr/bin/env ruby
#http://mtsmfm.github.io/2016/08/06/doukaku-e06.html
#http://qiita.com/mtsmfm/items/7a0bfd2ac5b7674ce8c7

def calc_damage(t1,t2)
	{
		'R'=>{'R'=>2,'G'=>4,'B'=>1},
		'G'=>{'R'=>1,'G'=>2,'B'=>4},
		'B'=>{'R'=>4,'G'=>1,'B'=>2},
	}[t1][t2]
end

class Pokemon
	attr_reader :type
	attr_accessor :level,:hp
	def initialize(s)
		@type=s[-1]
		@level=@hp=s[0...-1].to_i
	end
	def battle(o)
		if o.level>self.level
			o.battle(self)
		else
			o.hp-=calc_damage(self.type,o.type) if @hp>0
			if o.hp>0 || o.level==self.level
				self.hp-=calc_damage(o.type,self.type)
			end
		end
	end
	
end

while gets
	trainers=$_.chomp.split(',').map{|e|e.scan(/\d+[RGB]/)}
	win=[0]*trainers.size
	(trainers.size-1).times{|i|
		(i+1...trainers.size).each{|j|
			trainer1=trainers[i].map{|e|Pokemon.new(e)}
			trainer2=trainers[j].map{|e|Pokemon.new(e)}
			while !trainer1.empty?&&!trainer2.empty?
				trainer1.first.battle(trainer2.first)
				trainer1.shift if trainer1.first.hp<=0
				trainer2.shift if trainer2.first.hp<=0
			end
			win[i]+=1 if !trainer1.empty?
			win[j]+=1 if !trainer2.empty?
		}
	}
	puts (1..trainers.size).sort_by.with_index{|e,i|[-win[e-1],i]}*','
	STDOUT.flush
end