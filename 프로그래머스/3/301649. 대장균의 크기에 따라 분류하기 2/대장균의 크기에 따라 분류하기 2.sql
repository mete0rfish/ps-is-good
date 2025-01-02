select ID,
case
    when A.e_rank/A.total *100 <= 25 then 'CRITICAL'
    when A.e_rank/A.total *100 <= 50 then 'HIGH'
    when A.e_rank/A.total *100 <= 75 then 'MEDIUM'
    else 'LOW'
end as COLONY_NAME
from (
    select *,
        rank() over (order by SIZE_OF_COLONY desc) as e_rank,
        count(*) over () as total
    from ECOLI_DATA
) as A
order by ID