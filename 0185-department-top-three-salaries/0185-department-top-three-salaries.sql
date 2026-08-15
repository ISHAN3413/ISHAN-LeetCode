# Write your MySQL query statement below
select d.name as Department ,  e.name as Employee , e.Salary 
from Employee e
join Department d
on e.departmentId = d.id
where(
    select count(distinct e2.salary)
    from Employee e2
    where e.departmentId = e2.departmentId
    and e2.salary>e.salary
)<3
order by e.departmentId asc;