package psp.ut3.actividad3_2;

public class ThreadEjemploRunnable implements Runnable {

    public void run() {
        for (int i = 0; i < 5 ; i++)
            System.out.println(i + " " + Thread.currentThread().getName());
        System.out.println("Termina thread " + Thread.currentThread().getName());
    }

    public static void main (String[] args) {

        ThreadEjemploRunnable ejemplo = new ThreadEjemploRunnable();
        Thread hilo1 =  new Thread (ejemplo, "Pepe");
        Thread hilo2 =  new Thread (ejemplo, "Juan");
        hilo1.start();
        hilo2.start();
        System.out.println("Termina thread main");
    }
}