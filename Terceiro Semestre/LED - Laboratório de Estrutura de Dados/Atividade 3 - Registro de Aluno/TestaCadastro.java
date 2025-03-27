package com.mycompany.cadastro;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class TestaCadastro {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Cadastro de Pessoas");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 300);

        JPanel panel = new JPanel();
        panel.setLayout(new BorderLayout());

        JCheckBox alunoCheckBox = new JCheckBox("Aluno");
        JTabbedPane tabbedPane = new JTabbedPane();

        JPanel cadastroPanel = new JPanel();
        cadastroPanel.setLayout(new GridLayout(3, 2));

        cadastroPanel.add(new JLabel("Nome: "));
        JTextField nomeField = new JTextField(5);
        cadastroPanel.add(nomeField);

        cadastroPanel.add(new JLabel("Idade: "));
        JTextField idadeField = new JTextField(20);
        cadastroPanel.add(idadeField);

        cadastroPanel.add(new JLabel("ID: "));
        JTextField idField = new JTextField(20);
        cadastroPanel.add(idField);

        JPanel alunoPanel = new JPanel();
        alunoPanel.setLayout(new GridLayout(3, 2));

        alunoPanel.add(new JLabel("RA: "));
        JTextField raField = new JTextField(20);
        alunoPanel.add(raField);

        alunoPanel.add(new JLabel("Curso: "));
        JTextField cursoField = new JTextField(20);
        alunoPanel.add(cursoField);

        alunoPanel.add(new JLabel("Semestre: "));
        JTextField semestreField = new JTextField(20);
        alunoPanel.add(semestreField);

        tabbedPane.addTab("Cadastro", cadastroPanel);

        JButton registrarButton = new JButton("Registrar");

        registrarButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (alunoCheckBox.isSelected()) {
                    tabbedPane.removeTabAt(0);
                    tabbedPane.addTab("Inscrição de Aluno", alunoPanel);
                    // Exibir no console
                    String ra = raField.getText();
                    String curso = cursoField.getText();
                    String semestre = semestreField.getText();
                    System.out.println("Inscrição de Aluno realizada: \nRA: " + ra + "\nCurso: " + curso + "\nSemestre: " + semestre);
                } else {
                    String nome = nomeField.getText();
                    String idade = idadeField.getText();
                    String id = idField.getText();
                    // Exibir no console
                    System.out.println("Cadastro realizado: \nNome: " + nome + "\nIdade: " + idade + "\nID: " + id);
                }
            }
        });

        JPanel bottomPanel = new JPanel();
        bottomPanel.add(alunoCheckBox);
        bottomPanel.add(registrarButton);

        panel.add(bottomPanel, BorderLayout.SOUTH);
        panel.add(tabbedPane, BorderLayout.CENTER);

        frame.add(panel);
        frame.setVisible(true);
    }
}
