#bd from coursework - online shop
SELECT `products`.`id`,
    `products`.`id_category`,
    `products`.`id_brand`,
    `products`.`model`,
    `products`.`price`,
    `products`.`img_path`,
    `products`.`description`,
    sales.stock,
    products.price *0.01*(100-sales.stock) as "final price"
FROM `products` join sales on  products.id = sales.id_product;

#продукти в яких кеатегорія "Shoes" 
SELECT * FROM products where id_category = ( select id  from   categories where name = "Shoes" );

#замовлення на суму вище вартості середнього замовлення
SELECT  * from orders where amount > (SELECT avg(amount) from orders);

#клієнти що робили замовлення на суму вище вартості середнього замовлення
SELECT  * from clients where id in (select distinct `id_client` from orders where amount > (SELECT avg(amount) from orders));

#продукти та скільки їх куплено
select * from products join 
(SELECT id_product,sum(number) as kupleno  FROM zebra2.orders_details group by id_product) as tabl 
on products.id = tabl.id_product;


SELECT  * from orders where amount >  (SELECT max(price) from products);
SELECT  * from orders where amount > all (SELECT price from products);


