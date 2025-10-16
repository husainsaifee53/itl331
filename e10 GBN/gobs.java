//GO-BACK-N -SERVER
//PROGRAM

import java.net.*;
import java.io.*;
public class gobs
 {
  public static void main(String args[]) throws IOException 
   {
    ServerSocket ss = new ServerSocket(8088);
    Socket s = ss.accept();
    DataInputStream din = new DataInputStream(s.getInputStream());
    DataOutputStream dout = new DataOutputStream(s.getOutputStream());
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int frames[] = new int[20];
    System.out.print("Enter number of frames to send: ");
    int n = Integer.parseInt(br.readLine());
    System.out.println("Enter " + n + " frame values:");
    for(int i = 0; i < n; i++) 
     {
      frames[i] = Integer.parseInt(br.readLine());
     }
    System.out.println("Sending " + n + " frames...");
    dout.write(n); 
    dout.flush();
    for(int i = 0; i < n; i++) 
     {
      dout.write(frames[i]); 
      dout.flush();
      System.out.println("Frame " + i + " sent: " + frames[i]);
     }
    int lost = din.read(); 
    System.out.println("Client reported loss at frame number: " + lost);
    System.out.println("Resending from frame " + lost + " onwards...");
    for(int i = lost; i < n; i++)
     {
      dout.write(frames[i]);
      dout.flush();
      System.out.println("Resent frame " + i + ": " + frames[i]);
     }
    din.close();
    dout.close();
    s.close();
    ss.close();
   }
 }
 
//OUTPUT

//Enter number of frames to send: 4
//Enter 4 frame values:
//5
//6
//7
//3
//Sending 4 frames...
//Frame 0 sent: 5
//Frame 1 sent: 6
//Frame 2 sent: 7
//Frame 3 sent: 3
//Client reported loss at frame number: 1
//Resending from frame 1 onwards...
//Resent frame 1: 6
//Resent frame 2: 7
//Resent frame 3: 3



/*Algorithm: Go-Back-N ARQ (Server Side)

1. Start 
2. Create a `ServerSocket` on port 8088.
3. Wait for client connection and accept it to obtain a socket.
4. Create input and output data streams for communication.
5. Create a buffered reader to read input from the keyboard.
6. Declare an array frames[] to store frame values to be sent.
7. Wait to read the number of frames to send from the keyboard.
8. Display to enter the frame values.
9. For i = 0 to n−1:
    9.1. Read frame value from the keyboard.
    9.2. Store it in frames[i].
10. Display that frames are being sent.
11. Send the number of frames to the client.
12. For i = 0 to n−1:
     12.1. Send frames[i] to the client.
     12.2. Display frame i is sent.
13. Wait to receive the lost frame number from the client.
14. Display which frame is lost.
15. Display that resending frames is starting.
16.For i = lost to n−1:
     16.1. Resend frames[i] to the client.
     16.2. Display frame i is resent.
17. Close all input, output streams, and the socket and server socket.
18.Stop.
*/


