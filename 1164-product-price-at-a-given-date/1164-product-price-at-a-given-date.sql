# Write your MySQL query statement below
select p1.id as product_id , if(p2.price is null , 10 , p2.price) as price from
(select product_id as id from Products group by product_id) p1
left join (select d.id as id, p.new_price as price
from Products p
right join( 
select product_id as id , max(change_date) as cd
from Products
where change_date <= '2019-08-16'
group by product_id) d
on p.product_id = d.id and p.change_date = d.cd ) p2
on p1.id = p2.id
;