-- 코드를 작성해주세요
select C.ID as ID
from ECOLI_DATA as A join
    (ECOLI_DATA as B join ECOLI_DATA as C on B.ID = C.PARENT_ID)
    on A.ID = B.PARENT_ID
where A.PARENT_ID is null
order by C.ID