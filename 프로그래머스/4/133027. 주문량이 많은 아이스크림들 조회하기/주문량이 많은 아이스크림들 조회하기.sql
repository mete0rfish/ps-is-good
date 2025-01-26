select flavor
from first_half h
join july j
using (flavor)
group by flavor
order by sum(h.total_order) + sum(j.total_order) desc
limit 3
;