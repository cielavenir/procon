#!/usr/bin/env ruby
#https://mtsmfm.github.io/2018/02/03/doukaku-e21.html
#https://qiita.com/mtsmfm/items/b48952dee07784cce8f2

=begin
補足
・参加者は与えられた順番で引き金を引いていき、全員引き終わったら最初の参加者に戻る。
・引き金を引いても弾倉は回転しない。このため、2回連続でアタリとなることはない。
・「アタリを引いた人」が1巡目で引いたとは限らない。
[1]12[4][3]/8
の[4]は2巡目で引いている。
1,4,3ハズレ,3の順番で引いたとすると、
11010000
となるが、2個目の1は、1巡目で2人目がアタリを引いていないことに矛盾する。
よって、解き方にも依るが、ハズレも確定させていく必要がある。
=end

def dfs(r,cur,i,a,b,k)
	# r:結果(-1:未確定、1:弾が入っていた)
	# cur:弾倉のカーソル
	# i:i人目
	# a:ハズレの際回す数
	# b:アタリを引いた人か
	# k:連続ハズレ数
	return to_enum(:dfs,r,cur,i,a,b,k) if !block_given?
	if b.all?(&:!)
		yield r
	elsif k<=r.size*2 # 少し多めにする
		# 「弾倉数」回回ったら、今まで確定した分では決められた回数アタリが出せない
		# (確定に誤りがある)とする
		i=0 if i==a.size
		if !b[i]
			r[cur]=0 if f=r[cur]==-1
			dfs(r,(cur+a[i])% r.size,i+1,a,b,k+1,&proc)
			r[cur]=-1 if f
		else
			if r[cur]==-1
				r[cur]=1
				dfs(r,cur,i,a[0,i]+a[i+1..-1],b[0,i]+b[i+1..-1],0,&proc)
				r[cur]=-1
			end
			r[cur]=0 if f=r[cur]==-1
			dfs(r,(cur+a[i])% r.size,i+1,a,b,k+1,&proc)
			r[cur]=-1 if f
		end
	end
end

def parse(s)
	#[3]4[4]3/7
	#a => [3, 4, 4, 3]
	#b => [true, false, true, false]
	a=[]
	b=[]
	f=false
	s.each_char{|c|
		if c=='['
			f=true
		elsif c!=']'
			a<<c.to_i
			b<<f
			f=false
		end
	}
	[a,b]
end

STDOUT.sync=true
while gets
	x,y=$_.chomp.split('/')
	a,b=parse(x)
	dfs([-1]*y.to_i,0,0,a,b,0){|e|
		puts e.map{|e|e<0?0:e}*''
		#2行以上出力される == 一意でないといえる
	}
end
