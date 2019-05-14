drop table customers;
Create table customers (ID number(10), name varchar2(10), age number(10), address varchar2(10), Salary Float );
insert into customers values(101,'John',32,'Lodan',20000.00);
insert into customers values(3,'Clerk',25,'Paris',15000.00);
insert into customers values(4,'Mark',22,'New York',85000.00);
insert into customers values(5,'Albert',29,'California',45000.00);

select * from customers;


SET SERVEROUTPUT ON;
CREATE OR REPLACE FUNCTION totalcustomers 
RETURN NUMBER IS
  total NUMBER(4):= 0;
BEGIN
  select count(*) into total from customers;
  RETURN total;
END;
/
DECLARE 
co number(4);
BEGIN
co := totalcustomers();
dbms_output.put_line('Total no. of customer : '||co);
END;
/