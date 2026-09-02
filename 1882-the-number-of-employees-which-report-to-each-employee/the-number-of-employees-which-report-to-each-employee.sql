# Write your MySQL query statement below
select e1.employee_id as employee_id,e1.name as name,count(*) as reports_count, ROUND(avg(e2.age)) as average_age
from employees e1 Inner join 
employees e2 on e1.employee_id=e2.reports_to
group by e1.employee_id
order by e1.employee_id 