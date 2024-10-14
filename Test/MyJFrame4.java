package Test;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

public class MyJFrame4 extends JFrame implements MouseListener, ActionListener {
    JButton jb = new JButton(new ImageIcon("image\\login\\登录按钮.png"));
    TextField tx = new TextField(20);
    MyJFrame4(){
        setJFrame();

        setButton();
        tx.setBounds(100,100,200,30);
        tx.addActionListener(this);

        this.getContentPane().add(tx);

        this.getContentPane().add(jb);
        this.setVisible(true);
    }

    private void setButton() {
        jb.setBounds(200,200,128,47);
        jb.addMouseListener(this);
        jb.setBorderPainted(false);
        jb.setContentAreaFilled(false);
    }

    private void setJFrame() {
        this.setSize(500,500);

        this.setAlwaysOnTop(true);

        this.setTitle("鼠标监听测试版");

        this.setLocationRelativeTo(null);

        this.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);

        this.setLayout(null);
    }

    @Override
    public void mouseClicked(MouseEvent e) {

    }

    @Override
    public void mousePressed(MouseEvent e) {
        Object a = e.getSource();
        if(a==jb){
            jb.setIcon(new ImageIcon("image\\login\\登录按下.png"));
        }
    }

    @Override
    public void mouseReleased(MouseEvent e) {
        Object a = e.getSource();
        if(a==jb){
            jb.setIcon(new ImageIcon("image\\login\\登录按钮.png"));
        }
    }

    @Override
    public void mouseEntered(MouseEvent e) {

    }

    @Override
    public void mouseExited(MouseEvent e) {

    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource()==tx){
            String ans = tx.getText();
            System.out.println(ans);
        }
    }
}