SELECT 
    temp.contest_id, 
    ROUND((100 * temp.part / totalUsers.total_count), 2) AS percentage
FROM (
    SELECT 
        contest_id, 
        COUNT(*) AS part
    FROM Register
    GROUP BY contest_id
) AS temp
CROSS JOIN (
    SELECT 
        COUNT(*) AS total_count
    FROM Users
) AS totalUsers
group by contest_id
order by percentage DESC, contest_id ASC;
