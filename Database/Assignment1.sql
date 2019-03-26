use cdac;

insert into dual values('x');

select * from dual;

select sqrt(25.5) from dual;

CREATE TABLE dept(
  deptno int,
  dname  nVARCHAR(14),
  loc    nVarchar(13),
  CONSTRAINT pk_dept PRIMARY KEY (deptno));


CREATE TABLE emp(
  empno    int,
  ename    nVARCHAR(10),
  job      nVARCHAR(9),
  mgr      INT,
  hiredate DATE,
  sal      DECIMAL(7,2),
  comm     DECIMAL(7,2),
  deptno   INT,
  CONSTRAINT pk_emp PRIMARY KEY (empno),
  constraint fk_deptno foreign key (deptno) references dept(deptno)
);

CREATE TABLE salgrade(
  grade int,
  losal int,
  hisal int
);

CREATE TABLE bonus(
  ename nVARCHAR(10),
  job   nVARCHAR(9),
  sal   int,
  comm  int
);

--POPULATING DEPT TABLE
INSERT INTO dept VALUES(10, 'ACCOUNTING', 'NEW YORK'), 
					   (20, 'RESEARCH', 'DALLAS'), 
					   (30, 'SALES', 'CHICAGO'), 
					   (40, 'OPERATIONS', 'BOSTON');
select * from dept;


--POPULATING EMP TABLE
INSERT INTO emp VALUES(
 7839, 'KING', 'PRESIDENT', null,
 convert(datetime,'1981-11-17'),
 5000, null, 10);

INSERT INTO emp VALUES(
 7698, 'BLAKE', 'MANAGER', 7839,
 ('1-5-1981'),
 2850, null, 30);

INSERT INTO emp VALUES(
 7782, 'CLARK', 'MANAGER', 7839,
 '9-6-1981',
 2450, null, 10);

INSERT INTO emp VALUES(
 7566, 'JONES', 'MANAGER', 7839,
 ('2-4-1981'),
 2975, null, 20);

INSERT INTO emp VALUES(
 7788, 'SCOTT', 'ANALYST', 7566,
('13-JUL-87'),
 3000, null, 20);

INSERT INTO emp VALUES(
 7902, 'FORD', 'ANALYST', 7566,
('3-12-1981'),
 3000, null, 20 );

INSERT INTO emp VALUES(
 7369, 'SMITH', 'CLERK', 7902,
 convert(datetime,'1980-12-17'),
 800, null, 20 );

INSERT INTO emp VALUES(
 7499, 'ALLEN', 'SALESMAN', 7698,
 ('1981-2-20'),
 1600, 300, 30);

INSERT INTO emp VALUES(
 7521, 'WARD', 'SALESMAN', 7698,
 ('1981-2-22'),
 1250, 500, 30 );

INSERT INTO emp VALUES(
 7654, 'MARTIN', 'SALESMAN', 7698,
 ('1981-9-28'),
 1250, 1400, 30 );

INSERT INTO emp VALUES(
 7844, 'TURNER', 'SALESMAN', 7698,
 ('1981-8-9'),
 1500, 0, 30);

INSERT INTO emp VALUES(
 7876, 'ADAMS', 'CLERK', 7788,
 ('13-JUL-87'),
 1100, null, 20 );

INSERT INTO emp VALUES(
 7900, 'JAMES', 'CLERK', 7698,
 ('3-12-1981'),
 950, null, 30 );

INSERT INTO emp VALUES(
 7934, 'MILLER', 'CLERK', 7782,
 ('1982-1-23'),
 1300, null, 10 );

 select * from emp;

--POPULATION SALGRADE TABLE

INSERT INTO salgrade VALUES (1, 700, 1200),
							(2, 1201, 1400),
							(3, 1401, 2000),
							(4, 2001, 3000),
							(5, 3001, 9999);
select * from salgrade;

-- 1. List all employees who have a salary between 1000 and 2000.
select * from emp where sal between 1000 and 2000;

-- 2. List department numbers and names in department name order.
select dname, deptno from dept order by dname;

-- 3. Display all the different job types.
select job from emp group by job;

-- 4. Employees in departments 10 and 20 in alphabetical order of employee names.
select * from emp where deptno in(10,20) order by ename;

-- 5. List names and jobs of all clerks in department 20.
select ename, job from emp where job = 'clerk' and deptno=20;

-- 7. List the details of the employees who have a manager
select * from emp where isnull(mgr,0) != 0;

-- 8. Display the name and the total remuneration for all employees
select ename as Name, sal+isnull(comm,0) as Renumeration from emp;

-- 9. Display name, annual salary and commission of all sales people whose monthly salary is greater than their commission. The output should be ordered by salary highest first. If two or more employees have the same salary sort by employee name, within the highest salary order.
select ename as Name, sal*12 as "Annual Salary" from emp where sal > comm order by sal DESC, ename;

-- 10. List the employee names and their salaries increased by 15% and expressed as a whole number Display the employee name and job by concatenating them and give an appropriate heading.
select concat(ename, ' `s salary increased by 15% = ', sal*0.15) as 'Salary Increased by 15%' from emp;

--11. It has been discovered that the sales people in department 30 are not all male. Hence display the job of salesman as salesperson.
select ename as Name, 'Sales Person' as Job from emp where job = 'salesman' and deptno=30;

--12. List the minimum and maximum salary for each job type.
select job as Job, max(sal) as 'Maximum Salary', min(sal) as 'Minimum Salary' from emp group by job;

-- 13. Find out how many managers are there without listing them.
select count(*) from emp where isnull(mgr,0) != 0 group by mgr;

select * from emp;

-- 14. Find out the average salary and total remuneration for each job type.
select job as "Job", avg(sal) as "Average Salary", sal+isnull(comm, 0) as "Total Renumeration" from emp group by job;