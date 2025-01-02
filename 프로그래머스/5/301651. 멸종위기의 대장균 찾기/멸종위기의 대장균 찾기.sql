-- 코드를 작성해주세요
with recursive rc AS (
    select ID, PARENT_ID, 1 as gen
    from ECOLI_DATA
    where PARENT_ID is null
    
    union all
    
    select A.ID, A.PARENT_ID, rc.gen + 1 as gen
    from ECOLI_DATA as A join rc 
    on A.PARENT_ID = rc.ID
)

#select * from rc

select count(id) as COUNT, gen as GENERATION
from rc
where id not in 
(
    select parent_id from rc
    where parent_id is not null
)
group by gen
