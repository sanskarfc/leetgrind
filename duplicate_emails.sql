select distinct e1.email as Email
from 
Person as e1 JOIN Person as e2
on e1.email = e2.email and e1.id != e2.id;
