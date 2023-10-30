WITH max_revenue as (
    WITH invoices as (
     SELECT invoice_id, quantity * price as revenue FROM Products JOIN Purchases ON Products.product_id = Purchases.product_id
)

SELECT invoice_id, sum(revenue) as revenue from invoices GROUP BY 1 ORDER BY 2 DESC, 1 ASC LIMIT 1
)

SELECT Products.product_id, quantity, price * quantity as price
FROM Purchases
         JOIN max_revenue on Purchases.invoice_id = max_revenue.invoice_id
         JOIN Products on Purchases.product_id = Products.product_id
ORDER BY 1 DESC;