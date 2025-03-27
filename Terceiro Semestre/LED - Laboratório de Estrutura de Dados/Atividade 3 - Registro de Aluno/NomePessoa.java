package com.mycompany.cadastro;

public class NomePessoa {
    private Texto nome;

    public NomePessoa(String nome) {
        this.nome = new Texto(nome);
    }

    public String getNome() {
        return nome.getTxt();
    }

    public String nomeBibliografico() {
        String nomeCompleto = nome.getTxt();
        String[] partes = nomeCompleto.split(" ");
        String sobrenome = partes[partes.length - 1];
        StringBuilder iniciais = new StringBuilder();

        for (int i = 0; i < partes.length - 1; i++) {
            if (!verificaStr(partes[i].toLowerCase())) {
                iniciais.append(partes[i].charAt(0)).append(". ");
            }
        }

        return sobrenome + ", " + iniciais.toString().trim();
    }

    private boolean verificaStr(String s) {
        final String sRet[] = {"da", "de", "do", "di", "das", "dos", "e"};

        for (int i = 0; i < sRet.length; i++) {
            if (sRet[i].equals(s)) {
                return true;
            }
        }
        return false;
    }

    public String inverterTexto() {
        return nome.inverterTexto();
    }
}
