select distinct a.CAR_ID, a.CAR_TYPE, floor(a.daily_fee*30*(1 - DISCOUNT_RATE/100)) as FEE
from car_rental_company_car a 
join car_rental_company_discount_plan b
    on a.car_type = b.car_type
join car_rental_company_rental_history c
    on a.car_id = c.car_id
    and b.duration_type = '30일 이상'
where a.car_type in ('세단', 'SUV')
    and a.car_id not in (
        select car_id from car_rental_company_rental_history
        where not (START_DATE > '2022-11-30' OR end_date < '2022-11-01')
    )
having fee >= 500000 AND fee < 2000000
order by 3 desc, 2, 1 desc;
