set serveroutput on;
drop table Salary;
drop table Salary_new;
create table Salary(Emp_no integer,b_hra integer,tot_deduct integer,net_sal integer,gross_sal integer);
create table Salary_new(Emp_no integer,b_hra integer,tot_deduct integer,net_sal integer,gross_sal integer);
 
insert into Salary  values(300,400,500,600,700);
insert into Salary  values(1300,1400,1500,1600,1700);
insert into Salary  values(2300,2400,2500,2600,2700);

 drop trigger first_trigger;
CREATE OR REPLACE TRIGGER FIRST_TRIGGER 
BEFORE UPDATE ON SALARY 
FOR EACH ROW 
BEGIN
  insert into Salary_new values(:OLD.Emp_no,:OLD.b_hra,:OLD.tot_deduct,:OLD.net_sal,:OLD.gross_sal);
END;
/
update Salary set Emp_no = 500 where Emp_no =300;