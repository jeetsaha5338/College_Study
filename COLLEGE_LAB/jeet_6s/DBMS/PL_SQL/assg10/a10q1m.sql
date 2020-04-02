DECLARE
	N NUMBER(20):=&N;
	C NUMBER(20);
BEGIN
	fact(N,C);
	DBMS_OUTPUT.PUT_LINE('factorial is='||C);
END;
/
	
	
