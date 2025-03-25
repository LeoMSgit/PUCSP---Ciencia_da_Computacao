package Atividade2;

public class Texto {
    private String txt;

    // Construtor que armazena o texto e limpa os espaços
    Texto(String txt){
        setTxt(txt);
        limpaEspacosExcedentes();
    }

    private void setTxt(String t){
        this.txt = t;
    }

    public String getTxt(){
        return this.txt;
    }

    // Inverte o texto
    public String inverterTexto(){
        String txtInvertido = "";
        if(!(this.txt == null || this.txt.equals(""))){
            for (int i=this.txt.length()-1; i >= 0; i--){
                txtInvertido = txtInvertido + this.txt.charAt(i);
            }
        } else {
            return null;
        }
        return txtInvertido;
    }

    // Retorna o número de palavras
    public int getQtdePalavras(){
        return (getTxt().split(" ").length);
    }

    // Remove espaços excedentes
    private void limpaEspacosExcedentes(){
        setTxt(this.txt.trim());
        String s = "";
        for (int i=0; i < this.txt.length(); i++){
            s = s + this.txt.charAt(i);
            if(this.txt.charAt(i) == ' '){
                while(this.txt.charAt(i+1) == ' '){
                    i++;
                }
            }
        }
        setTxt(s);
    }

    // Retorna o texto
    public String toString(){
        return(getTxt());
    }
}
