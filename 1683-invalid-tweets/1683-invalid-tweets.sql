# Write your MydSQL query statement below
select tweet_id
from tweets
where char_length(content)>15;