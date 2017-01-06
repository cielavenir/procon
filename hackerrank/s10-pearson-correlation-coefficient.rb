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
    mean_x = self.inject(0) { |s, a| s += a } / self.size.to_f
    mean_y = y.inject(0) { |s, a| s += a } / y.size.to_f

    # x と y の共分散の分子 (covariance)
    cov = self.zip(y).inject(0) { |s, a| s += (a[0] - mean_x) * (a[1] - mean_y) }

    # x の分散の分子, y の分散の分子 (variance)
    var_x = self.inject(0) { |s, a| s += (a - mean_x) ** 2 }
    var_y = y.inject(0) { |s, a| s += (a - mean_y) ** 2 }

    # 相関係数 (correlation coefficient)
    r = cov / Math.sqrt(var_x)
    r /= Math.sqrt(var_y)
	r.nan? ? 0 : r
  end
end

n=gets.to_i
a=gets.split.map(&:to_f)
b=gets.split.map(&:to_f)
puts '%.3f'%a.r(b)
