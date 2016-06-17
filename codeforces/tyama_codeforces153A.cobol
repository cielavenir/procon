	identification division.
	program-id. codeforces153A.
	data division.
	working-storage section.
		77 n PIC 9(10).
		77 m PIC 9(10).
		77 s PIC z(10).
	procedure division.
	main.
		accept n.
		accept m.
		add n to m.
		move m to s.
		display s.
		stop run.