SELECT 
    'Low Salary' AS category,
    COUNT(CASE WHEN a.income < 20000 THEN 1 END) AS accounts_count
FROM accounts a
UNION ALL
SELECT 
    'Average Salary' AS category,
    COUNT(CASE WHEN a.income BETWEEN 20000 AND 50000 THEN 1 END) AS accounts_count
FROM accounts a
UNION ALL
SELECT 
    'High Salary' AS category,
    COUNT(CASE WHEN a.income > 50000 THEN 1 END) AS accounts_count
FROM accounts a;