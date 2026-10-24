# Write your MySQL query statement below
select product_id ,ROUND(IFNULL(total_money / total_units ,0),2) as average_price
from
(
select p.product_id as product_id ,SUM(p.price * us.units) as total_money ,SUM(us.units) as total_units
from prices p
left join unitsSold us on p.product_id=us.product_id
and  us.purchase_date >= p.start_date
and us.purchase_date <= p.end_date
group by p.product_id) as temp