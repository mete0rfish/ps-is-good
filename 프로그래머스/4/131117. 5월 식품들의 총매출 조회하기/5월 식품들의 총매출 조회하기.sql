select p.product_id, product_name, sum(o.amount*price) as TOTAL_SALES
from food_product p
    join food_order o
    on p.product_id = o.product_id
where o.produce_date like '2022-05%'
group by p.product_id
order by total_sales desc, p.product_id;
