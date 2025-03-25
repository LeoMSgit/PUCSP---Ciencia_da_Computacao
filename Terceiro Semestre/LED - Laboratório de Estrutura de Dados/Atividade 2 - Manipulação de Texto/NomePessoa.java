package Atividade2;

public class NomePessoa {
    private Texto nome;

    // Construtor que recebe o nome completo
    public NomePessoa(String nome) {
        this.nome = new Texto(nome);  // Cria um objeto Texto com o nome
    }

    // Retorna o nome completo
    public String getNome() {
        return nome.getTxt();
    }

    // Método que retorna o nome em formato bibliográfico
    public String nomeBibliografico() {
        String nomeCompleto = nome.getTxt();
        String[] partes = nomeCompleto.split(" ");
        String sobrenome = partes[partes.length - 1];
        StringBuilder iniciais = new StringBuilder();
        for (int i = 0; i < partes.length - 1; i++) {
            iniciais.append(partes[i].charAt(0)).append(". ");
        }
        return sobrenome + ", " + iniciais.toString().trim();
    }

    // Método que retorna o nome invertido
    public String inverterTexto() {
        return nome.inverterTexto();  // Chama o método inverterTexto() da classe Texto
    }
}
