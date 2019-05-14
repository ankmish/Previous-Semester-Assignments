set serveroutput on;
drop table emp;
create table emp(empid integer,emp_name varchar(100),mgr varchar(100));
insert into emp values(1001,'Anna',Null);
insert into emp values(1002,'Anthony','Anna');
insert into emp values(1003,'Andy','Sachin');
insert into emp values(1004,'Sam','Anna');
insert into emp values(1005,'Tom','Sam');
insert into emp values(1006,'Ricky','Sam');
insert into emp values(1007,'Sachin','Anna');
insert into emp values(1008,'Amy','Anthony');
insert into emp values(1009,'Christina','Anna');
insert into emp values(1010,'Jennifer','Anthony');

	
drop trigger third_trigger;
create trigger third_trigger;
before delete on emp
begin 
update set 
mgr = Null
where 
mgr like :OLD.emp_name
end ;
/
delete * from emp where empid = 1002;