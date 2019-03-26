use aspclass;
create table student (
	id int primary key identity,
	name varchar(40),
	rollNo varchar(10),
	year_ int,
	branch varchar(40)
);

insert into student values('Joey Tribbiane', '1221', 4, 'Acting');

select * from student;

-- INSERT PROCEDURE
create procedure addStudent
@name varchar(40),
@rollNo varchar(10),
@year int,
@branch varchar(40)

as 

insert into student values(@name, @rollNo, @year, @branch);

--exec addStudent 'Ross','1234', 4, 'Paleantology'

-- SELECT PROCEDURE
create procedure getStudents
as 
select * from student

--exec getStudents

-- DELETE Student
create procedure deleteStudent
@name varchar(40),
@rollNo varchar(10),
@year int,
@branch varchar(40)
as
delete from student where rollNo = @rollNo

-- UPDATE PROCEDURE
create procedure updateStudent
@name varchar(40),
@rollNo varchar(10),
@year int,
@branch varchar(40)
as
update student set name = @name, rollNo = @rollNo, year_ = @year, branch = @branch where rollNo = @rollNo