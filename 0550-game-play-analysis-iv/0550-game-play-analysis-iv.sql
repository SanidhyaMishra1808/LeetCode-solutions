with cte as(Select player_id,min(event_date) as first_date,(select count(DISTINCT player_id)from Activity) as total_count
from Activity
group by player_id)

Select round(sum(if(event_date = date_add(first_date, Interval 1 day),1,0))/total_count,2) as fraction
from Activity a
join cte c
on a.player_id = c.player_id