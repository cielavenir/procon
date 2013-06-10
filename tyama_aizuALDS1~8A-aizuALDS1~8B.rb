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

$black={}
class SETI <TLLI # a=>key, b=>left, c=>right
	def set_entry(key)
		if $black[key]
			$black.delete(key)
			return
		end
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
		return false if $black[key]
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
	def print_preorder(t)
		return if t==0
		Kernel.print " #{get_a(t)}" unless $black.has_key?(get_a(t))
		print_preorder(get_b(t))
		print_preorder(get_c(t))
	end
	def print_inorder(t)
		return if t==0
		print_inorder(get_b(t))
		Kernel.print " #{get_a(t)}" unless $black.has_key?(get_a(t))
		print_inorder(get_c(t))
	end
	def print_postorder(t)
		return if t==0
		print_postorder(get_b(t))
		print_postorder(get_c(t))
		Kernel.print " #{get_a(t)}" unless $black.has_key?(get_a(t))
	end
	def print
		print_inorder(root_triany);puts
		print_preorder(root_triany);puts
	end
end

seti=SETI.new
$<.drop(1).each{|l|
	a=l.chomp.split
	if a[0]=='insert'
		seti.set_entry(a[1].to_i)
	elsif a[0]=='find'
		puts seti.find_entry(a[1].to_i) ? :yes : :no
	elsif a[0]=='delete'
		$black[a[1].to_i]=1 # incorrect: WA on 7C case2.
	elsif a[0]=='print'
		seti.print
	end
}