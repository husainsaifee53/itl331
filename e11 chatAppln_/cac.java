import java.io.*;
import java.net.*;

public class cac {
    public static void main(String[] args) throws Exception {
        Socket sock = new Socket("127.0.0.1", 3000);

        // Read from keyboard (Client user input)
        BufferedReader keyRead = new BufferedReader(new InputStreamReader(System.in));

        // Send to server
        OutputStream ostream = sock.getOutputStream();
        PrintWriter pwrite = new PrintWriter(ostream, true);

        // Receive from server
        InputStream istream = sock.getInputStream();
        BufferedReader receiveRead = new BufferedReader(new InputStreamReader(istream));

        System.out.println("Start the chat, type your message and press Enter:");

        String receiveMessage, sendMessage;

        while (true) {
            sendMessage = keyRead.readLine();   // Read user input
            pwrite.println(sendMessage);        // Send to server
            pwrite.flush();

            if ((receiveMessage = receiveRead.readLine()) != null) {
                System.out.println("Server: " + receiveMessage);
            }
        }
    }
}
