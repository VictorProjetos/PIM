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