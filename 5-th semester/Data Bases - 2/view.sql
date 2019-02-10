/*create VIEW sales2 as SELECT `products`.`id`,
    `products`.`id_category`,
    `products`.`id_brand`,
    `products`.`model`,
    `products`.`price`,
    `products`.`img_path`,
    `products`.`description`,
    sales.stock,
    products.price *0.01*(100-sales.stock) as "final price"
FROM `products` join sales on  products.id = sales.id_product;*/

select * from sales2;
INSERT INTO `sales`(`id_product`, `stock`) VALUES (18,10);
select * from sales2;