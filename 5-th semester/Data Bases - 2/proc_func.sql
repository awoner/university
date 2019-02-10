Хранимые подпрограммы создаются с помощью выражений CREATE PROCEDURE или CREATE FUNCTION. 
Хранимая подпрограмма вызывается, используя выражение CALL
функція повертає значення, процедура - ні 

CREATE FUNCTION имя_функции ([параметр_функции[,...]])
RETURNS тип
[характеристика ...] тело_подпрограммы

DELIMITER //
 CREATE PROCEDURE getAllProductsByCategory(category varchar(10))
   BEGIN
  	#продукти в яких кеатегорія "Shoes" 
	SELECT * FROM products where id_category = ( select id  from   categories where name = category );
   END //
 DELIMITER ;

call getAllProductsByCategory("Shoes");
call getAllProductsByCategory("Shirts");
call getAllProductsByCategory("Jeans");


--------------------------------
DELIMITER //
 CREATE FUNCTION getProductSellNumber() RETURNS int
   BEGIN
	RETURN  (SELECT sum(zebra2.orders_details.number) FROM zebra2.orders_details);
   END //
 DELIMITER ;

select getProductSellNumber() as "Number of sold products";