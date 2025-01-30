/* Write your T-SQL query statement below */
with cte as (
    select
        id, 
        num,
        id - rank() over (partition by num order by id asc) streak
    from
        logs
)
select distinct num as ConsecutiveNums 
from cte 
group by num, streak 
having count(*) >= 3