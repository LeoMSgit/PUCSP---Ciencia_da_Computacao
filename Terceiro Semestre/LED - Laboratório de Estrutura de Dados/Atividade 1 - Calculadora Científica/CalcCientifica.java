package com.mycompany.mavenproject1;

public class CalcCientifica extends CalcBasica {
    public void calcular(String operando1, String operador, String operando2) {
        double result = 0;
        String msg = "";
        
        if (isNumeric(operando1)) {
            double num = Double.parseDouble(operando1);
            switch (operador) {
                case "sin":
                    result = Math.sin(Math.toRadians(num));
                    msg = String.format("Resultado = %.2f", result);
                    break;
                case "sqrt":
                    result = Math.sqrt(num);
                    msg = String.format("Resultado = %.2f", result);
                    break;
                case "!":
                    result = fatorial((int) num);
                    msg = String.format("Resultado = %.0f", result);
                    break;
                default:
                    super.calcular(operando1, operador, operando2);
                    return;
            }
        } else {
            msg = "Operando não numérico!!";
        }
        Saida.mostrarMsg(msg);
    }
    
    private double fatorial(int n) {
        return (n <= 1) ? 1 : n * fatorial(n - 1);
    }
}
