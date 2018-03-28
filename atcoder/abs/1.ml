let a = Scanf.scanf "%d " (fun x -> x);;
let b = Scanf.scanf "%d" (fun x -> x);;

print_string (if (a * b) mod 2 = 1 then "Odd\n" else "Even\n")
