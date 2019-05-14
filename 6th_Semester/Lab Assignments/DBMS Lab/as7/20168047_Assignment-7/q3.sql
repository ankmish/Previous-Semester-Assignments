drop table Account_Master;
Create table  Account_Master(acct_no number(5) primary key,acct_holder_name varchar2(10),balance number(10));
insert into Account_Master values(1,'John',1000);
insert into Account_Master values(2,'Denis',100);
insert into Account_Master values(3,'Albert',1100);
insert into Account_Master values(4,'Charles',700);
insert into Account_Master values(5,'Darwin',1700);
SET serveroutput ON;
DECLARE
 accno number(5);              
 bal number(10);              
BEGIN 
  dbms_output.put_line('Input account Number');
  accno := &accno;
  select balance into bal from Account_Master where acct_no like accno;
  if bal < 1000 then
    bal := bal-100;
  end if;
  dbms_output.put_line('New Balance' || bal);
  update Account_Master set balance = bal where acct_no like accno;
END;
/
select * from Account_Master;