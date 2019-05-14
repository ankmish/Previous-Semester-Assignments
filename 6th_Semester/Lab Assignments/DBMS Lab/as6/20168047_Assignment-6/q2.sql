use db20168047;

create view Client_View1 as select * from `TABLE 19`;
create view Client_vw2 as select CLIENT_ID,CITY,BAL_DUE from `TABLE 19`;
create view Client_vw3 as select CLIENT_ID as CID,CLIENT_NAME as cname,ADDRESS as Addr from `TABLE 19`;
select CLIENT_NAME,BAL_DUE from Client_View1 where CLIENT_ID="cn01001";
insert into Client_vw2 values('cn02003','alld',5000);
update Client_vw2  set BAL_DUE=2000 where CLIENT_ID='cn01004';
delete from Client_vw2 where CLIENT_ID='cn02003';
drop view Client_vw3;
drop view Client_vw4;
create view Client_vw4 as select `TABLE 19`.CLIENT_ID,CLIENT_NAME,BAL_DUE,PHONE from `TABLE 19`,`TABLE 22` where `TABLE 19`.CLIENT_ID=`TABLE 22`.CLIENT_ID;
select * from Client_vw4;

