-- CODEIQ - MATRIX MULTIPLICATION IN SQL

-- CREATE A TABLE
create table A (
	row_id		integer,
	col_id		integer,
	val_nr		integer,
	img_nr		integer);

-- CREATE B TAbLE
create table B (
	row_id		integer,
	col_id		integer,
	val_nr		integer,
	img_nr		integer);

-- LOAD FILE TO TABLES A AND B
delete from A;
delete from B;
\copy A from 'A.csv' with CSV HEADER;
\copy B from 'B.csv' with CSV HEADER;

-- SHOW MATRIX A
select row_id, col_id, val_nr from A;

-- SHOW MATRIX B
select row_id, col_id, val_nr from B;

------------------------------------------------------------------------
-- QUESTION 1 
-- MATRIX MULTIPLICATION OF A AND B
-- YOUR CODE IS HERE ---------------------------------------------------
drop table C;
create table C (
	row_id		integer,
	col_id		integer,
	val_nr		integer,
	img_nr		integer);

create or replace function calc() returns void as $$
	declare
		i0 int;
		i0_max int;
		j0 int;
		j0_max int;
		i int;
		i_max int;
		a int;
		b int;
		x int;
	begin
		select into i0_max max(row_id) from A;
		select into j0_max max(col_id) from B;
		select into i_max max(col_id) from A;
		i0=0;
		loop
			i0=i0+1;
			j0=0;
			loop
				j0=j0+1;
				x=0;
				i=0;
				loop
					i=i+1;
					select into a val_nr from A where row_id=i0 and col_id=i;
					select into b val_nr from B where row_id=i and col_id=j0;
					a=coalesce(a,0);
					b=coalesce(b,0);
					x=x+a*b;
					exit when i=i_max;
				end loop;
				insert into C (row_id,col_id,val_nr) values (i0,j0,x);
				exit when j0=j0_max;
			end loop;
			exit when i0=i0_max;
		end loop;
	end;
$$ language plpgsql
;
select calc();
select row_id, col_id, val_nr from C;

------------------------------------------------------------------------


------------------------------------------------------------------------
-- QUESTION 2 
-- MATRIX MULTIPLICATION OF COMPLEX NUMBER
-- YOUR CODE IS HERE ---------------------------------------------------
drop table C;
create table C (
	row_id		integer,
	col_id		integer,
	val_nr		integer,
	img_nr		integer);

create or replace function calc() returns void as $$
	declare
		i0 int;
		i0_max int;
		j0 int;
		j0_max int;
		i int;
		i_max int;
		a int;
		b int;
		c int;
		d int;
		x int;
		y int;
	begin
		select into i0_max max(row_id) from A;
		select into j0_max max(col_id) from B;
		select into i_max max(col_id) from A;
		i0=0;
		loop
			i0=i0+1;
			j0=0;
			loop
				j0=j0+1;
				x=0;
				y=0;
				i=0;
				loop
					i=i+1;
					select into a val_nr from A where row_id=i0 and col_id=i;
					select into b img_nr from A where row_id=i0 and col_id=i;
					select into c val_nr from B where row_id=i and col_id=j0;
					select into d img_nr from B where row_id=i and col_id=j0;
					a=coalesce(a,0);
					b=coalesce(b,0);
					c=coalesce(c,0);
					d=coalesce(d,0);
					x=x+a*c-b*d;
					y=y+b*c+a*d;
					exit when i=i_max;
				end loop;
				insert into C (row_id,col_id,val_nr,img_nr) values (i0,j0,x,y);
				exit when j0=j0_max;
			end loop;
			exit when i0=i0_max;
		end loop;
	end;
$$ language plpgsql
;
select calc();
select row_id, col_id, val_nr, img_nr from C;
------------------------------------------------------------------------