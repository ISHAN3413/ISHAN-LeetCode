# Write your MySQL query statement below

select lb.book_id , lb.title , lb.author , lb.genre , lb.publication_year , br.cnt as current_borrowers
from library_books lb
join (
    select book_id,count(*) as cnt
from borrowing_records
where return_date is NULL
group by book_id
) br
on lb.book_id = br.book_id
where br.cnt = lb.total_copies
order by current_borrowers desc , title asc;
