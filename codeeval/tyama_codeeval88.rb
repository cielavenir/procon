#!/usr/bin/ruby
#140710: finally fixed
def calculateScore(juggler,circuit) juggler[:h]*circuit[:h]+juggler[:e]*circuit[:e]+juggler[:p]*circuit[:p] end
def assignJuggler(juggler_id)
	juggler=$jugglers[juggler_id]
	$jugglers[juggler_id][:preferences].each{|preference|
		if $circuits[preference][:jugglers].size < $jugglers.size/$circuits.size
			$circuits[preference][:jugglers]<<juggler_id
			$jugglers[juggler_id][:circuit]=preference
			break
		else
			break if !$circuits[preference][:jugglers].each_with_index{|circuit_juggler_id,key| #ghaa! this "break"!
				if calculateScore(juggler,$circuits[preference])>calculateScore($jugglers[circuit_juggler_id],$circuits[preference])
					$circuits[preference][:jugglers][key]=juggler_id
					$jugglers[juggler_id][:circuit]=preference
					assignJuggler(circuit_juggler_id)
					break
				end
			}
		end
	}
end

$stderr.puts RubyVM::DEFAULT_PARAMS
$circuits={}
$jugglers={}
$<.each{|line|
	if line=~/C ([\w\d]+) H:(\d+) E:(\d+) P:(\d+)/
		$circuits[$1]={:id=>$1,:h=>$2.to_i,:e=>$3.to_i,:p=>$4.to_i,:jugglers=>[]}
	elsif line=~/J ([\w\d]+) H:(\d+) E:(\d+) P:(\d+) ([\w\d,]+)/
		$jugglers[$1]={:id=>$1,:h=>$2.to_i,:e=>$3.to_i,:p=>$4.to_i,:preferences=>$5.split(',')}
	end
}
$jugglers.each_value{|juggler|
	assignJuggler(juggler[:id]) if !juggler[:circuit]
}
$circuits.each_value{|circuit|
=begin
	puts "#{circuit[:id]} "+circuit[:jugglers].map{|juggler_id|
		juggler_id.to_s+$jugglers[juggler_id][:preferences].map{|preference|
			" #{preference}:"+calculateScore($jugglers[juggler_id],$circuits[preference]).to_s
		}*''
	}*', '
=end
	if circuit[:id]=='C1970'
		$stderr.puts 'C1970 sum = '+circuit[:jugglers].reduce(0){|s,e|s+=e[1..-1].to_i}.to_s # 28762
	end
}