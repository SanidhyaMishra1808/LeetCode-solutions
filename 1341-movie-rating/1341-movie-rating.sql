# Write your MySQL query statement below
WITH t AS (SELECT user_id,COUNT(*) AS results
FROM MovieRating
GROUP BY user_id),
t1 AS (SELECT * FROM t
       WHERE t.results=(SELECT MAX(results) FROM t)),
t2 AS (SELECT t1.user_id,u.name,t1.results FROM t1
JOIN Users u
ON t1.user_id=u.user_id),
t3 AS (SELECT t2.name FROM t2
        WHERE t2.name=(SELECT MIN(name) FROM t2)),
t4 AS (SELECT mr.movie_id,m.title,AVG(rating) AS Avg_1 FROM MovieRating mr
        JOIN Movies m
        ON mr.movie_id=m.movie_id
        WHERE MONTH(created_at)=2 AND YEAR(created_at)=2020
        GROUP BY movie_id),
t5 AS (SELECT * FROM t4
        WHERE Avg_1=(SELECT MAX(Avg_1) FROM t4)),
t6 AS (SELECT title FROM t5
        WHERE title=(SELECT MIN(title) FROM t5))
SELECT t3.name AS results FROM t3
UNION ALL
SELECT t6.title FROM t6