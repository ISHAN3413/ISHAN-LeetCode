# Write your MySQL query statement below
select p.product_name , o.unit
from Products p
join (
    select product_id , sum(unit) as unit
    from Orders 
    where order_date >= '2020-02-01' and order_date<'2020-03-01'
    group by product_id 
) o
on p.product_id = o.product_id
where unit>=100;

