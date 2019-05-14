
drop table CLIENT_MASTER;
Create table CLIENT_MASTER (Client_No number(10), Name varchar2(50),City varchar2(20),Profession varchar2(40),
	Bal_Due NUMBER(5)  );
insert into CLIENT_MASTER values(101,'James','London','Telephone Operator',50000  );
insert into CLIENT_MASTER values(102,'Richie','Paris','Bank Manager',80000);
insert into CLIENT_MASTER values(103,'John','Rome','Network Operator',10000 );


SET SERVEROUTPUT ON;
CREATE OR REPLACE PROCEDURE checkvalidity(x IN number)
AS
flag number(10) ;
BEGIN
  select count(*) into flag from CLIENT_MASTER where Client_No=x;
  if flag~=0 then
   dbms_output.put_line('Client  exist !!! ');
  else 
    dbms_output.put_line('Client doesnt  exist !!!  ');  
  end  if;
  
END;
/
DECLARE 
num number(10);
BEGIN
num := &num;
checkvalidity(num);
END;
/