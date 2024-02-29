WITH temp AS (
    SELECT seller_id, SUM(price) AS total_price 
    FROM Sales 
    GROUP BY seller_id
),
max_price AS (
    SELECT MAX(total_price) AS max_price 
    FROM temp
)
SELECT seller_id 
FROM temp 
WHERE total_price = (SELECT max_price FROM max_price);
