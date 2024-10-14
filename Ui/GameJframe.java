package Ui;

import javax.swing.*;
import javax.swing.border.BevelBorder;
import java.awt.*;
import java.awt.event.*;
import java.util.Random;

public class GameJframe extends JFrame implements KeyListener, ActionListener {
    Random r = new Random();
    private  int [][]arr=new int [4][4];
    int x,y;//空白方块在二维数组中的位置
    String path="image\\animal\\animal1\\";
    int [][]arr0 = new int[][]{{1,2,3,4},{5,6,7,8}, {9, 10, 11, 12},{13,14,15,0}};
    int count =0;
    JMenuItem replayItem = new JMenuItem("重新游戏");
    JMenuItem reLoginItem = new JMenuItem("重新登录");
    JMenuItem closeItem = new JMenuItem("关闭游戏");
    JMenuItem animal = new JMenuItem("动物");
    JMenuItem sport = new JMenuItem("运动");
    JMenuItem girl = new JMenuItem("女生");
    JMenuItem change = new JMenuItem("更换图片");

    JMenuItem account = new JMenuItem("二维码");
    //主界面
    public GameJframe(){
        //初始化窗口
        initFrame();
        //添加菜单
        initJMenuBar();
        //初始化数据，打乱
        initData();
        //添加图片
        initImage();

        this.setVisible(true);
    }

    private void initData() {
        int []temparr={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
        for (int i = 0; i < temparr.length; i++) {
            int index = r.nextInt(temparr.length);
            int temp = temparr[i];
            temparr[i]=temparr[index];
            temparr[index]=temp;
        }
        int index=0;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(temparr[index]==0){x=i;y=j;}
                this.arr[i][j]=temparr[index];
                index++;
            }
        }
    }

    private void initImage() {
        this.getContentPane().removeAll();
        //路径两种，绝对路径（盘符开始）
        //相对路径，不从盘符开始
        if(victory()){
            JLabel j = new JLabel(new ImageIcon("image\\win.png"));
            j.setBounds(203,283,197,73);
            this.getContentPane().add(j);
        }

        JLabel step = new JLabel("步数"+count);
        step.setBounds(50,30,100,20);
        this.getContentPane().add(step);

        for(int i =0 ;i<4;i++){
            for(int k =0;k<4;k++){
        JLabel j = new JLabel(new ImageIcon(path+arr[i][k]+".jpg"));
        j.setBounds(105*k+83,105*i+134,105,105);
        //给图片添加边框
                j.setBorder(new BevelBorder(0));
        this.getContentPane().add(j);

            }
        }
        //背景
        JLabel jl = new JLabel((new ImageIcon("image\\background.png")));
        jl.setBounds(40,40,508,560);
        this.getContentPane().add(jl);

        this.getContentPane().repaint();
    }

    private void initJMenuBar() {
        //初始化菜单
        JMenuBar jmenuBar = new JMenuBar();
        //选项对象
        JMenu change = new JMenu("更换图片");
        JMenu functionJMenu= new JMenu("功能");
        JMenu aboutJMenu = new JMenu("关于我们");
        //条目对象

        functionJMenu.add(replayItem);
        functionJMenu.add(reLoginItem);
        functionJMenu.add(closeItem);
        functionJMenu.add(change);
        change.add(girl);
        change.add(animal);
        change.add(sport);

        aboutJMenu.add(account);

        //给条目绑定事件
        replayItem.addActionListener(this);
        reLoginItem.addActionListener(this);
        closeItem.addActionListener(this);
        account.addActionListener(this);
        girl.addActionListener(this);
        animal.addActionListener(this);
        sport.addActionListener(this);

        jmenuBar.add(functionJMenu);
        jmenuBar.add(aboutJMenu);

        //给整个界面设置菜单
        this.setJMenuBar(jmenuBar);

    }

    private void initFrame() {
        this.setSize(603,680);
        //标题
        this.setTitle("拼图单机版 v1.0");
        //标题置顶
        this.setAlwaysOnTop(true);
        //居中
        this.setLocationRelativeTo(null);
        //关闭模式
        this.setDefaultCloseOperation(3);
        //取消默认居中放置
        this.setLayout(null);

        this.addKeyListener(this);
    }

    @Override
    public void keyTyped(KeyEvent e) {

    }
    //按下不松一直调用
    @Override
    public void keyPressed(KeyEvent e) {
        int code = e.getKeyCode();
        if(code==65){
            this.getContentPane().removeAll();
            JLabel j = new JLabel(new ImageIcon(path+"all.jpg"));
            j.setBounds(83,134,420,420);
            this.getContentPane().add(j);
            JLabel jl = new JLabel(new ImageIcon("image\\background.png"));
            jl.setBounds(40,40,508,560);
            this.getContentPane().add(jl);
            this.getContentPane().repaint();
        }
    }

    @Override
    public void keyReleased(KeyEvent e) {
        int code = e.getKeyCode();
        if(code==37){
            if(y==3)return;
            arr[x][y]=arr[x][y+1];
            arr[x][y+1]=0;
            y++;
            count++;
            initImage();
        }
        else if(code ==38){
            //向上移动
            if(x==3){return;}
            arr[x][y]=arr[x+1][y];
            arr[x+1][y]=0;
            x++;
            count++;
            initImage();
        }
        else if(code == 39){
            if(y==0)return;
            arr[x][y]=arr[x][y-1];
            arr[x][y-1]=0;
            y--;
            count++;
            initImage();
        }
        else if(code==40){
            if(x==0)return;
            arr[x][y]=arr[x-1][y];
            arr[x-1][y]=0;
            x--;
            count++;
            initImage();
        }
        else if(code==65){
            initImage();
        }
        else if(code==87){
            arr = new int[][]{{1,2,3,4},{5,6,7,8}, {9, 10, 11, 12},{13,14,15,0}};
            initImage();;
        }
    }

    public boolean victory(){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(arr[i][j]!=arr0[i][j])return false;
            }
        }
        return true;
    }

    //action
    @Override
    public void actionPerformed(ActionEvent e) {
        Object obj = e.getSource();
        if(obj==reLoginItem){
            this.setVisible(false);
            new LoginJframe();
        }
        else if(obj==replayItem){
            count=0;
            initData();
            initImage();
        }
        else if(obj==closeItem){
            System.exit(0);
        }
        else if(obj==account){
            //弹框对象
            JDialog jd = new JDialog();
            JLabel j = new JLabel(new ImageIcon("image\\555.jpg"));
            j.setBounds(0,0,789,737);
            jd.getContentPane().add(j);
            jd.setSize(789,737);
            jd.setAlwaysOnTop(true);
            jd.setLocationRelativeTo(null);
            //弹框不关闭无法操作
            jd.setModal(true);
            jd.setVisible(true);
        }
        else if(obj==girl){
            // String path="image\\animal\\animal3\\";
            count=0;
            path="image\\girl\\girl"+r.nextInt(14)+"\\";
            initData();
            initImage();
        }
        else if(obj==animal){
            count=0;
            path="image\\animal\\animal"+r.nextInt(9)+"\\";
            initData();
            initImage();
        }
        else if(obj==sport){
            count = 0;
            path="image\\sport\\sport"+r.nextInt(11)+"\\";
            initData();
            initImage();
        }
    }
}
