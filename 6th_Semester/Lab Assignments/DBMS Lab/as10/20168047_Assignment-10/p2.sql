set serveroutput on;
drop table Employee;
create table Employee(Emp_no integer,Emp_name varchar(100) ,street varchar(200),city varchar(100));
  insert into Employee values(300,'Muskan','dsff','fgfdg');
  select * from Employee;
  drop trigger sec_trigger;
  
CREATE OR REPLACE TRIGGER SEC_TRIGGER 
AFTER UPDATE ON EMPLOYEE 
--REFERENCING OLD AS o NEW AS n 
FOR EACH ROW 
BEGIN
  dbms_output.put_line(:OLD.Emp_name ||'new name is ' || :NEW.Emp_name);
END;
/
 update Employee set Emp_name = 'MuskanSri' where Emp_no =300;