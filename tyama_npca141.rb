#!/usr/bin/ruby
if RUBY_VERSION<'2.0'
module Enumerable
  def lazy
    Lazy.new(self)
  end

  class Lazy < Enumerator
    def initialize(obj, &block)
      super(){|yielder|
        begin
          obj.each{|x|
            if block
              block.call(yielder, x)
            else
              yielder << x
            end
          }
        rescue StopIteration
        end
      }
    end

    def drop(n)
      dropped = 0
      Lazy.new(self){|yielder, val|
        if dropped < n
          dropped += 1
        else
          yielder << val
        end
      }
    end

    def take(n)
      taken = 0
      Lazy.new(self){|yielder, val|
        if taken < n
          yielder << val
          taken += 1
        else
          raise StopIteration
        end
      }
    end
  end
end
end

p Enumerator.new{|y|
	a,b=0,1
	loop{
		a,b=b,a+b
		y<<a
	}
}.lazy.drop(gets.to_i-1).take(1).to_a.last