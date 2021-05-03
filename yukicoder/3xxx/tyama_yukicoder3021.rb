#!/usr/bin/ruby
gets.to_i.times{puts'select count(*) from point where %s<=x and x<=%s and %s<=y and y<=%s;'%gets.split}
__END__
select count(*) from point where (x between %s and %s) and (y between %s and %s);
