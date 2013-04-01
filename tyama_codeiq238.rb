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
=begin
	#test
	def setup_list
		x=root_triany
		y=allocate_triany
		z=allocate_triany
		set_a(x,31)
		set_b(x,41)
		set_c(x,y)
		set_a(y,59)
		set_b(y,26)
		set_c(y,z)
		set_a(z,53)
		set_b(z,58)
		set_c(z,0)
	end
	def print_list
		t=root_triany
		while t!=0
			a=get_a(t)
			b=get_b(t)
			printf("%d,%d,",a,b)
			t=get_c(t)
		end
		puts
	end
=end
end

class DICTI <TLLI
	ALGORITHM=:tree
if ALGORITHM==:list
	#version 1 O(N)
	def set_entry(key,value)
		t=root_triany
		loop{
			if key==get_a(t)
				set_b(t,value)
				return
			end
			succ=get_c(t)
			if succ==0
				succ=allocate_triany
				set_a(succ,key)
				set_b(succ,value)
				set_c(t,succ)
				return
			else
				t=succ
			end
		}
	end
	def find_entry(key)
		t=root_triany
		loop{
			if key==get_a(t)
				return get_b(t)
			end
			succ=get_c(t)
			if succ==0
				return 0
			else
				t=succ
			end
		}
	end
elsif ALGORITHM==:tree
	#version 2 O(logN)
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
		while get_c(t)!=0
			if key<=get_a(t)
				t=get_b(t)
			else
				t=get_c(t)
			end
		end
		if get_a(t)==key
			return get_b(t)
		else
			return 0
		end
	end
else
	raise "set ALGORITHM"
end
=begin
	#test
	def sample_dicti
		sum=0
		set_entry(123,1)
		set_entry(456,2)
		set_entry(789,3)
		n=find_entry(123)
		p n # => 1
		sum+=n
		n=find_entry(999)
		p n # => 0
		sum+=n
		n=find_entry(789)
		p n # => 3
		sum+=n
		set_entry(456,90)
		n=find_entry(456)
		p n # => 90
		sum+=n
		set_entry(456,6)
		n=find_entry(456)
		p n # => 6
		sum+=n
		p sum # => 100
	end
=end
end

=begin
tlli=TLLI.new
tlli.setup_list
tlli.print_list # => 31,41,59,26,53,58,
dicti=DICTI.new
dicti.sample_dicti
exit
=end

dicti=DICTI.new
sum=0
while gets
	if $_[0..0]=='s'
		a=$_.split
		dicti.set_entry(a[1].to_i,a[2].to_i)
	elsif $_[0..0]=='f'
		a=$_.split
		sum+=dicti.find_entry(a[1].to_i)
	#elsif $_[0..0]=='#'
	end
end
p sum

__END__
141421356

DICTIには二分探索木を使用した。二分探索木の特徴として、その時点で比較しているキーよりも遠いキーについては比較しなくて良いため、比較回数が少なくて済むという点が上げられる。
ノードのCが0なら葉、そうでなければ接点を示す。
葉は、Aがキー、Bが値である。接点は、Aがキー、Bが左側のノード番号、Cが右側のノード番号である。
探索するとき、検索するキーが接点のキー以下ならば左側のノードに移動する。こう決めることで、トリアニーは3つの値しか保持できないが、すぐ左側のノードを「その接点のキーと同じキーを持った葉」とすることができる。
二分探索木なので計算量はO(logN)である。それでもtestdata.txtを処理する時間が連結リスト(O(N))の半分ぐらいにしかならないのは接点ノードに値を保持できないためだろう。
読みやすさのために、実装が簡便な連結リスト版も併記した(ALGORITHM=:list)ので、メンテナンスはそちらを一緒に見ながら行うと良い。

プログラミング言語はRubyを使用した。コードを以下に示す。