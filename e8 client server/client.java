//Step 1: Start the program and print “Client started...”.

//Step 2: Create a Socket object to connect to the server at "localhost" on port 8888.

//Step 3: Create input and output streams for communication:

//DataInputStream for receiving messages from the server.

//DataOutputStream for sending messages to the server.

//Step 4: Also create a BufferedReader to read input from the client console (keyboard).

//Step 5: Print “Enter a message...”.

//Step 6: Read the message from the keyboard using BufferedReader.readLine().

//Step 7: Send this message to the server using writeUTF() and flush the output stream.

//Step 8: Print “Waiting for server reply...”.

//Step 9: Receive a message from the server using readUTF() and print it with a prefix "server says...".

//Step 10: Close the input and output streams to release resources.

import java.net.*;
import java.io.*;
public class client
{
  public static void main(String[]args)throws Exception
  {
   System.out.println("client started...");
   Socket s=new Socket("localhost",8888);
   DataInputStream din=new DataInputStream(s.getInputStream());
   DataOutputStream dout=new DataOutputStream(s.getOutputStream());
   BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
   System.out.println("enter a message....");
   String s1=br.readLine();
   dout.writeUTF(s1);
   dout.flush();
   System.out.println("Waiting for server reply...");
   String s2=din.readUTF();
   System.out.println("server says...:"+s2);
   din.close();
   dout.close();
 }
}


//output:
//client started...
//enter a message....
//hiiiiiiiiii...!
//Waiting for server reply...
//server says...:helloooo.....!


