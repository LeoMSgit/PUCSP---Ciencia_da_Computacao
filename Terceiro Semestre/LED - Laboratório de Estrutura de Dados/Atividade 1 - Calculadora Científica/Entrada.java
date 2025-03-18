package com.mycompany.mavenproject1;

import javax.swing.*;
import java.util.Scanner;

/**
 * Classe principal.
 * 
 * @author Julio Arakaki 
 * @version 20250310
 */
public class Entrada {
    private static final Scanner sc = new Scanner(System.in);
    private static boolean modoGrafico = false;
    
    public static void setModoGrafico(String modo) {
        modoGrafico = "grafico".equalsIgnoreCase(modo);
    }
    
    /**
     * Método lerString - lê uma string via console ou Swing
     *
     * @param mensagem Mensagem para entrada de dados
     * @return String lida do usuário
     */
    public String lerString(String mensagem){
        if (modoGrafico) {
            return JOptionPane.showInputDialog(null, mensagem, "Entrada de Dados", JOptionPane.QUESTION_MESSAGE);
        } else {
            System.out.print(mensagem);
            return sc.nextLine();
        }
    }
    
    /**
     * Método mostrarMsg - Exibe uma mensagem no console ou em uma janela gráfica
     *
     * @param msg Mensagem a ser exibida
     */
    public static void mostrarMsg(String msg) {
        if (modoGrafico) {
            JOptionPane.showMessageDialog(null, msg, "Resultado", JOptionPane.INFORMATION_MESSAGE);
        } else {
            System.out.println(msg);
        }
    }
}
