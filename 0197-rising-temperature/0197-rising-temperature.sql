# Write your MySQL query statement below
select w2.id as id
from weather w2
join weather w1
on datediff(w2.recordDate ,w1.recordDate) = 1
where w1.temperature<w2.temperature;