select project_id, round(total_years/total_people, 2) as average_years from (select p.project_id, sum(e.experience_years) as total_years, count(p.employee_id) as total_people from
Project as p left join Employee as e
on p.employee_id = e.employee_id
group by p.project_id) as temp;
