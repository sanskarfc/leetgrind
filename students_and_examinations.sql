select temp.student_id, temp.student_name, temp.subject_name, sum(case when e.subject_name is not null then 1 else 0 end) as attended_exams from 
(select * from Students cross join Subjects) as temp LEFT JOIN Examinations as e
on temp.student_id = e.student_id and temp.subject_name = e.subject_name
group by temp.student_id, temp.subject_name
order by temp.student_id, temp.subject_name;
