# Write your MySQL query statement below
WITH 
June AS
(
SELECT c.customer_id, name, country, order_id, order_date, p.price * o.quantity AS 'Total_spend' 
    FROM Customers c 
        JOIN Orders o ON c.customer_id = o.customer_id 
        JOIN Product p on o.product_id = p.product_id 
    WHERE (
            (MONTH(order_date) = 6) AND 
            (YEAR(order_date) = 2020)
        )
), 
July AS
(
SELECT c.customer_id, name, country, order_id, order_date, p.price * o.quantity AS 'Total_spend' 
    FROM Customers c 
        JOIN Orders o ON c.customer_id = o.customer_id 
        JOIN Product p on o.product_id = p.product_id 
    WHERE (
            (MONTH(order_date) = 7) AND 
            (YEAR(order_date) = 2020)
        )
), 
Qualified_June AS
(
SELECT customer_id, SUM(Total_spend) AS 'Amount' 
    FROM June 
        GROUP BY 1 
            HAVING SUM(Total_spend) >= 100
), 
Qualified_July AS
(
SELECT customer_id, SUM(Total_spend) AS 'Amount' 
    FROM July 
        GROUP BY 1 
            HAVING SUM(Total_spend) >= 100
)

SELECT june.customer_id, c.name 
    FROM Qualified_June june 
        JOIN Qualified_July july ON june.customer_id = july.customer_id 
        JOIN Customers c ON june.customer_id = c.customer_id;
