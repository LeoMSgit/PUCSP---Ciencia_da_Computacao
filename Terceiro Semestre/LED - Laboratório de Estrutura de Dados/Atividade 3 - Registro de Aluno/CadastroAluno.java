package com.mycompany.cadastro;

public class CadastroAluno extends CadastroPessoa {
    private String ra;
    private String curso;
    private int semestre;

    public CadastroAluno(String nome, int idade, String id, String ra, String curso, int semestre) {
        super(nome, idade, id);
        this.ra = ra;
        this.curso = curso;
        this.semestre = semestre;
    }

    @Override
    public void exibirDados() {
        super.exibirDados();
        System.out.println("RA                   : " + ra);
        System.out.println("Curso                : " + curso);
        System.out.println("Semestre             : " + semestre);
    }

    public String getRa() {
        return ra;
    }

    public void setRa(String ra) {
        this.ra = ra;
    }

    public String getCurso() {
        return curso;
    }

    public void setCurso(String curso) {
        this.curso = curso;
    }

    public int getSemestre() {
        return semestre;
    }

    public void setSemestre(int semestre) {
        this.semestre = semestre;
    }
}
