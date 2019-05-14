use db20168069;
drop table if exists Participated;
drop table if exists Owns;
drop table if exists Accident;
drop table if exists Car;
drop table if exists Person;

create table Person(
  driverid varchar(20),
  Name varchar(20),
  Address varchar(20),
  primary key(driverid)
);
alter table Person ENGINE = InnoDB;

create table Car(
  Model varchar(20),
  Registration_ID varchar(20),
  Year varchar(20),
  primary key(Registration_ID)
);
alter table Car ENGINE = InnoDB;

create table Accident(
    Report_No varchar(20),
    Date date,
    Location varchar(20),
    primary key (Report_No)
    );
alter table Accident ENGINE = InnoDB;

create table Owns(
  Driver_ID varchar(20),
  License varchar(20),
  Registration_ID varchar(20),
  FOREIGN KEY (Registration_ID)
  REFERENCES Car(Registration_ID) ON DELETE CASCADE,
  FOREIGN KEY (Driver_ID)
  REFERENCES Person(driverid) ON DELETE CASCADE
)ENGINE='InnoDB';

create table Participated(
  Driver_ID varchar(20),
  Report_No varchar(20),
  Damage_Amount varchar(20),
  Registration_ID varchar(20),
  FOREIGN KEY (Report_No)
  REFERENCES Accident(Report_No) ON DELETE CASCADE,
  FOREIGN KEY (Driver_ID)
  REFERENCES Person(driverid) ON DELETE CASCADE
) ENGINE = InnoDB;


insert into Person
values('4001','John Smith','1/0 Berkeley');
insert into Person
values('4002','Johnson', '22/T Oakland');
insert into Person
values('4003','W.Wills', '56/P San Francisco');
insert into Person
values('4004','Roger', '55/U San Jose');
insert into Person
values('4005','Willams','77/Y Stockton');
insert into Person
values('4006','Aprinam', '1/00 Modesto');
insert into Person
values('4007','Herry', '1/1 San Fresno');


insert into Car
values('Hyundai','UK201B8','2001');
insert into Car
values('Toyota','US201B8', '2018');
insert into Car
values('Honda','UK208L8', '2009');
insert into Car
values('Audi','UK201V7', '2018');
insert into Car
values('Ford','UK201S8','2019');
insert into Car
values('BMW','UK2022Y', '2018');
insert into Car
values('Renault','UK7077K', '2009');

insert into Accident
values('AR2195','2019-01-02','Berkeley');
insert into Accident
values('AR2196','2018-12-22', 'Oakland');
insert into Accident
values('AR2197','2018-11-22', 'San Francisco');
insert into Accident
values('AR2198','2018-12-07', 'San Jose');
insert into Accident
values('AR2199','2018-12-09','Stockton');
insert into Accident
values('AR2200','2018-12-22', 'Modesto');
insert into Accident
values('AR2201','2018-11-01', 'Fresno');

insert into Owns
values('4001','AABB2000','UK201B8');
insert into Owns
values('4002','AAABB201', 'US201B8');
insert into Owns
values('4003','AAABC201', 'UK208L8');
insert into Owns
values('4004','AAABD202', 'UK201V7');
insert into Owns
values('4005','ABCS3212','UK201S8');

insert into Participated
values('4001','AR2195','$ 2000','UK201B8');
insert into Participated
values('4002','AR2196','$ 2200','UK208L8');
insert into Participated
values('4003','AR2197','$ 2500','UK201V7');
insert into Participated
values('4004','AR2198','$ 2675','UK201S8');
insert into Participated
values('4005','AR2199','$ 3500','UK201V7');
insert into Participated
values('4006','AR2200','$ 4000','UK2022Y');
insert into Participated
values('4007','AR2201','$ 200','UK2022Y');

