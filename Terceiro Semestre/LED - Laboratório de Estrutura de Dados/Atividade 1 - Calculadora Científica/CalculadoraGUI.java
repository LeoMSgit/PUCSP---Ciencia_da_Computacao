package com.mycompany.mavenproject1;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class CalculadoraGUI {
    public CalculadoraGUI() {
        JFrame frame = new JFrame("Calculadora Científica");
        frame.setSize(400, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new GridLayout(8, 2));

        JTextField txtOperando1 = new JTextField();
        JTextField txtOperador = new JTextField();
        JTextField txtOperando2 = new JTextField();
        JButton btnCalcular = new JButton("Calcular");

        frame.add(new JLabel("Operando 1:"));
        frame.add(txtOperando1);
        frame.add(new JLabel("Operador (+, -, *, /, sin, sqrt, !):"));
        frame.add(txtOperador);
        frame.add(new JLabel("Operando 2 (se aplicável):"));
        frame.add(txtOperando2);
        frame.add(btnCalcular);

        btnCalcular.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                Aplicacao.calcular(txtOperando1.getText(), txtOperador.getText(), txtOperando2.getText());
            }
        });

        frame.setVisible(true);
    }
}
