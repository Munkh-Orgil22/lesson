
create table tableIndexes(
	id int,
    test1 int,
    test2 varchar(50),
    test3 varchar(50),
    primary key (id)
);

select *from tableIndexes;

DELIMITER $$
CREATE PROCEDURE `northwind`.`insertRow` ()
BEGIN
	DECLARE i int default 1;
	while(i <= 15000000) do
		insert into tableIndexes(test1, test2, test3) values(i, "value1", "value2");
		set i = i + 1;
	end while;
END $$
DELIMITER ;

call insertRow()