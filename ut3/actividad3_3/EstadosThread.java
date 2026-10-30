package psp.ut3.actividad3_3;

public class EstadosThread  {
    static class Hilo implements Runnable {
        @Override
        public void run(){
            try {
                Thread.sleep(200);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }
   
    
    public static void main(String[] args) throws Exception {
        Thread t = new Thread(new Hilo(), "Hilo-1");

        System.out.println("Estado inicial: " + t.getState());

        t.start();
        System.out.println("Tras start(): " + t.getState());

        Thread.sleep(50);
        System.out.println("Durante sleep(): " + t.getState());

        t.join(50);
        System.out.println("Durante join(): WAITING");
        System.out.println("Tras join(): " + t.getState());
    }
}