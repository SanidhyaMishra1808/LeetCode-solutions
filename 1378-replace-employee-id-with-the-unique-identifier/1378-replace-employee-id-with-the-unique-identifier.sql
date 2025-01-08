select unique_id as unique_id, name as name
from Employees e left join EmployeeUNI eu on e.id = eu.id