#!/usr/bin/ruby
puts (1..Float::INFINITY).lazy.reject{|i|i.to_s(3).include?('2')}.take(100).to_a

__END__
Ruby 2.0以降 (※ideoneは1.9のため実行できません)

3進数で表した時に2を含まないものを100個出力。Enumerable#rejectは配列を返すためlazy必須。