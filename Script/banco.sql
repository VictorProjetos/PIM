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

create table tb_aluno
(
id int not null primary key auto_increment,
tb_aluno_nome varchar (128) not null,
tb_aluno_rg char(9) not null,
tb_aluno_email varchar(128) not null,
tb_aluno_ra varchar(16) not null,
tb_aluno_tel varchar(21) not null
);

create table tb_convidado
(
id int not null primary key auto_increment,
tb_convidado_nome varchar (128) not null,
tb_convidado_rg char(9) not null,
tb_convidado_email varchar(128) not null,
tb_convidado_convite varchar(16) not null,
tb_convidado_tel varchar(21) not null
);

create table tb_def
(
id int not null primary key auto_increment,
tb_def_nome varchar (128) not null,
tb_def_rg char(9) not null,
tb_def_tel varchar(21) not null,
tb_def_email varchar(128) not null,
tb_def_carteirinha varchar(21) not null
);


select * from tb_aluno; 
select * from tb_professor;
select * from tb_convidado; 
select * from tb_def; 