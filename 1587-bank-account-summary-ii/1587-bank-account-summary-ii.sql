# Write your MySQL query statement below
select u.name , t.amount as balance
from Users u
join(
    select account , sum(amount) as amount
    from Transactions
    group by account
) t
on t.account = u.account
where t.amount>10000;