SELECT * FROM Users
WHERE mail REGEXP '^[A-Za-z][A_Za-z0-9_.-]*@leetcode.com$' AND mail LIKE '%@leetcode.com';