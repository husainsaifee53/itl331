//Go-Back-N (Client Side)

import java.net.*;
import java.io.*;
import java.util.Random;
public class gobc
 {
  public static void main(String args[]) throws Exception
   {
    Socket s = new Socket("localhost", 8088);
    DataInputStream din = new DataInputStream(s.getInputStream());
    DataOutputStream dout = new DataOutputStream(s.getOutputStream());
    int frames[] = new int[20];
    int n = din.read();
    System.out.println("Number of frames received: " + n);
    for (int i = 0; i < n; i++)
     {
      frames[i] = din.read();
      System.out.println("Received frame " + i + ": " + frames[i]);
     }
    Random r = new Random();
    int lost = r.nextInt(n);
    System.out.println("\nFrame " + lost + " lost during transmission!");       
    dout.write(lost);
    dout.flush();      
    System.out.println("\nReceiving retransmitted frames...");
    for (int i = lost; i < n; i++)
     {
      frames[i] = din.read();
      System.out.println("Received frame " + i + ": " + frames[i]);
     }
    System.out.println("\nAll frames received successfully!");
    dout.close();
    din.close();
    s.close();
  }
 }
 
//OUTPUT
 
//Number of frames received: 4
//Received frame 0: 5
//Received frame 1: 6
//Received frame 2: 7
//Received frame 3: 3

//Frame 1 lost during transmission!

//Receiving retransmitted frames...
//Received frame 1: 6
//Received frame 2: 7
//Received frame 3: 3

//All frames received successfully!
 
 
//Algorithm: Go-Back-N (Client Side)

//1.Start program.
//2.Connect to the server at port 8088.
//3.Create input and output data streams for communication.
//4.Declare an array frames[] to store received frame values.
//5.Wait to receive the number of frames from the server.
//6.Display the number of frames received.
//7.For i = 0 to n−1:
	//7.1. Receive each frame from the server.
	//7.2. Display the frame number and its data for every frame received.
//8.Randomly select one frame to simulate as lost during transmission.
//9.Display which frame is lost.
//10.Send the lost frame number back to the server.
//11.Display a message that retransmission is starting.
//12.For i = lost to n−1:
	//12.1. Receive retransmitted frame from the server.
	//12.2. Display each retransmitted frame received successfully.
//13.Display that all frames have been received successfully.
//14.Close all connections (input, output, and socket).
//15.Stop program.

 
 
 
 
 


