# Write your MySQL query statement below
select person_name
from
    (select 
        person_name,
        SUM(weight) over (order by turn) as cumulative_weight
    from queue) as t
where cumulative_weight <= 1000
order by cumulative_weight desc
LIMIT 1