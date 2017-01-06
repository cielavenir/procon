#!/usr/bin/ruby
#https://gist.github.com/komasaru/b56131a6385bf52bdd0a
class Array
  def r(y)
    # 以下の場合は例外スロー
    # - 引数の配列が Array クラスでない
    # - 自身配列が空
    # - 配列サイズが異なれば例外
    raise "Argument is not a Array class!"  unless y.class == Array
    raise "Self array is nil!"              if self.size == 0
    raise "Argument array size is invalid!" unless self.size == y.size

    # x の相加平均, y の相加平均 (arithmetic mean)
    mean_x = self.reduce(:+)/self.size.to_f
    mean_y = y.reduce(:+)/y.size.to_f

    # x と y の共分散 (covariance)
    cov = self.zip(y).reduce(0){|s,(a,b)|s+(a-mean_x)*(b-mean_y)}

    # x の分散, y の分散 (variance)
    var_x = self.reduce(0){|s,e|s+(e-mean_x)**2}
    var_y = y.reduce(0){|s,e|s+(e-mean_y)**2}

    # 相関係数 (correlation coefficient)
    r = cov / Math.sqrt(var_x*var_y)
	r.nan? ? 0 : r
  end

  def spearman(r)
    n=self.size
    a=self.zip(r).sort
    n.times{|i|a[i]<<i}
    a.sort_by!{|e|e[1]}
    a.map{|e|e[2]}.r([*0...n])
  end
end

n=gets.to_i
a=gets.split.map(&:to_f)
b=gets.split.map(&:to_f)
puts '%.3f'%a.spearman(b)
