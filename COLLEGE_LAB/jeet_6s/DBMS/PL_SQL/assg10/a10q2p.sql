create or replace procedure lyear(N in number,V out varchar2) is

BEGIN
	IF N MOD 400=0 OR N MOD 4=0 AND N MOD 100!=0 THEN 
		V:='LEAP YEAR';
	ELSE
		V:='NOT LEAP YEAR';
	END IF;


END;
/

