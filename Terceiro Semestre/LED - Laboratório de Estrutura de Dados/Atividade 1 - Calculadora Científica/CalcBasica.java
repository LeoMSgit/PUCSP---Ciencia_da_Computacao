package com.mycompany.mavenproject1;

/**
 * Classe para calculadora basica (4 operacoes|)
 * 
 * @author Julio Arakaki 
 * @version 20250310
 */
public class CalcBasica {
    /**
     * Método calcular
     *
     * @param operando1 String
     * @param operador String
     * @param operando2 String
     */
    public void calcular(String operando1, String operador, String operando2){ 

        // Para armazenar resultado
        double result = 0;

        // Para armazenar uma msg
        String msg = "";

        if(isNumeric(operando1) && isNumeric(operando2)){ // Verifica se eh numerico
            // Realiza as 4 operacoes
            switch (operador){
                case "-":
                    result = Double.parseDouble(operando1) - Double.parseDouble(operando2);
                    msg = String.format("Resultado = %.2f", result);
                    break;
                case "+":
                    result = Double.parseDouble(operando1) + Double.parseDouble(operando2);
                    msg = String.format("Resultado = %.2f", result);
                    break;
                case "*":
                    result = Double.parseDouble(operando1) * Double.parseDouble(operando2);
                    msg = String.format("Resultado = %.2f", result);
                    break;
                case "/":
                    result = Double.parseDouble(operando1) / Double.parseDouble(operando2);
                    msg = String.format("Resultado = %.2f", result);
                    break;
                default:
                    msg = "Operador invalido!!";
            }    

        } else {
            msg = "Operando nao numerico!!";

        }
        Saida.mostrarMsg(msg);
        //System.out.println(msg);
    }

    /**
     * Metodo isNumeric - verifica se a string eh numerica
     * Parametros:
     *         String str - string a ser verificada
     * Retorno:
     *         boolean - true: a string eh numerica
     *                  - false: a string nao eh numerica
     */
    public boolean isNumeric(String str) {
        if (str == null || str.length() == 0) {
            return false;
        }

        boolean foundDecimal = false;
        for (char c : str.toCharArray()) { // percorre a string
            if (!Character.isDigit(c)) { // verifica se eh digito
                if (c == '.' && !foundDecimal) { // verifica se existe um unico ponto
                    foundDecimal = true;
                } else {
                    return false;
                }
            }
        }            
        return true;
    }
}
