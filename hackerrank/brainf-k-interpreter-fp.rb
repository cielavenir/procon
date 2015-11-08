#!/usr/bin/ruby

class BF
	def initialize(s)
		@inp=s
		@buffer=[0]*99999
		@ptr=0
		@inpptr=0
		@inst=0
	end
	def execute(s)
		i=0
		while i<s.size
			if s[i]=='>'
				@ptr+=1;@inst+=1
			elsif s[i]=='<'
				@ptr-=1;@inst+=1
			elsif s[i]=='+'
				@buffer[@ptr]=(@buffer[@ptr]+1)%256;@inst+=1
			elsif s[i]=='-'
				@buffer[@ptr]=(@buffer[@ptr]-1)%256;@inst+=1
			elsif s[i]=='.'
				@inst+=1
				if @inst>100000
					raise
				end
				print(@buffer[@ptr].chr)
			elsif s[i]==','
				@inst+=1
				if @inst>100000
					raise
				end
				@buffer[@ptr]=@inp[@inpptr].ord;@inpptr+=1
			elsif s[i]=='['
				@inst+=1
				if @buffer[@ptr]!=0
					execute(s[i+1..-1])
				end
				marker=1
				while marker>0
					if s[i+1]=='['
						marker+=1
					elsif s[i+1]==']'
						marker-=1
					end
					i+=1
				end
			elsif s[i]==']'
				@inst+=1
				if @buffer[@ptr]!=0
					@inst+=1
					i=-1
				else
					return
				end
			end
			i+=1
			if @inst>100000
				raise
			end
		end
	end
end

n,m=gets.split.map(&:to_i)
bf=BF.new(gets.chomp.chop)
begin
	bf.execute($<.to_a*'')
rescue
	puts
	puts 'PROCESS TIME OUT. KILLED!!!'
end