/*
미세먼지 수치의 계절간 차이
난이도 3
출제자 [데이터리안] 선미

정답율 55.00% (830회 / 1509회)
엔진: MySQL
*/

-- 정답
with T as (
  SELECT
    season,
    pm10,
    ROW_NUMBER() OVER(PARTITION BY season ORDER BY pm10) AS row_num,
    COUNT(*) OVER(PARTITION BY season) AS cnt
  FROM
  ( 
    select
      case 
        when month(measured_at) >= '3' and month(measured_at) <= '5' then 'spring'
        when month(measured_at) >= '6' and month(measured_at) <= '8' then 'summer'
        when month(measured_at) >= '9' and month(measured_at) <= '11' then 'autumn'
        else 'winter'
      end as season,
      pm10
    from measurements
  ) AS S
)
, A as (
  select
    season,
    ROUND(AVG(pm10), 2) AS pm10_average
  FROM T
  GROUP BY season
)
, M as (
  select
    season,
    AVG(pm10) AS pm10_median
  FROM T
  WHERE row_num IN (FLOOR((cnt+1) /2), FLOOR((cnt+2) /2))
  GROUP BY season
)
SELECT
  A.season,
  M.pm10_median,
  A.pm10_average
FROM A
INNER JOIN M
  ON A.season = M.season

/*
회고
- [중앙값 계산하기](https://datarian.io/blog/calculating-median-with-sql)
*/