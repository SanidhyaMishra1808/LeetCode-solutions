select
    round(count(a1.player_id) / (select count(distinct player_id) from Activity), 2)
    as fraction
from (
    select player_id, min(event_date) as first_day
    from Activity
    group by 1
) as a1
join Activity a2 
on datediff(a2.event_date, a1.first_day) = 1 
and a1.player_id = a2.player_id