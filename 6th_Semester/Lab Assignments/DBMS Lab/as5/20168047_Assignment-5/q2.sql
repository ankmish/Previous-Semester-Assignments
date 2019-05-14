--1
select Emp_Name from Works where Company_Name='First Bank Corporation';
--2
select Works.Emp_Name ,Employee.City from Employee,Works where Employee.Emp_Name=Works.Emp_Name and Works.Company_Name='First Bank corporation';
 --3
select Works.Emp_Name ,Employee.City ,Employee.Street from Employee,Works where Employee.Emp_Name=Works.Emp_Name and Works.Company_Name='First Bank corporation' and Works.Salary>'$1000000';
 --4
select Works.Emp_Name from Works,Employee,Company where Employee.City=Company.City and Works.Emp_Name=Employee.Emp_Name and Works.Company_Name=Company.Company_Name;
--5
select e1.Emp_Name from Employee as e1 ,Employee as e2,Manages as m 
     where e1.Emp_Name =m.Emp_Name and e2.Emp_Name =m.Manager_Name and e1.Street=e2.Street and e1.City=e2.City;
select Emp_Name from Works where Company_Name!='Small Bank Corporation';

select Emp_Name from Works where Salary > all(select Salary from Works where Company_Name='Small Bank Corporation');

 select Company_Name from Company where Company_Name in (select Company_Name from Company where Company_Name ='Small Bank Corporati');

