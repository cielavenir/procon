#!/usr/bin/ruby
t={"alfa"=>"A","sierra"=>"S","bravo"=>"B","tango"=>"T","charlie"=>"C","uniform"=>"U","delta"=>"D","victor"=>"V","echo"=>"E","whiskey"=>"W","foxtrot"=>"F","xray"=>"X","golf"=>"G","yankee"=>"Y","hotel"=>"H","zulu"=>"Z","india"=>"I","zero"=>"0","juliett"=>"J","one"=>"1","kilo"=>"K","two"=>"2","lima"=>"L","three"=>"3","mike"=>"M","four"=>"4","november"=>"N","five"=>"5","oscar"=>"O","six"=>"6","papa"=>"P","seven"=>"7","quebec"=>"Q", "eight"=>"8","romeo"=>"R","nine"=>"9"}
gets.to_i.times{
	puts gets.chomp.split.map{|e|
		ret=nil
		t.each{|f,g|
			if f=~/#{'^'+e.gsub('*','.*')+'$'}/
				if !ret
					ret=g
				elsif ret!='.'
					ret='.'
					break
				end
			end
		}
		ret||'.'
	}*''
}