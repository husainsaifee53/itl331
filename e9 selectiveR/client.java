import java.net.*;
import java.io.*;
import java.util.Random;

public class client {
    static Socket connection;

    public static void main(String a[]) {
        try {
            int v[] = new int[10];
            int n = 0;
            Random rands = new Random();
            int rand = 0;

            InetAddress addr = InetAddress.getByName("Localhost");
            System.out.println(addr);

            connection = new Socket(addr, 8011);
            DataOutputStream out = new DataOutputStream(connection.getOutputStream());
            DataInputStream in = new DataInputStream(connection.getInputStream());

            int p = in.read();
            System.out.println("No of frame is:" + p);

            for (int i = 0; i < p; i++) {
                v[i] = in.read();
                System.out.println(v[i]);
            }

            // Randomly mark a frame as lost (-1)
            rand = rands.nextInt(p);
            v[rand] = -1;

            for (int i = 0; i < p; i++) {
                System.out.println("Received frame is: " + v[i]);
            }

            for (int i = 0; i < p; i++) {
                if (v[i] == -1) {
                    System.out.println("Request to retransmit from packet no " + (i + 1) + " again!!");
                    n = i;
                    out.write(n);
                    out.flush();
                }
            }

            System.out.println();
            v[n] = in.read();
            System.out.println("Received frame is: " + v[n]);
            System.out.println("quiting");
            connection.close();

        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
// '
// ---

// # **Selective Repeat Protocol**

// ---

// ### AIM:

// Implementation of Medium Access Control protocols - Selective Repeat

// ---

// ### ALGORITHM:

// #### SERVER:

// 1. Start.
// 2. Establish connection (recommended UDP).
// 3. Accept the window size from the client (should be ≤ 40).
// 4. Accept the packets from the network layer.
// 5. Calculate the total frames/windows required.
// 6. Send the details to the client (total packets, total frames).
// 7. Initialize the transmit buffer.
// 8. Build the frame/window depending on the window size.
// 9. Transmit the frame.
// 10. Wait for the acknowledgement frame.
// 11. Check for the acknowledgement of each packet and retransmit packets for which negative acknowledgement is received. Otherwise, continue as usual.
// 12. Increment the frame count and repeat steps 7 to 12 until all packets are transmitted.
// 13. Close the connection.
// 14. Stop.

// #### CLIENT:

// 1. Start.
// 2. Establish a connection (recommended UDP).
// 3. Send the window size on server request.
// 4. Accept the details from the server (total packets, total frames).
// 5. Initialize the receive buffer with the expected packets.
// 6. Accept the frame/window from the server.
// 7. Check validity of the packets and construct the acknowledgement frame depending on validity (acknowledgements accepted from user).
// 8. Depending on the acknowledgement frame, readjust the process.
// 9. Increment the frame count and repeat steps 5 to 9 until all packets are received.

// ---

// ### PROGRAM:

// #### Client Side (Selective Repeat)

// ```java
// import java.net.*;
// import java.io.*;
// import java.util.Random;

// public class cli {
//     static Socket connection;

//     public static void main(String a[]) {
//         try {
//             int v[] = new int[10];
//             int n = 0;
//             Random rands = new Random();
//             int rand = 0;

//             InetAddress addr = InetAddress.getByName("Localhost");
//             System.out.println(addr);

//             connection = new Socket(addr, 8011);
//             DataOutputStream out = new DataOutputStream(connection.getOutputStream());
//             DataInputStream in = new DataInputStream(connection.getInputStream());

//             int p = in.read();
//             System.out.println("No of frame is:" + p);

//             for (int i = 0; i < p; i++) {
//                 v[i] = in.read();
//                 System.out.println(v[i]);
//             }

//             // Randomly mark a frame as lost (-1)
//             rand = rands.nextInt(p);
//             v[rand] = -1;

//             for (int i = 0; i < p; i++) {
//                 System.out.println("Received frame is: " + v[i]);
//             }

//             for (int i = 0; i < p; i++) {
//                 if (v[i] == -1) {
//                     System.out.println("Request to retransmit from packet no " + (i + 1) + " again!!");
//                     n = i;
//                     out.write(n);
//                     out.flush();
//                 }
//             }

//             System.out.println();
//             v[n] = in.read();
//             System.out.println("Received frame is: " + v[n]);
//             System.out.println("quiting");
//             connection.close();

//         } catch (Exception e) {
//             System.out.println(e);
//         }
//     }
// }
// ```

// ---

// #### Server Side (Selective Repeat)

// ```java
// import java.io.DataInputStream;
// import java.io.DataOutputStream;
// import java.io.IOException;
// import java.net.ServerSocket;
// import java.net.Socket;

// public class ser {
//     static ServerSocket Serversocket;
//     static DataInputStream dis;
//     static DataOutputStream dos;

//     public static void main(String[] args) {
//         try {
//             int a[] = {30, 40, 50, 60, 70, 80, 90, 100};
//             Serversocket = new ServerSocket(8011);
//             System.out.println("waiting for connection");

//             Socket client = Serversocket.accept();
//             dis = new DataInputStream(client.getInputStream());
//             dos = new DataOutputStream(client.getOutputStream());

//             System.out.println("The number of packets sent is:" + a.length);
//             int y = a.length;
//             dos.write(y);
//             dos.flush();

//             for (int i = 0; i < a.length; i++) {
//                 dos.write(a[i]);
//                 dos.flush();
//             }

//             int k = dis.read();
//             dos.write(a[k]);
//             dos.flush();

//             dis.close();
//             dos.close();
//             client.close();
//             Serversocket.close();

//         } catch (IOException e) {
//             System.out.println(e);
//         }
//     }
// }
// ```

// ---

// ### SAMPLE OUTPUT (Client Side)

// ```
// Localhost/127.0.0.1
// No of frame is:8
// 30
// 40
// 50
// 60
// 70
// 80
// 90
// 100
// Received frame is: 30
// Received frame is: 40
// Received frame is: 50
// Received frame is: -1
// Received frame is: 70
// Received frame is: 80
// Received frame is: 90
// Received frame is: 100
// Request to retransmit from packet no 4 again!!
// Received frame is: 60
// quiting
// ```

// ---

// ### RESULT:

// Program to implement **Selective Repeat** has been successfully executed and output verified.

// ---

// If you want, I can help you with the **UDP-based implementation** or expand the window size logic. Let me know!
