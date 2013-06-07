#!/usr/bin/ruby
class TLLI
	def initialize
		@trianies=[nil,[0,0,0]]
	end
	def root_triany
		1
	end
	def allocate_triany
		siz=@trianies.size
		@trianies[siz]=[0,0,0]
		return siz
	end
	def set_a(id,value)
		return if !@trianies[id]
		@trianies[id][0]=value
	end
	def set_b(id,value)
		return if !@trianies[id]
		@trianies[id][1]=value
	end
	def set_c(id,value)
		return if !@trianies[id]
		@trianies[id][2]=value
	end
	def get_a(id)
		return if !@trianies[id]
		@trianies[id][0]
	end
	def get_b(id)
		return if !@trianies[id]
		@trianies[id][1]
	end
	def get_c(id)
		return if !@trianies[id]
		@trianies[id][2]
	end
end

class SETI <TLLI # a=>key, b=>left, c=>right
	def set_entry(key,value)
		t=root_triany
		while get_c(t)!=0
			if key<=get_a(t)
				t=get_b(t)
			else
				t=get_c(t)
			end
		end
		if get_a(t)==key
			set_b(t,value)
		else
			leaf1=allocate_triany
			key1=get_a(t)
			leaf2=allocate_triany
			key2=key
			set_a(leaf1,key1)
			set_b(leaf1,get_b(t))
			set_a(leaf2,key2)
			set_b(leaf2,value)
			if key1<=key2 # insert right
				set_b(t,leaf1)
				set_c(t,leaf2)
			else # insert left
				set_a(t,key2) # need to update node key
				set_b(t,leaf2)
				set_c(t,leaf1)
			end
		end
	end
	def find_entry(key)
		t=root_triany
		loop{
			return true if key==get_a(t)
			if key<get_a(t)
				t=get_b(t)
				return false t==0
			else
				t=get_c(t)
				return false t==0
			end
		}
	end
	def print2(t)
		if get_c(t)!=0
			#Kernel.print(get_a(t))
			print2(get_b(t))
			Kernel.print(get_a(t))
			print2(get_c(t))
		else
			#Kernel.print(get_a(t))
		end
	end
	def print
		print2(root_triany)
		Kernel.puts
	end
end

dicti=DICTI.new
sum=0
while gets
	if $_[0..0]=='i'
		a=$_.split
		dicti.set_entry(a[1].to_i,1)
	elsif $_[0..0]=='f'
		a=$_.split
		sum+=dicti.find_entry(a[1].to_i)
	elsif $_[0..0]=='p'
		dicti.print
	end
end