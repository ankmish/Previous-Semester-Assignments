drop table Employee;
create table Employee(
  Emp_Name varchar(200),
  Street varchar(200),
  City varchar(200),
  primary key(Emp_Name)
)ENGINE = InnoDB;

drop table Company;
create table Company(
    Company_Name varchar(300),
  City varchar(200),
primary key(Company_Name)
)ENGINE = InnoDB;

drop table Works;
create table Works(
  Emp_Name varchar(200),
  Company_Name varchar(300),
  Salary integer
)ENGINE = InnoDB;
   --FOREIGN KEY (Emp_Name) REFERENCES Employee(Emp_name) ,
  -- FOREIGN KEY (Company_Name) REFERENCES Company(Company_Name) 

drop table Manages;
create table Manages(
    Emp_Name varchar(200),
    Manager_Name varchar(200),
    primary key(Manager_Name)
 
)ENGINE = InnoDB;
   -- FOREIGN KEY (Emp_Name) REFERENCES Employee(Emp_name) 

insert into Employee
values('John Smith','1/0B','Berkeley');
insert into Employee
values('Johnson', '22/T','Oakland');
insert into Employee
values('W.Wills', '56/P','San Francisco');
insert into Employee
values('Roger', '55/U','San Jose');
insert into Employee
values('Willams','77/Y','Stockton');
insert into Employee
values('Aprinam', '1/00B','Modesto');
insert into Employee
values('Herry', '1/1C','San Fresno');

insert into Company
values('First Bank Corporation1','Berkeley');
insert into Company
values('TCS','San Francisco');
insert into Company
values('IBM', 'San Jose');
insert into Company
values('First Bank Corporation2', 'Londan');
insert into Company
values('Small Bank Corporation1','Stockton');
insert into Company
values('First Bank Corporation3','Berkeley');
insert into Company
values('Small Bank Coporation2', 'Stockton');


insert into Works
values('John Smith','First Bank Corporation',700000);
insert into Works
values('Johnson', 'TCS',80000);
insert into Works
values('W.Wills', 'IBM',10000);
insert into Works
values('Roger', 'First Bank Corporation',500000);
insert into Works
values('Willams','Small Bank Corporation',56000);
insert into Works
values('Aprinam', 'First Bank Corporation',80000);
insert into Works
values('Herry', 'Small Bank Corporation',450000);



insert into Manages
values('John Smith','Jim Bentley');
insert into Manages
values('Johnson', 'Greth Ainsworth');
insert into Manages
values('Roger', 'Eddie Howe');
insert into Manages
values('Willams','Sean Dyche');
insert into Manages
values('Aprinam', 'Chris Will');

