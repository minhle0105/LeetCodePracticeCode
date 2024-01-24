WITH orders_by_user AS (
    SELECT buyer_id, count(order_id) AS orders_in_2019 
    FROM Orders 
    WHERE order_date BETWEEN '2019-01-01' AND '2019-12-31'
    GROUP BY 1
)
SELECT user_id AS buyer_id, join_date, IFNULL(orders_in_2019, 0) AS orders_in_2019
FROM orders_by_user
RIGHT JOIN Users 
ON orders_by_user.buyer_id = Users.user_id ;

