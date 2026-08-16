# Write your MySQL query statement below
select u.name , if(r.distance is null , 0 , r.distance) as travelled_distance
from Users u
left join (
    select user_id , sum(distance) as distance
    from Rides
    group by user_id
) r
on u.id = r.user_id
order by travelled_distance desc , u.name asc;
