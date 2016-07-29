SELECT * FROM enrollment_setup

update enrollment_setup set status = 3 where enrollment_setup_identifier != 'PRO-000770518'

select * from ns_email

BEGIN
  INSERT_ENROLLMENT_MAT();
END;

  select * from enrollment_setup_plan_view where product_category='medical';
  
  select * from exclusive_benefit;
  
  select * from system_config where key like '%dms%';
  update system_config set value = 'C:\TEMP' where key like '%dms_base_location%' ;
  
  
  select * from 