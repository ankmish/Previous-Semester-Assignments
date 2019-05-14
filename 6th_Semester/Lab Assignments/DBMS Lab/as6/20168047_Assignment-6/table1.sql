create table Employee2(
  eid integer,
  ename varchar(20),
  age integer,
  Salary integer,
  Gender varchar(20),
  City varchar(20),
  primary key(eid)
);
alter table Employee2 ENGINE = InnoDB;



insert into Employee2
values(101,'John Smith',45,100000,'M','Berkeley');
insert into Employee2
values(102,'Johnson',55,200000, 'M','Oakland');
insert into Employee2
values(103,'W.Wills',50, 55000,'M','San Francisco');
insert into Employee2
values(104,'Roger',45, 40000,'M','San Jose');
insert into Employee2
values(105,'April Willams',66,55000,'F','Stockton');
insert into Employee2
values(106,'Aprinam',44,60000,'F','Modesto');
insert into Employee2	
values(107,'Herry',49, 57000,'M','San Fresno');


