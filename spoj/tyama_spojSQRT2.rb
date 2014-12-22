require 'bigdecimal'
puts '1.'+BigDecimal.new(2).sqrt(50000).split[1][1..-1]