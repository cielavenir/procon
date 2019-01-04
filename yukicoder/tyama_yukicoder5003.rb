#!/usr/bin/ruby
YUKICODER=false # local test: set to false and >/dev/null
n,s = YUKICODER ? [gets.to_i,gets.chomp] : [10000,'']
n=10000
k=[0,0,0,0,0]
enh=[0,0,0,0,0]
t=[
	{:name=>'hand',:buyprice=>150,:enhprice=>1500,:reward=>1},
	{:name=>'lily',:buyprice=>2000,:enhprice=>20000,:reward=>10},
	{:name=>'factory',:buyprice=>30000,:enhprice=>300000,:reward=>120},
	{:name=>'casino',:buyprice=>600000,:enhprice=>6000000,:reward=>2000},
	{:name=>'grimoire',:buyprice=>10000000,:enhprice=>100000000,:reward=>25000},
]
r=0
z=0
idx=0
idxenh=0
n.times{
	if idxenh<t.size && r>=t[idxenh][:enhprice]
		puts 'reinforce '+t[idxenh][:name]
		r-=t[idxenh][:enhprice]
		t[idxenh][:enhprice]=10*t[idxenh][:enhprice]
		t[idxenh][:reward]=2*t[idxenh][:reward]
		enh[idxenh]+=1
		idxenh+=1 if enh[idxenh]>=1
	elsif idx<t.size && r>=t[idx][:buyprice]
		puts 'buy '+t[idx][:name]
		r-=t[idx][:buyprice];t[idx][:buyprice]=(6*t[idx][:buyprice]+5-1)/5
		k[idx]+=1
		idx+=1 if k[idx]>=10
	else
		puts 'click'
		r+=1
	end
	r+=t.zip(k).reduce(0){|s,(x,y)|s+x[:reward]*y}
	STDOUT.flush
	gets if YUKICODER
}
STDERR.puts r
