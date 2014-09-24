#!/usr/bin/ruby
t={"alfa"=>"A","sierra"=>"S","bravo"=>"B","tango"=>"T","charlie"=>"C","uniform"=>"U","delta"=>"D","victor"=>"V","echo"=>"E","whiskey"=>"W","foxtrot"=>"F","xray"=>"X","golf"=>"G","yankee"=>"Y","hotel"=>"H","zulu"=>"Z","india"=>"I","zero"=>"0","juliett"=>"J","one"=>"1","kilo"=>"K","two"=>"2","lima"=>"L","three"=>"3","mike"=>"M","four"=>"4","november"=>"N","five"=>"5","oscar"=>"O","six"=>"6","papa"=>"P","seven"=>"7","quebec"=>"Q","eight"=>"8","romeo"=>"R","nine"=>"9"}
gets.to_i.times{
	puts gets.split.map{|e|
		reg=Regexp.new('^'+e.gsub('*','.*')+'$')
		ret='.'
		t.each{|f,g|
			if f=~reg
				if ret=='.'
					ret=g
				else
					ret='.'
					break
				end
			end
		}
		ret
	}*''
}