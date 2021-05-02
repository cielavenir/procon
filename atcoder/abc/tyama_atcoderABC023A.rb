#!/usr/bin/ruby
p`dd`.chars.map(&:hex).reduce:+
__END__
p`dd`.sum-106