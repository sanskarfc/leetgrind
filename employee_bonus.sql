select name, bonus from 
Employee left join Bonus
on Employee.empId = Bonus.empId
where Bonus.bonus < 1000 or Bonus is null;
