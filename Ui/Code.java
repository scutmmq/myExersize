package Ui;

import java.util.Random;

public class Code {
    String code;
    static Random r =new Random();
    static char []arr=new char[62];
    public static String getcode(){
            for(int i=0;i<52;i++){
                if(i<26){
                    arr[i]=(char)(65+i);
                }
                else{
                    arr[i]=(char)(i+71);
                }
            }
            for(int i=52;i<62;i++){
                arr[i]=(char)(i-4);
            }
            String ans="";
            for(int i=0;i<5;i++) {
                ans+=arr[r.nextInt(62)];
            }
            return ans;
    }
}
