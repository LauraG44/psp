package psp.ut3.actividad3_4;

import javax.swing.*;
import java.text.SimpleDateFormat;
import java.util.Calendar;

public class JFrameReloj extends JFrame implements Runnable{
    private JPanel panel1;
    private JLabel labelTime;
    private Thread h1;

    public JFrameReloj() {
        setContentPane(panel1);
        setTitle("Reloj Digital");
        setSize(300, 150);
        setDefaultCloseOperation(JFrameReloj.EXIT_ON_CLOSE);
        h1 = new Thread(this);
        h1.start();
    }

    public void run() {
        Thread currentThread = Thread.currentThread();
        while (currentThread == h1) {
            SimpleDateFormat sdf = new SimpleDateFormat("HH:mm:ss");
            Calendar calendar = Calendar.getInstance();
            String horaActual = sdf.format(calendar.getTime());
            labelTime.setText(horaActual);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {}
        }
    }

    public static void main(String[] args){
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new JFrameReloj().setVisible(true);
            }
        });
    }

}
