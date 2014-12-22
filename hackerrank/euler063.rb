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

    def map(&block)
      Lazy.new(self){|yielder, val|
        yielder << block.call(val)
      }
    end

    def drop_while(&block)
      dropping = true
      Lazy.new(self){|yielder, val|
        if dropping
          if not block.call(val)
            yielder << val
            dropping = false
          end
        else
          yielder << val
        end
      }
    end
    
    def take_while(&block)
      Lazy.new(self){|yielder, val|
        if block.call(val)
          yielder << val
        else
          raise StopIteration
        end
      }
    end
  end
end
end

N=gets.to_i
puts (1..1/0.0).each.lazy.drop_while{|i|i**N<10**(N-1)}.take_while{|i|i**N<10**N}.map{|i|i**N}.to_a