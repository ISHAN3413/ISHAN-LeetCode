# Write your MySQL query statement below
select round(((
    select count(distinct a1.player_id) from Activity a1
join (
    select player_id , min(event_date) as event_date
    from Activity
    group by player_id
) a2
on a1.player_id = a2.player_id
where a1.event_date = DATE_ADD(a2.event_date, INTERVAL 1 DAY)
)/(
    select count(distinct player_id) from Activity
)),2)  as fraction ;