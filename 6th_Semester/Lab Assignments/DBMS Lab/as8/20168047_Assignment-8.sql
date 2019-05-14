drop table Employee_Detail;
Create table  Employee_Detail(eid number(5) primary key,first_name varchar2(10),last_name varchar2(10),salary number(10),dept_id number(2));
insert into Employee_Detail values(1,'John', 'aaa1',10000,11);
insert into Employee_Detail values(2,'Dennis', 'b1',8000,12);
insert into Employee_Detail values(3,'Albert', 'c1',11000,13);
insert into Employee_Detail values(4,'Charles', 'd1',7000,14);
insert into Employee_Detail values(5,'Richard', 'e1',17000,15);

drop table Department;
Create table Department ( Dept_name varchar2(10), Manager_id number(4), dept_id number(5) );
insert into Department values('LMNT',111,11);
insert into Department values('SRTC', 222,12);
insert into Department values('STORE', 333,13);
insert into Department values('TEST', 444,14);
insert into Department values('ENQIRY', 555,15);

SET serveroutput ON;
DECLARE
ee_id Employee_Detail.eid%type; 
f_name Employee_Detail.first_name%type; 
l_name Employee_Detail.last_name%type;  
salary Employee_Detail.salary%type;
d_id Employee_Detail.dept_id%type;
cursor cs  IS select * from Employee_Detail;
BEGIN 
open cs;
loop
FETCH cs into ee_id,f_name,l_name,salary,d_id;
EXIT WHEN cs%notfound;
dbms_output.put_line(ee_id||' '||f_name||' '||l_name||' '||salary||' '||d_id);
end loop;
close cs;
end;
/

SET serveroutput ON;
DECLARE
BEGIN 
FOR loop_emp IN
(
    SELECT first_name,salary,Employee_Detail.dept_id,Dept_name 
    FROM Employee_Detail INNER JOIN Department ON Employee_Detail.dept_id=Department.dept_id
    WHERE salary>5000
)  
LOOP
    dbms_output.put_line(loop_emp.first_name||' '||loop_emp.salary||' '||loop_emp.dept_id||' '||loop_emp.Dept_name);
  END LOOP;
end;
/


SET serveroutput ON;
DECLARE
ee_id Employee_Detail.eid%type; 
f_name Employee_Detail.first_name%type; 
l_name Employee_Detail.last_name%type;  
salary Employee_Detail.salary%type;
d_id Employee_Detail.dept_id%type;
cursor cs  IS select * from Employee_Detail where salary>8000;
BEGIN 
open cs;
loop
FETCH cs into ee_id,f_name,l_name,salary,d_id;
EXIT WHEN cs%notfound;
dbms_output.put_line(ee_id||' '||f_name||' '||l_name||' '||salary||' '||d_id);
end loop;
close cs;
end;
/

SET serveroutput ON;
DECLARE
ee_id Employee_Detail.eid%type; 
f_name Employee_Detail.first_name%type; 
l_name Employee_Detail.last_name%type;  
salary Employee_Detail.salary%type;
d_id Employee_Detail.dept_id%type;
cursor cs  IS select * from Employee_Detail order by salary DESC FETCH NEXT 6 ROWS ONLY;
BEGIN 
open cs;
loop
FETCH cs into ee_id,f_name,l_name,salary,d_id;
EXIT WHEN cs%notfound;
dbms_output.put_line(ee_id||' '||f_name||' '||l_name||' '||salary||' '||d_id);
end loop;
close cs;
end;
/

SET serveroutput ON;
DECLARE 
e_id Employee_Detail.eid%type; 
f_name Employee_Detail.first_name%type; 
l_name Employee_Detail.last_name%type;  
sal Employee_Detail.salary%type;
d_id Employee_Detail.dept_id%type;

cursor cs  IS select  * from Employee_Detail;
BEGIN 
open cs;
if cs%isopen then
loop
FETCH cs into e_id,f_name,l_name,sal,d_id;
EXIT WHEN cs%notfound;
if cs%found then
  if sal<=9000 then
   sal := sal + 1000;
    update Employee_Detail set salary = sal  where e_id=Employee_Detail.eid;
   end if;
   dbms_output.put_line(sal);
end if;
end loop;
end if;
close cs;
end;
/
select * from Employee_Detail;
