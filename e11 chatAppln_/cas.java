import java.io.*;
import java.net.*;

public class cas{
    public static void main(String[] args) throws Exception {
        ServerSocket sersock = new ServerSocket(3000);
        System.out.println("Server ready for chatting...");

        Socket sock = sersock.accept();  // Accept incoming client
        System.out.println("Client connected.");

        // Read from keyboard (Server user input)
        BufferedReader keyRead = new BufferedReader(new InputStreamReader(System.in));

        // Send to client
        OutputStream ostream = sock.getOutputStream();
        PrintWriter pwrite = new PrintWriter(ostream, true);

        // Receive from client
        InputStream istream = sock.getInputStream();
        BufferedReader receiveRead = new BufferedReader(new InputStreamReader(istream));

        String receiveMessage, sendMessage;

        while (true) {
            if ((receiveMessage = receiveRead.readLine()) != null) {
                System.out.println("Client: " + receiveMessage);
            }

            sendMessage = keyRead.readLine();
            pwrite.println(sendMessage);
            pwrite.flush();
        }
    }
}
