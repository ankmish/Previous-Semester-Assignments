drop table if exists sales;
create table sales(orderId integer,
	orderDate varchar(20),
	orderPrice integer,
	orderQuantity integer,
	customerName varchar(20));

insert into sales values(1,'12/22/2005',160,2,'Smith');
insert into sales values(2,'08/10/2005',190,2,'Johnson');
insert into sales values(3,'07/13/2005',500,5,'Baldwin');
insert into sales values(4,'07/15/2005',420,2,'Smith');
insert into sales values(5,'12/22/2005',1000,4,'Wood');
insert into sales values(6,'10/02/2005',820,4,'Smith');
insert into sales values(7,'11/03/2005',2000,2,'Baldwin');
insert into sales values(8,'12/22/2002',1000,4,'Wood');
insert into sales values(9,'12/29/2004',5000,4,'Smith');


drop table if exists products;
create table products(	
	productId varchar(10),
	orderId integer,
	manufactureDate varchar(15),
	rawMaterial varchar(10),
	vendorId integer);

insert into products values('AZ145',2,'12/23/2005','Steel',1);
insert into products values('CS784',4,'11/28/2005','Plastic',2);
insert into products values('AZ147',6,'08/15/2002','Steel',3);
insert into products values('FD344',3,'11/03/2005','Milk',1);
insert into products values('GR233',3,'11/30/2005','Pulses',2);
insert into products values('FD123',2,'10/03/2005','Milk',2);
insert into products values('CS783',1,'11/03/2004','Plastic',2);
insert into products values('CS435',5,'11/04/2001','Steel',1);
insert into products values('GR567',6,'09/03/2005','Pulses',2);
insert into products values('FD267',5,'21/03/2002','Bread',4);
insert into products values('FD333',9,'12/12/2001','Milk',1);


drop table if exists vendor_info;
create table vendor_info(
	vendorId integer,
	vendorName varchar(20));
insert into vendor_info(vendorId,vendorName) values(1,'Smith');
insert into vendor_info(vendorId,vendorName) values(2,'Wills');
insert into vendor_info(vendorId,vendorName) values(3,'Johnson');
insert into vendor_info(vendorId,vendorName) values(4,'Roger');
	

drop table if exists vendors;
create table vendors(
	rawMaterial varchar(10),
	vendor varchar(10),
	vendorId integer);
insert into vendors values('Steel','Smith',1);
insert into vendors values('Plastic','Wills',2);
insert into vendors values('Steel','Johnson',3);
insert into vendors values('Milk','Smith',1);
insert into vendors values('Pulses','Wills',2);
insert into vendors values('Bread','Roger',4);
insert into vendors values('Bread','Wills',2);
insert into vendors values('Milk','Wills',2);



select productId,manufactureDate,rawMaterial,vendorId,orderDate,orderPrice,orderQuantity,customerName from products,sales 
	where	substring(manufactureDate,7,4)=substring(orderDate,7,4) and products.orderId=sales.orderId;

--b
select productId,manufactureDate,rawMaterial, orderDate,orderPrice,orderQuantity,customerName,vendorName from products,sales,vendor_info 
	where substring(manufactureDate,7,4)=substring(orderDate,7,4) and products.orderId=sales.orderId and products.vendorId=vendor_info.vendorId 
		and vendorName='Smith';


--b
select productId,manufactureDate,rawMaterial, orderDate,orderPrice,orderQuantity,customerName,vendorName from products 
INNER JOIN sales ON products.orderId=sales.orderId 
INNER JOIN vendor_info ON products.vendorId=vendor_info.vendorId 
where vendorName='Smith' AND substring(manufactureDate,7,4)=substring(orderDate,7,4);


select orderDate,sum(orderQuantity) as sumquantity from sales group by substring(orderDate,7,4);


select substring(orderDate,7,4) as orderYear_Wills,sum(orderQuantity) as sumQuantity from sales,products,vendor_info where
	sales.orderId=products.orderId and products.vendorId=vendor_info.vendorId and vendorName='Wills' group by substring(orderDate,7,4);
select substring(orderDate,7,4),count(orderDate)  from sales INNER JOIN products ON sales.orderId=products.orderId
INNER JOIN vendor_info ON products.vendorId=vendor_info.vendorId
where vendorName='Wills'
group by substring(orderDate,7,4);



select vendorName from vendor_info where vendorName in (select customerName from sales);
select distinct(vendorName) from vendor_info INNER JOIN sales ON vendor_info.vendorName=sales.customerName;


select rawMaterial,substring(orderDate,7,4) as orderYear,sum(orderQuantity) as sumQuantity from sales,products where
	(rawMaterial='Milk' or rawMaterial='Bread' or rawMaterial='Pulses') and sales.orderId=products.orderId group by substring(orderDate,7,4),rawMaterial;

select rawMaterial,substring(orderDate,7,4) as orderYear,sum(orderQuantity) as sumQuantity from sales,products where
	rawMaterial='Bread' and sales.orderId=products.orderId group by substring(orderDate,7,4),rawMaterial;

select productId from products,sales,vendor_info where 
	vendor_info.vendorId=products.vendorId and products.orderId=sales.orderId and vendorName!=customerName;

select rawMaterial,customerName from sales,products,vendor_info where
	rawMaterial='Milk' and sales.orderId=products.orderId and products.vendorId=vendor_info.vendorId and vendorName='Smith';
	
select substring(orderDate,7,4) as orderYear_Vendor,sum(orderQuantity) as sumQuantity,vendorName from sales,products,vendor_info where
	sales.orderId=products.orderId and products.vendorId=vendor_info.vendorId group by substring(orderDate,7,4),products.vendorId;




-- disable sql_mode=only_full_group_by
set global sql_mode='STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION';
set session sql_mode='STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION';