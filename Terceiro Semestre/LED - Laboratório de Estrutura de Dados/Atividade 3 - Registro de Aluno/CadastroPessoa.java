package com.mycompany.cadastro;

public class CadastroPessoa {
    private NomePessoa nomePessoa;
    private int idade;
    private String id;

    public CadastroPessoa(String nome, int idade, String id) {
        this.nomePessoa = new NomePessoa(nome);
        this.idade = idade;
        this.id = id;
    }

    public void exibirDados() {
        System.out.println("Nome completo        : " + nomePessoa.getNome());
        System.out.println("Nome invertido       : " + nomePessoa.inverterTexto());
        System.out.println("Nome bibliográfico   : " + nomePessoa.nomeBibliografico());
        System.out.println("Idade                : " + idade);
        System.out.println("ID                   : " + id);
    }

    public String getNome() {
        return nomePessoa.getNome();
    }

    public int getIdade() {
        return idade;
    }

    public String getId() {
        return id;
    }

    public void setNome(String nome) {
        this.nomePessoa = new NomePessoa(nome);
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public void setId(String id) {
        this.id = id;
    }
}
