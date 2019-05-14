SET SERVEROUTPUT ON;
CREATE PROCEDURE findmin(x IN number,y IN number,z OUT number)
AS
BEGIN
IF x<y THEN
  z := x;
ELSE
  z := y;
END IF;
END;
/
DECLARE
a number;
b number;
c number;
BEGIN
a := &a;
b := &b;
findmin(a,b,c);
dbms_output.put_line('Minimum of 2 number is '||c);
END;
/