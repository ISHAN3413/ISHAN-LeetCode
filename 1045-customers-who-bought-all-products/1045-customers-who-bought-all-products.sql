select customer_id from (
    select customer_id , count(distinct product_key) as cnt
    from Customer 
    group by customer_id
) cus
where cnt = (
    select count(*)from Product
);