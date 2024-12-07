select res.rest_id, rest_name, food_type, favorites, address, round(avg(review_score),2)
from rest_info as res, rest_review as rev
where res.rest_id = rev.rest_id
    and address like '서울%'
group by rev.rest_id
order by avg(review_score) desc, favorites desc;