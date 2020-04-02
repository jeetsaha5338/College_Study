						project

project by hive=================

mkdir hivesummer18
cd hivesummer18
hive
create database project;
show databases;
use project;
set hive.cli.print.current.db=true;

hadoop fs -cp /user/edureka/startup_output/part-r-00000 /user/edureka/hivedata1/startup;


create table startup(SNo number(4),Date number(4) , StartupName varchar2(30), IndustryVertical varchar2(50) , CityLocation varchar2(20) , InvestorsName varchar2(50),InvestmentType varchar2(50) , AmountInUSD number(1))
row format delimited 
fields terminated by ',' 
location '/user/edureka/hivedata1/startup';

q1=======

create table q11 as select date,count(date) as count_all,IndustryVertical as ver from startup1 where sno!='SNo' group by date,IndustryVertical; 

create table q12 as select date,count(date) as count_1,IndustryVertical as ver from startup1 where sno!='SNo' and amountinusd=' 1' group by date,IndustryVertical; 

create table q1 as select a.date, a.count_all, b.count_1, a.ver from q11 a join q12 b on (a.ver = b.ver and a.date = b.date);

select * from q1 where ((count_1/count_all)>0.5 and count_1>10 and ver !=' null ') group by ver,date,count_1,count_all;


 Consumer Internet 	2016	305	539
 Consumer Internet 	2017	156	233
 ECommerce 		2016	21	38
 ECommerce 		2017	11	15
 Education 		2016	14	19
 Technology 		2016	120	190
 Technology 		2017	69	123
 eCommerce 		2016	80	125
 eCommerce 		2017	32	45





q2=======


create table q21 as select citylocation,count(citylocation) from startup1 where sno!='SNo' group by citylocation;
create table q22 as select citylocation,count(citylocation) from startup1 where sno!='SNo' and amountinusd=' 1' group by citylocation;

create table q2 as select a.citylocation, a.count_all, b.count_1 from q21 a join q22 b on (a.citylocation = b.citylocation);

select * from q2 where ((count_1/count_all)>0.5 and count_1>10 and citylocation !=' null ');

 Ahmedabad 	35	25
 Bangalore 	625	415
 Chennai 	66	49
 Gurgaon 	240	169
 Hyderabad 	75	56
 Mumbai 	442	306
 New Delhi 	381	223
 Noida 		78	47
 Pune 		84	55


q3==========


create table q31 as select IndustryVertical,count(IndustryVertical) as count_all from startup1 where sno!='SNo' group by IndustryVertical;
create table q32 as select IndustryVertical,count(IndustryVertical) as count_1 from startup1 where sno!='SNo' and amountinusd=' 1' group by IndustryVertical;

create table q3 as select a.industryvertical, a.count_all, b.count_1 from q31 a join q32 b on (a.industryvertical = b.industryvertical);

select industryvertical,count_1/count_all from q3 where ((count_1/count_all)>0.5 and count_1>10 and industryvertical !=' null ');

 Consumer Internet 	772	461
 ECommerce 		53	32
 Education 		20	15
 Food & Beverage 	19	12
 Logistics 		24	16
 Technology 		313	189
 eCommerce 		171	113


q4==========


create table q41 as select investorsname,count(investorsname) as count_all from startup1 where sno!='SNo' group by investorsname;
create table q42 as select investorsname,count(investorsname) as count_1 from startup1 where sno!='SNo' and amountinusd=' 1' group by investorsname;

create table q4 as select a.investorsname, a.count_all, b.count_1 from q41 a join q42 b on (a.investorsname = b.investorsname);

select investorsname,count_1/count_all from q4 where ((count_1/count_all)>0.5 and count_1>5 and investorsname !=' null ');


 Accel Partners			9	7
 Brand Capital			10	7
 Group of Angel Investors	15	14
 Indian Angel Network		25	13
 Info Edge (India) Ltd		8	8
 Kalaari Capital		16	14
 SAIF Partners			9	9
 Sequoia Capital		14	12
 Tiger Global			7	7
 Trifecta Capital		6	6
 Undisclosed			9	8
 Undisclosed Investor		10	8
 Undisclosed Investors		33	24
 Undisclosed investor		9	7
 Undisclosed investors		27	21
 undisclosed investors		11	11


