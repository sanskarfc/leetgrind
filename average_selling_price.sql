select product_id, case when round(total_price/total_units, 2) is null then 0 else round(total_price/total_units, 2) end as average_price from (select p.product_id, sum(u.units) as total_units, sum(u.units * p.price) as total_price from
(Prices as p) left join (UnitsSold as u)
on p.product_id=u.product_id and p.start_date <= u.purchase_date and p.end_date >= u.purchase_date
group by p.product_id) as temp;
