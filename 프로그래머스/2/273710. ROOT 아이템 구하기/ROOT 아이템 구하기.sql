select ITEM_ID, ITEM_NAME
from ITEM_INFO 
where ITEM_ID in
(
select item_id from item_tree where parent_item_id is null
)
order by item_id