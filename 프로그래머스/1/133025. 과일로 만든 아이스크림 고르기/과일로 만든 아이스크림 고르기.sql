select FLAVOR from first_half
where TOTAL_ORDER > 3000
and FLAVOR in (
    select flavor from ICECREAM_INFO
    where INGREDIENT_TYPE = 'fruit_based'
)
order by total_order desc;