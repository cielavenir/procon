#!/usr/bin/ruby
#I need to fix the answer. I shouldn't cite the code.

#https://github.com/rxaviers/codeeval/blob/master/open_challenges/hard/discount_offers.rb
QUALITY = :perfect
def biggest_SS(ss_table)
    # Objective:
    # For each product, get the most valuable SS. How? Give it to a customer
    # whom if you had given any other product, it wouldn't make that much value.
    #
    # Let's begin with the first product. For each customer, we calculate the ss
    # difference of giving him this product versus all other products. Then,  we
    # get the min of those differences. That's the same as getting the
    # difference from the first_product_ss to other_sses_max. With all the
    # customers' deltas in hand we are able to conclude which customer should
    # stay with the product.  It's the one whose benefit will be bigger (max).
    # The bigger the delta_ss, the bigger the value of giving this product to
    # customer_i.

    # On many customers
    if ss_table.size > 1
        # On many products
        if ss_table[0].size > 1
            delta_sses = ss_table.map {|customer_sses|
                first_product_ss = customer_sses[0]
                other_sses_max = customer_sses[1..-1].max
                delta_ss = first_product_ss - other_sses_max
            }
            if QUALITY == :fast
                max_delta_ss_customer_i = delta_sses.each_with_index.max[1]

                # The remaining_ss_table is the ss_table without the customer row a
                # without the product column.
                remaining_ss_table = []
                (0..ss_table.size-1).each {|customer_i|
                    remaining_ss_table<< ss_table[customer_i][1..-1] \
                        unless customer_i == max_delta_ss_customer_i
                }

                ss_table[max_delta_ss_customer_i][0] + biggest_SS(remaining_ss_table)
            elsif QUALITY == :perfect
                max_delta_ss = delta_sses.max
                max_delta_ss_customers_is = delta_sses.each_with_index.select {|v,k|
                    v == max_delta_ss
                }.transpose[1]

                # In case we have more than one max_delta_ss, try them all:
                max_delta_ss_customers_is.map {|max_delta_ss_customer_i|
                    # The remaining_ss_table is the ss_table without the customer row
                    # and without the product column.
                    remaining_ss_table = []
                    (0..ss_table.size-1).each {|customer_i|
                        remaining_ss_table<< ss_table[customer_i][1..-1] \
                            unless customer_i == max_delta_ss_customer_i
                    }

                    ss_table[max_delta_ss_customer_i][0] + biggest_SS(remaining_ss_table)
                }.max
            end
        # On one product
        else
            # Return the biggest ss left
            ss_table.transpose[0].max
        end
    # On one customer
    else
        ss_table[0][0]
    end
end

require 'rational'
while gets #DATA.gets
a,b=$_.chomp.split(';').map{|e|e.split(',').map{|f|f.tr(' ','')}}
ss=a.map{|e|
	customer=e.downcase
	customer_size=customer.count('a-z')
	vowels=customer.count('aeiouy')
	consonants=customer_size-vowels
	b.map{|f|
		product_size=f.count('A-Za-z')
		mul=customer_size.gcd(product_size)>1?1.5:1
		mul * (product_size%2==0 ? vowels*1.5 : consonants)
	}
}
#O(n!) solutions are not proper.
printf "%.2f\n", biggest_SS(ss)
end
__END__
Jeffery Lebowski,Walter Sobchak,Theodore Donald Kerabatsos,Jack Abraham,John Evans,Ted Dziuba,Jareau Wade,Rob Eroh,Mahmoud Abdelkader,Wenyi Cai,Justin Van Winkle,Gabriel Sinkin,Aaron Adelson,Peter Gibbons,Michael Bolton,Samir Nagheenanajar;Half & Half,Colt M1911A1,16lb Bowling ball,iPad 2 - 4-pack,Girl Scouts Thin Mints,Nerf Crossbow,Batman No. 1,Football - Official Size,Bass Amplifying Headphones,Elephant food - 1024 lbs,Three Wolf One Moon T-shirt,Dom Perignon 2000 Vintage,Widescreen Monitor - 30-inch,Red Swingline Stapler,Printer paper,Vibe Magazine Subscriptions - 40 pack
Jeffery Lebowski,Walter Sobchak,Theodore Donald Kerabatsos,Jack Abraham,John Evans,Ted Dziuba,Jareau Wade,Rob Eroh,Mahmoud Abdelkader,Wenyi Cai,Justin Van Winkle,Gabriel Sinkin,Aaron Adelson,Peter Gibbons,Michael Bolton,Samir Nagheenanajar;Half & Half,Colt M1911A1,16lb Bowling ball,iPad 2 - 4-pack,Girl Scouts Thin Mints,Nerf Crossbow,Batman No. 1,Football - Official Size,Bass Amplifying Headphones,Elephant food - 1024 lbs,Three Wolf One Moon T-shirt,Dom Perignon 2000 Vintage,Widescreen Monitor - 30-inch
Jack Abraham,John Evans,Ted Dziuba,Jareau Wade,Rob Eroh,Mahmoud Abdelkader,Wenyi Cai,Justin Van Winkle,Gabriel Sinkin,Aaron Adelson,Peter Gibbons,Michael Bolton,Samir Nagheenanajar;Half & Half,Colt M1911A1,16lb Bowling ball,iPad 2 - 4-pack,Girl Scouts Thin Mints,Nerf Crossbow,Batman No. 1,Football - Official Size,Bass Amplifying Headphones,Elephant food - 1024 lbs,Three Wolf One Moon T-shirt,Dom Perignon 2000 Vintage,Widescreen Monitor - 30-inch,Red Swingline Stapler,Printer paper,Vibe Magazine Subscriptions - 40 pack
Jack Abraham,John Evans,Ted Dziuba;iPad 2 - 4-pack,Girl Scouts Thin Mints,Nerf Crossbow
Jeffery Lebowski,Walter Sobchak,Theodore Donald Kerabatsos,Peter Gibbons,Michael Bolton,Samir Nagheenanajar;Half & Half,Colt M1911A1,16lb Bowling ball,Red Swingline Stapler,Printer paper,Vibe Magazine Subscriptions - 40 pack
Jareau Wade,Rob Eroh,Mahmoud Abdelkader,Wenyi Cai,Justin Van Winkle,Gabriel Sinkin,Aaron Adelson;Batman No. 1,Football - Official Size,Bass Amplifying Headphones,Elephant food - 1024 lbs,Three Wolf One Moon T-shirt,Dom Perignon 2000 Vintage