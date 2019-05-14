create table Person(
  Driver_ID varchar(20),
  Name varchar(20),
  Address varchar(20),
  primary key(Driver_ID)
);
alter table Person ENGINE = InnoDB;

create table Car(
  Model varchar(20),
  Registration_No varchar(20),
  Year varchar(20),
  primary key(Registration_No)
);
alter table Car ENGINE = InnoDB;

create table Accident(
    Report_No varchar(20),
    Date date,
    Location varchar(20),
    Primary key (Report_No)
);
alter table Accident ENGINE = InnoDB;

create table Owns(
  Driver_ID varchar(20),
  Registartion_No varchar(20),
Primary key (Registartion_No)
);
alter table Owns ENGINE = InnoDB;

create table Participated(
  Driver_ID varchar(20),
  Registration_No varchar(20),
  Report_No varchar(20),
  Damage_Amount varchar(20)
);

alter table Participated ENGINE = InnoDB;


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
values(' AR2196','2018-12-22', 'Oakland');
insert into Accident
values(' AR2197','2018-11-22', 'San Francisco');
insert into Accident
values(' AR2198','2018-12-07', 'San Jose');
insert into Accident
values(' AR2199','2018-12-09','Stockton');
insert into Accident
values(' AR2200','2018-12-22', 'Modesto');
insert into Accident
values(' AR2201','2018-11-01', 'Fresno');

insert into Owns
values('4001','UK201B8');
insert into Owns
values('4002', 'US201B8');
insert into Owns
values('4003','UK208L8');
insert into Owns
values('4004','UK201V7');
insert into Owns
values('4005','UK201S8');

insert into Participated
values('4001','UK201B8','AR2195','$ 2000');
insert into Participated
values('4002','US201B8','AR2196','$ 2200');
insert into Participated
values('4003','UK208L8','AR2197','$ 2500');
insert into Participated
values('4004','UK201V7','AR2198','$ 2675');
insert into Participated
values('4005','UK201S8','AR2199','$ 3500');
insert into Participated
values('4006','UK202Y8','AR2200','$ 4000');
insert into Participated
values('4007','UK9089Y','AR2201','$ 200');

