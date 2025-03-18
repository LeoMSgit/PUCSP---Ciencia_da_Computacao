package com.mycompany.mavenproject1;

import javax.swing.*;

public class Aplicacao {
    public static void main(String args[]) {
        if (args.length > 0) {
            Entrada.setModoGrafico(args[0]);
        }
        
        if (args.length > 0 && args[0].equalsIgnoreCase("grafico")) {
            new CalculadoraGUI();
        } else {
            Entrada ent = new Entrada();
            String operando1 = ent.lerString("Forneça operando1: ");
            String operador = ent.lerString("Forneça operador: ");
            
            String operando2 = "";
            if (!operador.equals("sin") && !operador.equals("sqrt") && !operador.equals("!")) {
                operando2 = ent.lerString("Forneça operando2: ");
            }
            
            calcular(operando1, operador, operando2);
        }
    }

    public static void calcular(String s1, String s2, String s3) {
        CalcCientifica cc = new CalcCientifica();
        cc.calcular(s1, s2, s3);
    }
}
