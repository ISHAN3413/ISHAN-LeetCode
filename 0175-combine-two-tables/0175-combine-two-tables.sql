# Write your MySQL query statement bel
select p.firstName as firstName , p.lastName as lastName , a.city as city , a.state
from Person p
left join Address a
on p.personId = a.personId;