#!/usr/bin/ruby
require 'net/http'
TARGET=208050656559285601386927895421059705239114932023754

mi=0
ma=1267650600228229401496703205376
Net::HTTP.start('salvageon.textfile.org'){|http|
	while mi!=ma
		h=(mi+ma)/2
		puts 'Attempting '+h.to_s
		resp=http.get('/?db=1&index='+h.to_s)
		sleep(1)
		redo if resp.code!='200'
		a=resp.body.split
		key=a[2][1..-1].to_i
		puts key
		if TARGET==key
			puts 'Found key!'
			puts a[3]
			exit
		end
		if key<TARGET
			mi=h
		else
			ma=h
		end
	end
}

=begin
Attempting 2565070352901388243030491
208050656559285601386927895421059705239114932023754
Found key!
V406435859539156181269150751031
=end

__END__
ENV:Ruby
POINT:(1)2分探索 (2)O(logn)で探索できるまで規則を単純化すること
【問１】
データは全て昇順に並んでいるので、単純な2分探索で良い。