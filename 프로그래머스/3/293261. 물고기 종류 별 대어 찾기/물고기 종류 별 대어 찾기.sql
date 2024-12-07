select id as ID, fish_name as FISH_NAME, length as LENGTH
from fish_info as f, fish_name_info as n
where f.fish_type = n.fish_type
and LENGTH = (
    select max(f2.length) from fish_info as f2
    where f.fish_type = f2.fish_type
)
order by id asc;