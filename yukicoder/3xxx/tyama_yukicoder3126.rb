#!/usr/bin/ruby

class BF
	def initialize(s,n=99999)
		@inp=s
		@buffer=[0]*n
		@ptr=0
		@inpptr=0
		@inst=0
		@n=n
	end
	attr_reader :buffer
	def execute(s)
		i=0
		while i<s.size
			if s[i]=='>'
				@ptr+=1;@inst+=1
				if @ptr<0 || @n<=@ptr
					raise
				end
			elsif s[i]=='<'
				@ptr-=1;@inst+=1
				if @ptr<0 || @n<=@ptr
					raise
				end
			elsif s[i]=='+'
				#@buffer[@ptr]=(@buffer[@ptr]+1)%256;@inst+=1
				@buffer[@ptr]=(@buffer[@ptr]+1);@inst+=1
			elsif s[i]=='-'
				#@buffer[@ptr]=(@buffer[@ptr]-1)%256;@inst+=1
				@buffer[@ptr]=(@buffer[@ptr]-1);@inst+=1
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

# also see hackerrank/brainf-k-interpreter-fp.rb

n=gets.to_i
bf=BF.new('', n)
begin
	bf.execute(gets)
	puts bf.buffer*' '
rescue
	# puts 'PROCESS TIME OUT. KILLED!!!'
	puts :error
end
