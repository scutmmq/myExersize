package Ui;

import javax.swing.*;

public class RejisterJfram extends JFrame {
    public RejisterJfram(){
        JButton login0 = new JButton(new ImageIcon("image\\register\\注册按钮.png"));
        JButton jb = new JButton(new ImageIcon("image\\register\\重置按钮.png"));
        JTextField username = new JTextField();//密码输入框
        JTextField password = new JTextField();//账号输入框
        initJFram();
        JLabel jyonghu = new JLabel(new ImageIcon("image\\register\\注册用户名.png"));
        jyonghu.setBounds(116, 135, 47, 17);
        this.getContentPane().add(jyonghu);

        username.setBounds(195, 134, 200, 30);
        this.getContentPane().add(username);

        JLabel mime = new JLabel(new ImageIcon("image\\register\\注册密码.png"));
        mime.setBounds(130, 195, 32, 16);
        this.getContentPane().add(mime);

        password.setBounds(195, 195, 200, 30);
        this.getContentPane().add(password);

        JLabel codeTest = new JLabel(new ImageIcon("image\\register\\再次输入密码.png"));
        codeTest.setBounds(133, 256, 50, 30);
        this.getContentPane().add(codeTest);


        login0.setBounds(123, 310, 128, 47);
        //去除按钮边框
        login0.setBorderPainted(false);
        //去除按钮背景
        login0.setContentAreaFilled(false);
        this.getContentPane().add(login0);

        //注册按钮
        jb.setBounds(256, 310, 128, 47);
        jb.setBorderPainted(false);
        jb.setContentAreaFilled(false);
        this.getContentPane().add(jb);

        JLabel p = new JLabel(new ImageIcon("image\\register\\background.png"));
        p.setBounds(0, 0, 470, 390);
        this.getContentPane().add(p);

        this.getContentPane().repaint();


        this.setVisible(true);
    }

    private void initJFram() {
        this.setSize(488,500);

        this.setTitle("拼图单机版注册界面");
        //标题置顶
        this.setAlwaysOnTop(true);
        //居中
        this.setLocationRelativeTo(null);
        //关闭模式
        this.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);

        this.setLayout(null);
    }
}
