package Ui;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class LoginJframe extends JFrame implements MouseListener,ActionListener,KeyListener {
    Label lab = new Label();
    static String account;//账号
    static String code;
    String getAccount="";
    String getCode="";//密码
    JButton login0 = new JButton(new ImageIcon("image\\login\\登录按钮.png"));
    JButton jb = new JButton(new ImageIcon("image\\login\\注册按钮.png"));
    JLabel code1 = new JLabel();//验证码文字
    JTextField codeinput = new JTextField();//验证码输入框
    JTextField username = new JTextField();//密码输入框
    JTextField password = new JTextField();//账号输入框
    String captcha="";//验证码
    String captchaexist;//生成的验证码

    public LoginJframe() {

        initJFrame();

        initView();

        addAction();

        this.setVisible(true);
    }

    private void addAction() {
        this.addMouseListener(this);
        login0.addMouseListener(this);
        code1.addMouseListener(this);
        jb.addMouseListener(this);
        codeinput.addActionListener(this);
        username.addActionListener(this);
        password.addActionListener(this);
    }

    public void initView() {
        this.getContentPane().removeAll();
        JLabel jyonghu = new JLabel(new ImageIcon("image\\login\\用户名.png"));
        jyonghu.setBounds(116, 135, 47, 17);
        this.getContentPane().add(jyonghu);

        username.setBounds(195, 134, 200, 30);
        this.getContentPane().add(username);

        JLabel mime = new JLabel(new ImageIcon("image\\login\\密码.png"));
        mime.setBounds(130, 195, 32, 16);
        this.getContentPane().add(mime);

        password.setBounds(195, 195, 200, 30);
        this.getContentPane().add(password);

        JLabel codeTest = new JLabel(new ImageIcon("image\\login\\验证码.png"));
        codeTest.setBounds(133, 256, 50, 30);
        this.getContentPane().add(codeTest);

        codeinput.setBounds(195, 256, 50, 30);
        this.getContentPane().add(codeinput);
        //生成验证码
        String ans = Code.getcode();
        captchaexist=ans;
        code1.setText(ans);
        code1.setBounds(260, 256, 50, 30);
        this.getContentPane().add(code1);

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

        JLabel p = new JLabel(new ImageIcon("image\\login\\background.png"));
        p.setBounds(0, 0, 470, 390);
        this.getContentPane().add(p);
        lab.setBounds(275,275,50,30);

        this.getContentPane().repaint();
    }

    public void initJFrame() {
        this.setSize(488, 430);

        this.setTitle("拼图登录界面");
        //标题置顶
        this.setAlwaysOnTop(true);
        //居中
        this.setLocationRelativeTo(null);
        //关闭模式
        this.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);

        this.setLayout(null);

    }

    @Override
    public void mouseClicked(MouseEvent e) {

    }

    @Override
    public void mousePressed(MouseEvent e) {
        Object a = e.getSource();
        if(a==login0){
            login0.setIcon(new ImageIcon("image\\login\\登录按下.png"));
        }
        else if(a==jb){
            jb.setIcon(new ImageIcon("image\\login\\注册按下.png"));
        }
    }

    @Override
    public void mouseReleased(MouseEvent e) {
        Object a = e.getSource();
        if(a==login0){
            if(captcha.equals(captchaexist)){
                this.setVisible(false);
                new GameJframe();
            }
            login0.setIcon(new ImageIcon("image\\login\\登录按钮.png"));
        }
        else if(a==jb){
            this.setVisible(false);
            new RejisterJfram();
        }
        else if(a==code1){
            String ans = Code.getcode();
            captchaexist=ans;
            code1.setText(ans);
        }
    }

    @Override
    public void mouseEntered(MouseEvent e) {

    }

    @Override
    public void mouseExited(MouseEvent e) {
        if(e.getSource()==this){
            try {
                Robot robot = new Robot();

                // 模拟按下回车键
                robot.keyPress(KeyEvent.VK_ENTER);
                robot.keyRelease(KeyEvent.VK_ENTER);

                // 可以在这里添加其他需要的自动化操作

            } catch (AWTException c) {
                c.printStackTrace();
            }
        }
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        Object a = e.getSource();
        if(a==codeinput){
            captcha=codeinput.getText();
            System.out.println(captcha);
        }
        else if(a==username){
            getAccount=username.getText();
            System.out.println(getAccount);
        }
        else if(a==password){
            getCode=password.getText();
            System.out.println(getCode);
        }
    }

    @Override
    public void keyTyped(KeyEvent e) {

    }

    @Override
    public void keyPressed(KeyEvent e) {

    }

    @Override
    public void keyReleased(KeyEvent e) {

    }
}
