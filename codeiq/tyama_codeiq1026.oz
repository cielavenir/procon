% ozc -x
functor
import
	Application Open
define
	class TextFile from Open.file Open.text end
	Stdout = {New Open.file init(name:stdout)}

	proc {Fib N A B}
		if N<20 then
			{Stdout write(vs:","#B)}
			{Fib (N+1) B (A+B)}
		end
	end

	proc {Main}
		{Stdout write(vs:0)}
		{Fib 1 0 1}
	end

	{Main}
	{Application.exit 0}
end