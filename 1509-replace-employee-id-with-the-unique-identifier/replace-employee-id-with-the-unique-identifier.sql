SELECT
    (SELECT EmployeeUNI.unique_id
     FROM EmployeeUNI
     WHERE Employees.id = EmployeeUNI.id) AS unique_id,
    Employees.name
FROM Employees;


