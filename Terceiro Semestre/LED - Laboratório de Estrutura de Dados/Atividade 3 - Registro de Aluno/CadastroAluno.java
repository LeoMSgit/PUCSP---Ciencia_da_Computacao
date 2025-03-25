package com.mycompany.cadastro;

public class CadastroAluno {
    private String ra;        // RA do aluno
    private String curso;     // Curso do aluno
    private String periodo;   // Período do aluno

    // Construtor que recebe RA, curso e período
    public CadastroAluno(String ra, String curso, String periodo) {
        this.ra = ra;
        this.curso = curso;
        this.periodo = periodo;
    }

    // Método para exibir os dados completos do aluno
    public void exibirDados() {
        System.out.println("RA                    : " + ra);
        System.out.println("Curso                 : " + curso);
        System.out.println("Período               : " + periodo);
    }

    // Métodos getters e setters
    public String getRa() {
        return ra;
    }

    public String getCurso() {
        return curso;
    }

    public String getPeriodo() {
        return periodo;
    }

    public void setRa(String ra) {
        this.ra = ra;
    }

    public void setCurso(String curso) {
        this.curso = curso;
    }

    public void setPeriodo(String periodo) {
        this.periodo = periodo;
    }
}
