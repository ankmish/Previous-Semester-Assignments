Create   table   client (client_id   varchar(10) primary key,
                           client_name   char(20),
                           address varchar(15),
                           city char(15),
                           pin int,
                           state char(15),
                           bal_due DECIMAL(9,4)
                          );

Insert into client values('cn01001','alak roy','b.d.para','amarpur',799101,'tripura',390.9);
Insert into client values('cn01002','suman roy','puk para','agartala',799102,'tripura',2390.9);
Insert into client values('cn01004','priya das',' chora par','kamalpur',799301,'tripura',1390.9);
Insert into client values('cn01005','mita mia','kamal para','singur',799721,'tripura',190.9);
Insert into client values('cn01006','pulak roy','bircity','sonitpur',799141,'assam',110.9);
Insert into client values('cn01007','munni das','nappam','sonitpur',799152,'assam',190.9);
Insert into client values('cn01008','kusum roy','city_dos','tezpur',799141,'assam',110.9);
Insert into client values('cn01009','mina das','pachmile','tezpur',799152,'assam',190.9);
Insert into client values('cn01003','moytree nayak','pachmile','tezpur',799152,'assam',9990.9);
Insert into client values('cn01010','pauri mia','pachmile','tezpur',799152,'assam',2990.9);
Insert into client values('cn01011','manali das','satmile','tezpur',799154,'assam',3990.9);

