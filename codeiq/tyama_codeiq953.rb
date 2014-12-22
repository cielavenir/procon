#!/usr/bin/ruby
def dfs(a,lst)
	lst.each{|e|
		if a.last[-1]==e[0] && !a.include?(e)
			a.push(e)
			if a.size>$size
				$size=a.size
				$a=a.dup
			end
			dfs(a,lst)
			a.pop
		end
	}
end

$size=0
$a=[]
data=DATA.map{|e|e.chomp.downcase}
data.each{|e|dfs([e],data)}
p $size
p $a

#8
#["korea republic", "cameroon", "netherlands", "spain", "nigeria", "australia", "argentina", "algeria"]

__END__
Brazil
Croatia
Mexico
Cameroon
Spain
Netherlands
Chile
Australia
Colombia
Greece
Cote d'Ivoire
Japan
Uruguay
Costa Rica
England
Italy
Switzerland
Ecuador
France
Honduras
Argentina
Bosnia and Herzegovina
Iran
Nigeria
Germany
Portugal
Ghana
USA
Belgium
Algeria
Russia
Korea Republic