SELECT s.user_id,
       CASE 
           WHEN SUM(CASE WHEN c.action IN ('confirmed', 'timeout') THEN 1 ELSE 0 END) = 0 THEN 0
           ELSE ROUND(CAST(SUM(CASE WHEN c.action = 'confirmed' THEN 1 ELSE 0 END) AS FLOAT) / 
                SUM(CASE WHEN c.action IN ('confirmed', 'timeout') THEN 1 ELSE 0 END), 2)
       END AS confirmation_rate
FROM Signups AS s
LEFT JOIN Confirmations AS c ON s.user_id = c.user_id
GROUP BY s.user_id;
