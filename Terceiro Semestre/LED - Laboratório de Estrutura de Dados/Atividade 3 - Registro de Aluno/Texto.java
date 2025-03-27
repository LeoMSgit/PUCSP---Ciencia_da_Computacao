package com.mycompany.cadastro;

public class Texto {
    private String txt;

    Texto(String txt) {
        setTxt(txt);
        limpaEspacosExcedentes();
    }

    private void setTxt(String t) {
        this.txt = t;
    }

    public String getTxt() {
        return this.txt;
    }

    public String inverterTexto() {
        String txtInvertido = "";
        if (!(this.txt == null || this.txt.equals(""))) {
            for (int i = this.txt.length() - 1; i >= 0; i--) {
                txtInvertido = txtInvertido + this.txt.charAt(i);
            }
        } else {
            return null;
        }
        return txtInvertido;
    }

    public int getQtdePalavras() {
        return (getTxt().split(" ").length);
    }

    private void limpaEspacosExcedentes() {
        setTxt(this.txt.trim());
        String s = "";
        for (int i = 0; i < this.txt.length(); i++) {
            s = s + this.txt.charAt(i);
            if (this.txt.charAt(i) == ' ') {
                while (i + 1 < this.txt.length() && this.txt.charAt(i + 1) == ' ') {
                    i++;
                }
            }
        }
        setTxt(s);
    }

    public String toString() {
        return getTxt();
    }
}
