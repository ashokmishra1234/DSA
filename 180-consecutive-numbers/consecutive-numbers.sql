# Write your MySQL query statement below
select distinct num as consecutiveNums
from (select  num,
        LEAD(num,1) over(order by id) as next_num,
        LEAD(num,2) over(order by id) as next_next_num
        from logs) as t
where num=next_num and num=next_next_num

