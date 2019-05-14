--1
Select count(DISTINCT Owns.Driver_ID) from Accident,Participated,Owns 
 where Participated.Driver_ID = Owns.Driver_ID and Accident.Report_No=Participated.Report_No and YEAR(Date)=2018;

--2
select count(Distinct aa.Report_No) from Accident as aa,Participated as pp,Person as p
 where aa.Report_No=pp.Report_No and pp.Driver_ID=p.Driver_ID and p.Name='John Smith';

--3
insert into Person values(4008,'Babu Lal','56/U Uttar Pradesh');
insert into Accident values('AR2222','2019-01-31','Uttar Pradesh');
insert into Owns values(4008,'UK2022Y');
insert into Participated select  Owns.Driver_ID,Car.Registration_No,Accident.Report_No,'$ 3400' from Person,Owns,Accident,Car where Person.Name='Babu Lal'   
	and Person.Driver_ID=Owns.Driver_ID and Owns.Registration_No=Car.Registration_No and Accident.Report_No='AR2222';


-- 4
delete from Owns where Owns.Driver_Id in (select Driver_Id from Person where Person.Name = "John Smith") and 
Owns.Registration_No in (select Registration_No from Car where Car.Model = "Hyundai");


--5
Update Participated set Participated.Damage_Amount='$ 3000' where 
Participated.Registration_No='AABB2000' and Participated.Report_No='AR2197';


--6
select count(Report_No),Date from Accident group by Date;



-- 7
select Name,A1.Date from Person,Accident as A1,Accident as A2 where A1.Date=A2.Date and 
A1.Report_No <> A2.Report_No and Person.Driver_Id in (select Driver_Id from Participated,Accident where 
Participated.Report_No = A1.Report_No);


--8
select Person.Name,Person.Address,Accident.Location from Person,Accident,Participated where Participated.Damage_Amount>'$ 2200' 
and Participated.Driver_ID=Person.Driver_ID and Participated.Report_No=Accident.Report_No;






   



select count(DISTINCT Owns.Driver_ID) from Person,Owns,Participated,Accident
where Person.Driver_ID=Owns.Driver_ID AND Owns.Registartion_No=Participated.Registration_No  AND YEAR(Date)=2018;
