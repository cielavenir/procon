#!/usr/bin/ruby
$key=0
def trans_table
	alphabets = ["A".."Z", "a".."z", "0".."9"].map{|r| r.to_a.join}
	alphabets.map{|ab| [ab, ab[$key%ab.size..-1] + ab[0, $key%ab.size]]}.transpose.map{|a| a.join}
end
(0..1/0.0).each{|i|
	$key=i
	tr="ykkg://tg2.ezekveuf.tf.ag/vekvi".tr(*trans_table)
	if tr.start_with?('http')
		p $key # => 9
		puts tr # => enter
		break
	end
}