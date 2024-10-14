package Test;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class MyJFrame2 extends JFrame implements MouseListener, MouseWheelListener,Scrollable {
    private JButton jtb = new JButton("点我呀");
    Scrollbar sc = new Scrollbar(Scrollbar.VERTICAL,0,1,0,100);
    public MyJFrame2(){
            JTextField t = new JTextField();
            this.setSize(603,680);

            this.setTitle("拼图单机版注册界面");
            //标题置顶
            this.setAlwaysOnTop(true);
            //居中
            this.setLocationRelativeTo(null);
            //关闭模式
            this.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);

            this.setLayout(null);
            t.setBounds(100,100,50,30);
            jtb.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {

                }
            });
            jtb.setBounds(0,0,50,100);
            jtb.addMouseListener(this);
            sc.setBounds(570,0,30,670);
            sc.addMouseWheelListener(this);
            this.addMouseWheelListener(this);
            this.getContentPane().add(sc);
            this.getContentPane().add(jtb);
            this.getContentPane().add(t);

            this.setVisible(true);
    }

    @Override
    public void mouseClicked(MouseEvent e) {
        System.out.println("单机");}

    @Override
    public void mousePressed(MouseEvent e) {
        System.out.println("按压");
    }

    @Override
    public void mouseReleased(MouseEvent e) {
        System.out.println("松开");
    }

    @Override
    public void mouseEntered(MouseEvent e) {
        System.out.println("划入");
    }

    @Override
    public void mouseExited(MouseEvent e) {
        System.out.println("划出");
    }

    @Override
    public void mouseWheelMoved(MouseWheelEvent e) {
        int a = e.getWheelRotation();
        System.out.println("滚动了");
        int currentValue = sc.getValue();
        int newValue = currentValue + a;
        sc.setValue(newValue);
    }

    @Override
    public Dimension getPreferredScrollableViewportSize() {
        return null;
    }

    @Override
    public int getScrollableUnitIncrement(Rectangle visibleRect, int orientation, int direction) {
        return 0;
    }

    @Override
    public int getScrollableBlockIncrement(Rectangle visibleRect, int orientation, int direction) {
        return 0;
    }

    @Override
    public boolean getScrollableTracksViewportWidth() {
        return false;
    }

    @Override
    public boolean getScrollableTracksViewportHeight() {
        return false;
    }
}
