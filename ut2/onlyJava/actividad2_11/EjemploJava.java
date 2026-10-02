import java.io.*;

public class EjemploJava {
    public static void main (String[] args) throws IOException {

        File directorio = new File("./actividad2_10");

        ProcessBuilder pb = new ProcessBuilder("java", "EjemploComando");

        pb.inheritIO();

        pb.directory(directorio);
        System.out.printf("Directorio de trabajo %s%n", pb.directory);

        Process p = pb.start();
    }
}