#!/usr/bin/ruby
require 'prime'
puts (1..100).select{|e|e.prime_division.all?{|f|f[1].even?}}*','
#puts (1..100).select{|e|Math.sqrt(e).to_i**2==e}*','

__END__
フィードバックありがとうございました。折角なのでInteger#prime_divisionを使ってみます。
(素因数の指数+1)の積が約数の個数なので、素因数の指数が全て偶数になるとき(すなわち平方数であるとき)約数は奇数個、つまり裏返されたままとなります。
※1.prime_divisionは空配列なのでall?は真となります