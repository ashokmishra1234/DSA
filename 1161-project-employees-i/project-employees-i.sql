# Write your MySQL query statement below
select p.project_id as project_id ,ROUND(sum(e.experience_years)/Count(*),2) as average_years
from project p
left join employee e
on p.employee_id=e.employee_id
group by p.project_id
