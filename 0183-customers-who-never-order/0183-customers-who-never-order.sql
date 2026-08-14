# Write your MySQL query statement below
select c.name as Customers
from Customers c
left Join Orders o
ON c.id = o.customerID
WHERE o.id is NULL;