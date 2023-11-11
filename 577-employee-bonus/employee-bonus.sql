# Write your MySQL query statement below

SELECT
    Employee.name,
    (SELECT bonus FROM Bonus WHERE Employee.empID = Bonus.empID) AS bonus
FROM Employee
WHERE (SELECT bonus FROM Bonus WHERE Employee.empID = Bonus.empID) < 1000 OR NOT EXISTS (SELECT 1 FROM Bonus WHERE Employee.empID = Bonus.empID);

