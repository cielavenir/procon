#!/usr/bin/ruby
require 'prime'

# https://github.com/ChapterHouse/prime_miller_rabin
# Copyright (c) 2013 Frank Hall
# MIT License

class Prime::MillerRabin < Prime::PseudoPrimeGenerator
  def succ()
    self.last_prime = next_prime(last_prime || 1)
  end

  def rewind()
    self.last_prime = nil
  end

  def prime?(x)
    miller_rabin(x)
  end

  private

  attr_accessor :last_prime

  def likely_prime?(a, n)
    d = n - 1
    s = 0
    while d % 2 == 0 do
      d >>= 1
      s += 1
    end

    b = 1
    while d > 0
      u = d % 2
      t = d / 2
      b = (b * a) % n if u == 1
      a = a**2 % n
      d = t
    end

    if b == 1
      true
    else
      s.times do |i|
        return true if b == n - 1
        b = (b * b) % n
      end
      (b == n - 1)
    end
  end

  def miller_rabin(n)
    if n.abs < 2
      false
    else
      likely_prime = true
      # 26 Yields a probability of prime at 99.99999999999998% so lets kick it up a notch.
      27.times do |i|
        begin
          a = rand(n)
        end while a == 0
        likely_prime = likely_prime?(a, n)
        break unless likely_prime
      end
      likely_prime
    end
  end

  def next_prime(x)
    if x < 2
      2
    elsif x < 3
      3
    elsif x < 5
      5
    else
      x += (x.even? ? 1 : (x % 10 == 3 ? 4 : 2 ))
      x += (x % 10 == 3 ? 4 : 2 ) until x.prime?
      x
    end
  end
end

N=gets.to_i
if N>25
	p N%8==1&&Prime::MillerRabin.new.prime?(N-8) ? 14 : 8
else
	h={4=>3,6=>5,12=>11,14=>13,18=>8,20=>19,21=>19,24=>23,25=>23};h.default=7
	p h[N]
end