drop table AREA;
create table AREA(
  Radius number(5) not null,
  Area number(7,3) not null
);
SET serveroutput ON;
DECLARE
 radius number(5);              
 area number(7,3);                
BEGIN 
  dbms_output.put_line('Radius  Area');

  for radius in  3..7
  loop
    area := (22*radius*radius)/7;
    dbms_output.put_line(radius || '       ' || area);
  insert into  AREA(Radius,Area) values (radius, area);
  end loop;
 
END;
/
select * from AREA;