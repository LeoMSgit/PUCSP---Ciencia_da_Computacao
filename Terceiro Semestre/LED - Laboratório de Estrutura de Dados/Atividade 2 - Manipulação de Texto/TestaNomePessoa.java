import javax.swing.JOptionPane;

public class TestaNomePessoa {
    public static void main(String[] args) {
        // Entrada do nome completo
        String nomeCompleto = JOptionPane.showInputDialog("Forneça o nome completo da pessoa:");

        // Criação do objeto NomePessoa
        NomePessoa pessoa = new NomePessoa(nomeCompleto);

        // Exibe o nome completo
        System.out.println("Nome Completo: " + pessoa.getNome());

        // Exibe o nome invertido
        System.out.println("Nome Invertido: " + pessoa.inverterNome());

        // Exibe o nome no formato bibliográfico
        System.out.println("Nome Bibliográfico: " + pessoa.obterNomeBibliografico());
    }
}
