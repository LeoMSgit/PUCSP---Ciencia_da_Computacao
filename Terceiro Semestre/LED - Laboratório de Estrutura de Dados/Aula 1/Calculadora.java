import javax.swing.JOptionPane;

public class Calculadora {
    public static void main(String[] args) {

        String input1 = JOptionPane.showInputDialog(null ,"Digite o primeiro número:");
        double Numero1 = Double.parseDouble(input1);

        String input2 = JOptionPane.showInputDialog(null ,"Digite o segundo número:");
        double Numero2 = Double.parseDouble(input2);

        double soma = Numero1 + Numero2;
        double subtracao = Numero1 - Numero2;
        double multiplicacao = Numero1 * Numero2;
        double divisao = Numero1 / Numero2;

         String mensagem = "O resultado da soma é: " + soma + "\n" + "O resultado da subtração é: " + subtracao + "\n" + "O resultado da multiplicação é: " + multiplicacao + "\n" + "O resultado da divisão é: " + divisao;

        JOptionPane.showMessageDialog(null, mensagem, "Resultados da Calculadora", JOptionPane.INFORMATION_MESSAGE);

    }
}
