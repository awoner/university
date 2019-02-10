
DELIMITER //
CREATE PROCEDURE buildJson(INOUT product_list varchar(5000))
BEGIN
	DECLARE finished INT DEFAULT 0;
	DECLARE _id INT DEFAULT 0; 
	DECLARE _model VARCHAR(500) DEFAULT "";
	DECLARE _price FLOAT DEFAULT 0;
	DECLARE crs CURSOR FOR SELECT id, model, price FROM products;
	DECLARE CONTINUE HANDLER FOR NOT FOUND SET finished = 1;
	
	OPEN crs;
	
	get_json: LOOP
	
	FETCH crs INTO _id, _model, _price;
	IF finished = 1 THEN 
		SET product_list = SUBSTRING(product_list FROM 1 FOR CHAR_LENGTH(product_list) - 2);
		LEAVE get_json;
	END IF;
	
	SET product_list = CONCAT(product_list, "{'", _id, "':['", _model, "', '", _price, "']}, "); #build json list
	
	END LOOP get_json;
	
	CLOSE crs;	
END //
DELIMITER ;


SET @initial_json = "";
CALL buildJson(@initial_json);
SELECT @initial_json;