create or replace procedure fact(n in number,n1 out number) is
	F number:=1;
BEGIN
	for i in 1..n
	loop
		F:=F*i;
	end loop;
	n1:=F;
END;
/

