create table Employee(
  eid varchar(20),
  ename varchar(20),
  age varchar(20),
  Salary integer,
  Gender varchar(20),
  City varchar(20),
  primary key(eid)
);
alter table Employee ENGINE = InnoDB;



insert into Employee
values('101','John Smith','45',100000,'M','Berkeley');
insert into Employee
values('102','Johnson','55',200000, 'M','Oakland');
insert into Employee
values('103','W.Wills','50', 55000,'M','San Francisco');
insert into Employee
values('104','Roger','45', 40000,'M','San Jose');
insert into Employee
values('105','April Willams','66',55000,'F','Stockton');
insert into Employee
values('106','Aprinam','44',60000,'F','Modesto');
insert into Employee
values('107','Herry','49', 57000,'M','San Fresno');


