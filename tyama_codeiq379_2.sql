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

select A.row_id, B.col_id, sum( A.val_nr*B.val_nr ) as val_nr
	from A, B
	where A.col_id = B.row_id
	group by A.row_id, B.col_id
	order by A.row_id;

------------------------------------------------------------------------


------------------------------------------------------------------------
-- QUESTION 2 
-- MATRIX MULTIPLICATION OF COMPLEX NUMBER
-- YOUR CODE IS HERE ---------------------------------------------------

select A.row_id, B.col_id, sum( A.val_nr*B.val_nr-A.img_nr*B.img_nr ) as val_nr, sum( A.img_nr*B.val_nr+A.val_nr*B.img_nr ) as img_nr
	from A, B
	where A.col_id = B.row_id
	group by A.row_id, B.col_id
	order by A.row_id;

------------------------------------------------------------------------