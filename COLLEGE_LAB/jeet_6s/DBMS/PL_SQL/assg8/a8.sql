DECLARE
	N NUMBER(20):='&N';
	C NUMBER(20):=1;
	X NUMBER(20):=0;
BEGIN
	X:=C*3;
	WHILE X < N
	LOOP
		DBMS_OUTPUT.PUT_LINE(X||',');
		C:=C+1;
		X:=C*3;
	END LOOP;
END;
/
	
	
