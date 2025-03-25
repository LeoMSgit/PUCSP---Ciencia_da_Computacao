package Atividade2;

import javax.swing.JOptionPane;

public class TestaTexto {
    public static void main(String[] args) {
        // Entrada do nome completo
        String nome = JOptionPane.showInputDialog("Forneça o nome completo: ");

        // Criação de um objeto NomePessoa
        NomePessoa pessoa = new NomePessoa(nome);

        // Exibindo as informações
        System.out.println("Nome completo        : " + pessoa.getNome());
        System.out.println("Nome completo invertido: " + pessoa.inverterTexto());
        System.out.println("Nome bibliográfico   : " + pessoa.nomeBibliografico());
    }
}
