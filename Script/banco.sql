create database teatro;
use banco;
create  table tb_professor
(
 id int not null  primary key AUTO_INCREMENT ,
 tb_prof_nome varchar(128),
 tb_prof_rg char(9) not null,
 tb_prof_email varchar(128) not null,
 tb_prof_carteirinha varchar(20) not null,
 tb_prof_tel varchar(21)
);



select * from tb_professor; 