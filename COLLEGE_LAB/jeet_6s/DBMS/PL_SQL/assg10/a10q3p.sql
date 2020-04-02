create or replace procedure prime(N in number,V out varchar2) is
	f number(10):=0;
BEGIN
	for i in 2..N-1
	loop
		if N mod i =0 then
			f:=1;
			exit;	
		end if;
	END loop;
	if f=0 then
		V:='Prime';
	else
		V:='Not Prime';	
	end if;
END;
/

