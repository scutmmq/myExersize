package Test;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Random;

public class MyJFrame extends JFrame implements ActionListener {
    private JButton jtb = new JButton("点我呀");
    private JButton jtb1 = new JButton(("再点我"));
    TextField tx = new TextField(20);
    public MyJFrame(){
        JFrame j = new JFrame();
        this.setSize(603,680);

        this.setTitle("拼图单机版注册界面");
        //标题置顶
        this.setAlwaysOnTop(true);
        //居中
        this.setLocationRelativeTo(null);
        //关闭模式
        this.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);

        this.setLayout(null);

        jtb.setBounds(0,0,100,50);
        jtb.addActionListener(this);


        jtb1.setBounds(100,0,100,50);
        jtb1.addActionListener(this);

        tx.setBounds(100,100,200,30);

        this.getContentPane().add(tx);
        this.getContentPane().add(jtb);
        this.getContentPane().add(jtb1);

        this.setVisible(true);
    }
    @Override
    public void actionPerformed(ActionEvent e) {
        Object source = e.getSource();
        if(source==jtb){
            jtb.setSize(200,200);
        }
        else if(source==jtb1){
            jtb1.setLocation(200,200);
        }
    }
}
