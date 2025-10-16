//Algorithm: Server Socket Communication

//Step 1: Start the program and print “Waiting for client…”.

//Step 2: Create a ServerSocket object on a specific port (port 8888 in this case).

//Step 3: Wait for a client to connect by calling accept() on the ServerSocket.
   // → This call blocks until a connection is made.

//Step 4: Once a connection is established, print “connected client…”.

//Step 5: Create input and output streams for communication:

//DataInputStream for receiving messages from the client.

//DataOutputStream for sending messages to the client.

//Step 6: Also create a BufferedReader to read input from the server console (keyboard).

//Step 7: Print “Waiting for client message…”.

//Step 8: Receive a message from the client using readUTF() and print it with a prefix "client:".

//Step 9: Prompt the server user to enter a message for the client.

//Step 10: Read the message from the console input using BufferedReader.readLine().

//Step 11: Send this message to the client using writeUTF() and flush the output stream.

//Step 12: Close the socket and the server socket to release resources.


import java.net.*;
import java.io.*;
public class server
{
  public static void main(String[]args)throws Exception
  {
    System.out.println("Waiting for client....");
    ServerSocket ss=new ServerSocket(8888);
    Socket s=ss.accept();
    System.out.println("connected client....");
    DataInputStream din=new DataInputStream(s.getInputStream());
    DataOutputStream dout=new DataOutputStream(s.getOutputStream());
    BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    System.out.println("Waiting for client message...");
    String s1=din.readUTF();
    System.out.println("client:"+s1);
    System.out.println("enter the message to client..");
    String s2=br.readLine();
    dout.writeUTF(s2);
    dout.flush();
    s.close();
    ss.close();
 }
}

//output:
//Waiting for client....
//connected client....
//Waiting for client message...
//client:hiiiiiiiiii...!
//enter the message to client..
//helloooo.....!












