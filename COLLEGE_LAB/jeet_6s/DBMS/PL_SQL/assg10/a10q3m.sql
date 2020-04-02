DECLARE
	N NUMBER(20):=&N;
	C varchar2(20);
BEGIN
	prime(N,C);
	DBMS_OUTPUT.PUT_LINE(C);
END;
/
	
	
