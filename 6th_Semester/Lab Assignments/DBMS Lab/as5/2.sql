create table Employee(
  Emp_Name varchar(20),
  Street varchar(20),
  City varchar(20),
  primary key(Emp_Name)
);
alter table Employee ENGINE = InnoDB;

create table Works(
  Emp_Name varchar(20),
  Company_Name varchar(20),
  Salary varchar(20),
  primary key(Emp_Name)
);
alter table Works ENGINE = InnoDB;

create table Company(
    Company_Name varchar(20),
  City varchar(20)
);
alter table Works ENGINE = InnoDB;

create table Manages(
    Emp_Name varchar(20),
    Manager_Name varchar(20)
);
alter table Manages ENGINE = InnoDB;


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


insert into Works
values('John Smith','First Bank Corporation','$700000');
insert into Works
values('Johnson', 'TCS','$80000');
insert into Works
values('W.Wills', 'IBM','$10000');
insert into Works
values('Roger', 'First Bank Corporation','$500000');
insert into Works
values('Willams','Small Bank Corporation','$56000');
insert into Works
values('Aprinam', 'First Bank Corporation','$780000');
insert into Works
values('Herry', 'Small Bank Coporation','$450000');


insert into Company
values('First Bank Corporation','Berkeley');
insert into Company
values('TCS','San Francisco');
insert into Company
values('IBM', 'San Jose');
insert into Company
values('First Bank Corporation', 'Londan');
insert into Company
values('Small Bank Corporation','Stockton');
insert into Company
values('First Bank Corporation','Berkeley');
insert into Company
values('Small Bank Coporation', 'Stockton');


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

