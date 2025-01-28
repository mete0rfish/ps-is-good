select book_id, author_name, date_format(PUBLISHED_DATE,'%Y-%m-%d') as PUBLISHED_DATE
from book b join author a
on b.author_id = a.author_id
where b.category = '경제'
order by PUBLISHED_DATE;