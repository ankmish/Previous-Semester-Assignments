
drop table employee;
Create table employee (Emp_Id number(10), Name varchar2(50),Designation varchar2(20),Initial_Salary number(10),
	Monthly_raise_percent NUMBER(5),Date_of_hiring varchar2(20) );
insert into employee values(101,'Anna','HR',50000,5,'08-12-2018' );
insert into employee values(102,'Ricky','Manager',80000,10 ,'01-01-2019');
insert into employee values(103,'Sam','Team Leader',10000,2 ,'02-03-2019');
insert into employee values(104,'Tom','CEO',600000,4,'05-03-2019');

select * from employee;

SET SERVEROUTPUT ON;
CREATE OR REPLACE FUNCTION totalsalary 
RETURN NUMBER IS
  total NUMBER(10):= 0;
--DECLARE
ee_id employee.Emp_Id%type; 
e_name employee.name%type;
desg employee.Designation%type;
i_salary employee.Initial_Salary%type;
m_percent employee.Monthly_raise_percent%type;
dateh employee.Date_of_hiring%type;
temp NUMBER(10);
cursor cs  IS select * from employee;
BEGIN
  open cs;
  if cs%isopen then
  loop
  FETCH cs into ee_id,e_name,desg,i_salary,m_percent,dateh;
  EXIT WHEN cs%notfound;
  if cs%found then
     temp :=  i_salary + (m_percent*0.01*i_salary*6);
     total := total + temp;
  end if;
  end loop;
  end if;
  close cs;
  RETURN total;
END;
/
DECLARE 
tot NUMBER(10);
BEGIN
tot := totalsalary();
dbms_output.put_line('Total salary to be given : '||tot);
END;
/
