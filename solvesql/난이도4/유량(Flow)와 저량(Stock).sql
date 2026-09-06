/*
링크: https://solvesql.com/problems/flow-and-stock/
정답률 52.75% (854회 / 1619회)
*/

select
    year(acquisition_date) as "Acquisition year",
    count(year(acquisition_date)) as "New acquisitions this year (Flow)",
    sum(count(year(acquisition_date))) over(order by year(acquisition_date)) as "Total collection size (Stock)"
from artworks
group by 1
having count(year(acquisition_date)) > 0
order by 1

/*
회고:
이전 행까지의 합을 계산하기
*/