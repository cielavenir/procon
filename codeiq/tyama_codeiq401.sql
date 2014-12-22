-- CODEIQ - VECTOR INNERPRODUCT IN SQL

-- CREATE A TABLE
create table U (
	row_id		integer,
	val_nr		integer);

-- CREATE B TAbLE
create table V (
	row_id		integer,
	val_nr		integer);

create table W (
	row_id		integer,
	col_id		integer,
	val_nr		integer);

-- LOAD FILE TO TABLES U AND V
delete from U;
delete from V;
delete from W;
\copy U from 'U.csv' with CSV HEADER;
\copy V from 'V.csv' with CSV HEADER;
\copy W from 'W.csv' with CSV HEADER;

-- SHOW VECTOR U
select row_id, val_nr from U;

-- SHOW VECTRE V
select row_id, val_nr from V;

-- SHOW VECTRE W
select row_id, col_id, val_nr from W;

------------------------------------------------------------------------
-- QUESTION 1 
-- VECTOR INNERPRODUCT OF U AND V
-- YOUR CODE IS HERE ---------------------------------------------------

select sum( U.val_nr*V.val_nr )
	from U, V
	where U.row_id = V.row_id;

------------------------------------------------------------------------


------------------------------------------------------------------------
-- QUESTION 2 
-- VECTOR PRODUCT OF MATRIX W AND VECTOR V 
-- YOUR CODE IS HERE ---------------------------------------------------

select W.row_id, sum( W.val_nr*V.val_nr )
	from W, V
	where W.col_id = V.row_id
	group by W.row_id
	order by W.row_id; -- output order is somehow strange here; order by is required.

------------------------------------------------------------------------