select concat('/home/grep/src/', a.board_id, '/', file_id,file_name,file_ext) as FILE_PATH
from used_goods_file a, used_goods_board b
where a.board_id = b.board_id
and b.views = 
(
    select max(views)
    from used_goods_board
)
order by file_id desc;