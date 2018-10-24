
-- Cdastro de professor --
Delimiter //

create procedure cadas_prof (
 tb_prof_nome varchar(128),
 tb_prof_rg char(9) ,
 tb_prof_email varchar(128) ,
 tb_prof_carteirinha varchar(20) ,
 tb_prof_tel varchar(21)
    
)
begin
	insert into tb_professor (tb_prof_nome, tb_prof_rg, tb_prof_email, tb_prof_carteirinha,
								tb_prof_tel) value (tb_prof_nome, tb_prof_rg, tb_prof_email, tb_prof_carteirinha,
								tb_prof_tel);
end
//

-- Cadastro de aluno --
Delimiter //

create procedure cadas_aluno (
tb_aluno_nome varchar (128),
tb_aluno_rg char(9),
tb_aluno_email varchar(128),
tb_aluno_ra varchar(16),
tb_aluno_tel varchar(21)
    
)
begin
	insert into tb_aluno (tb_aluno_nome, tb_aluno_rg, tb_aluno_email, tb_aluno_ra, tb_aluno_tel) 
						value (tb_aluno_nome, tb_aluno_rg, tb_aluno_email, tb_aluno_ra, tb_aluno_tel);
end
//

-- cadastro de convidado --
Delimiter //

create procedure cadas_convidado (
tb_convidado_nome varchar (128),
tb_convidado_rg char(9),
tb_convidado_email varchar(128),
tb_convidado_convite varchar(16),
tb_convidado_tel varchar(21)     
)
begin
	insert into tb_convidado (tb_convidado_nome, tb_convidado_rg, tb_convidado_email, tb_convidado_convite, tb_convidado_tel) 
						value (tb_convidado_nome, tb_convidado_rg, tb_convidado_email, tb_convidado_convite, tb_convidado_tel);
end
//

-- cadastro de Deficiente --
Delimiter //

create procedure cadas_pne(
tb_def_nome varchar (128),
tb_def_rg char(9) ,
tb_def_tel varchar(21),
tb_def_email varchar(128),
tb_def_carteirinha varchar(21)
) 
begin 
	insert into tb_def (tb_def_nome, tb_def_rg, tb_def_tel, tb_def_email, tb_def_carteirinha ) 
				value (tb_def_nome, tb_def_rg, tb_def_tel, tb_def_email, tb_def_carteirinha);
end
//