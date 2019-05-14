SELECT * FROM `issue` WHERE i_date>='21-aug-18' and i_date<='29-aug-18';
SELECT author,title,COUNT(*) AS No_of_Books FROM `Book` GROUP BY author;
SELECT MAX(No_of_Books) FROM (SELECT COUNT(*) AS No_of_Books, publisher FROM Book GROUP BY publisher) AS t;
SELECT COUNT(*) AS Total_no_of_books FROM `Book`;
SELECT COUNT(*) AS No_of_books_issued FROM `issue` where s_roll='CS20164034';
UPDATE `Book` SET `author`='ABC' WHERE id='BK003';
SELECT DISTINCT `s_name` FROM `issue`,`Book` WHERE (SELECT id FROM Book WHERE Book.title='Databse Sys' and Book.author='E.Navathe')=issue.id;
SELECT s_department,COUNT(*) AS Total_no_of_books_issued FROM `issue` GROUP BY s_department;
SELECT * FROM `Book` WHERE subject='ora';
