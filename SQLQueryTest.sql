--สร้าง View ชื่อ STD1 เพื่อแสดงรายวิชา และจำนวนนักศึกษาที่ลงทะเบียน
create view STD1 as
select s.sbjName,COUNT(r.stdCode) as จำนวนที่ลง
from Registered r inner join Subject s
on r.sbjCode = s.sbjCode
group by s.sbjName;

--สร้าง View ชื่อ STD2 เพื่อแสดงรหัส ชื่อนักศึกษา รหัสสาขาวิชาที่ไม่ได้งลงทะเบียน
create view STD21 as
select stdCode,stdName,majorCode
from Student
where stdCode in
(select stdCode from Student
except
select stdCode from Registered);
--------------------------------------- ได้ 2 แบบ
create view STD22 as
select s.stdCode,s.stdName,s.majorCode
from Student s left outer join Registered r
on s.stdCode = r.stdCode
group by s.stdCode,s.stdName,s.majorCode
having COUNT(r.stdCode)=0;

-- แสดงนักศึกษาที่มี GPA มากสุด 5 คนแรก
select top 5 * from Student
order by GPA desc;

-- สร้าง View ชื่อ STD3 แสดงรหัสรายวิชาที่มีการลงทะเบียนมากสุด 3 ลำดับแรก
create view STD3 as
select top 3 r.sbjCode,s.sbjName,COUNT(r.stdCode) as จำนวนที่ลง
from Registered r inner join Subject s
on r.sbjCode = s.sbjCode
group by r.sbjCode,s.sbjName
order by COUNT(r.stdCode) desc;

alter TABLE Student
alter column address nvarchar(100);

--เพิ่ม column subcredit และอัพข้อมูลเป้นราคาค่าหน่วยกิต
alter table Subject
add price_net float
----------------------
update Subject set price_net = credit * 300

alter table Student
add constraint sex_check check (sex in ('F','M'))

alter table Subject
add constraint df_cred default(3)
for credit

--เพิ่มคอลัมน์ Tel ในตารางนักศึกษา เพื่อเก็ยข้อมูลเบอร์โทรศัพท์
--โดยมีการกำหนด contraint ให้ใส่ได้แต่ตัวเลข 0-9 จำนวน 10 หลัก
alter table Student
add TEL varchar(11),
constraint chl_tel check (TEL like replicate ('[0-9]',10))

alter table Student
drop column TEL