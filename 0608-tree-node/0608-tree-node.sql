# Write your MySQL query statement below
select id , 'Root' as type from Tree 
where p_id is null

union all

select id , 'Inner' as type from Tree
where id in (
    select t1.id from Tree t1
    join Tree t2
    on t1.id = t2.p_id
    and t1.p_id is not null
)

union all

select id , 'Leaf' as type from Tree
where id not in (
    select t1.id from Tree t1
    join Tree t2
    on t1.id = t2.p_id
)
and p_id is not null

;

