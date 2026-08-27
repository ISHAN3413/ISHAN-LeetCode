# Write your MySQL query statement below
select u.user_id as buyer_id , u.join_date , if(c.cnt is null , 0 , c.cnt) as orders_in_2019
from Users u
left join (
   select buyer_id as id , count(order_date) as cnt 
from Orders
where year(order_date) = 2019
group by buyer_id 
) c
on u.user_id = c.id
;