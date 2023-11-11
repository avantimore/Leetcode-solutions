SELECT
    customer_id,
    COUNT(v.visit_id) AS count_no_trans
FROM Visits v
WHERE NOT EXISTS (
    SELECT 1
    FROM Transactions t
    WHERE v.visit_id = t.visit_id
)
GROUP BY customer_id
HAVING COUNT(v.visit_id) > 0;
