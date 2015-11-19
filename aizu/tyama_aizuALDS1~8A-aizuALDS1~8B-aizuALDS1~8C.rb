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
	def set_entry(key)
		x=root_triany
		y=0
		while x!=0&&!(x==root_triany&&get_a(x)==0) #fixme
			y=x
			if key<get_a(x)
				x=get_b(x)
			else
				x=get_c(x)
			end
		end
		if y==0
			set_a(root_triany,key)
		else
			leaf=allocate_triany
			set_a(leaf,key)
			if key<get_a(y)
				set_b(y,leaf)
			else
				set_c(y,leaf)
			end
		end
	end
	def find_entry(key)
		t=root_triany
		loop{
			return true if key==get_a(t)
			if key<get_a(t)
				t=get_b(t)
				return false if t==0
			else
				t=get_c(t)
				return false if t==0
			end
		}
	end
	def delete_entry(key)
		left=false
		prev=nil
		t=root_triany
		loop{
			break if key==get_a(t)
			prev=t
			if key<get_a(t)
				t=get_b(t)
				left=true
				return false if t==0
			else
				t=get_c(t)
				left=false
				return false if t==0
			end
		}
		if get_b(t)>0&&get_c(t)>0
			children=inorder_internal(get_c(t))+[t]
			set_a(t,get_a(children[0]))

			prev=children[1]
			#left of parent of t
			if prev!=t
				set_b(prev,0)
				left=true
			else
				left=false
			end
			t=children[0]
		end
		if t==root_triany
			if get_b(root_triany)>0
				set_a(root_triany,get_a(get_b(root_triany)))
				set_c(root_triany,get_c(get_b(root_triany)))
				set_b(root_triany,get_b(get_b(root_triany)))
			elsif get_c(root_triany)>0
				set_a(root_triany,get_a(get_c(root_triany)))
				set_b(root_triany,get_b(get_c(root_triany)))
				set_c(root_triany,get_c(get_c(root_triany)))
			end
		else
			raise if !prev
			if get_b(t)+get_c(t)>0
				n=get_b(t)+get_c(t)
				if left
					set_b(prev,n)
				else
					set_c(prev,n)
				end
			else
				if left
					set_b(prev,0)
				else
					set_c(prev,0)
				end
			end
		end
	end
	def inorder_internal(t)
		t==0 ? [] : inorder_internal(get_b(t))+[t]
	end
	def print_preorder(t)
		return if t==0
		Kernel.print " #{get_a(t)}"
		print_preorder(get_b(t))
		print_preorder(get_c(t))
	end
	def print_inorder(t)
		return if t==0
		print_inorder(get_b(t))
		Kernel.print " #{get_a(t)}"
		print_inorder(get_c(t))
	end
	def print_postorder(t)
		return if t==0
		print_postorder(get_b(t))
		print_postorder(get_c(t))
		Kernel.print " #{get_a(t)}"
	end
	def print
		print_inorder(root_triany);puts
		print_preorder(root_triany);puts
	end
end

seti=SETI.new
gets
$<.each{|l|
	a=l.split
	if a[0]=='insert'
		seti.set_entry(a[1].to_i)
	elsif a[0]=='find'
		puts seti.find_entry(a[1].to_i) ? :yes : :no
	elsif a[0]=='delete'
		seti.delete_entry(a[1].to_i)
	elsif a[0]=='print'
		seti.print
	end
}