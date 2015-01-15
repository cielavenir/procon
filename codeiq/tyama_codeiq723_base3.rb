#!/usr/bin/ruby

module Enumerable
  # https://github.com/yhara/enumerable-lazy/blob/master/lib/enumerable/lazy.rb
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

    def reject(&block)
      Lazy.new(self){|yielder, val|
        if not block.call(val)
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
end if RUBY_VERSION<'2.0'

puts (1..Float::INFINITY).lazy.reject{|i|i.to_s(3).include?('2')}.take(100).to_a

__END__
Ruby
2.0以降を推奨しますが、ideoneで実行できるよう1.9互換としてあります。

3進数で表した時に2を含まないものを100個出力。Enumerable#rejectは配列を返すためlazy必須。

http://ideone.com/eUC0kn