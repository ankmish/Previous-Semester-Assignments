SET serveroutput ON;
DECLARE
 num varchar2(10);              
 len number(2);             
 revnum varchar2(10); 
BEGIN 
  dbms_output.put_line('Input Number');
  num := &num;
  len := length(num);
  for i in reverse 1.. len
  loop
    revnum := revnum||substr(num, i, 1);
  end loop;
  dbms_output.put_line('Original Number = ' || num);
  dbms_output.put_line('Reversed Number = ' || revnum);
END;
/