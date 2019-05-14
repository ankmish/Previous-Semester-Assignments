select monthly_salary/12 as monthly from (select Salary as monthly_salary from Employee2) as e;
select  max_age from (select max(age) as max_age from Employee2) as e;

drop temporary table emp_temp;
create temporary table emp_temp ( select e1.Salary from (select avg(Salary) as average_salary from Employee2) as e,Employee2 e1
where e1.Salary  > e.average_salary);
select * from emp_temp;
drop temporary table emp_temp1;

--or
select e1.Salary from Employee2 as e1,
    (select AVG(Salary) as avg_salary from Employee2) as e2
    where e1.salary > e2.avg_salary;


create temporary table emp_temp1 (select * from Employee2 where eid < 100 and Gender LIKE 'M');
select * from emp_temp1;

create temporary table emp_temp2 (select Salary from Employee2 order by Salary desc limit 2 );
select * from emp_temp2;
