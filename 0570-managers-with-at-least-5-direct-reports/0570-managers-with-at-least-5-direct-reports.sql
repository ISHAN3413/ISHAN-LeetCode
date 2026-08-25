# Write your MySQL query statement below

select e.name as name from (
   select e1.name , e2.counting as counting from Employee e1
join (
    select managerId , count(id) as counting
    from Employee 
    group by managerId
) e2
on e1.id = e2.managerId 
) e
where e.counting>4
;