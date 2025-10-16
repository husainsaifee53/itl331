
// # **Selective Repeat Protocol**



// ### AIM:

// Implementation of Medium Access Control protocols - Selective Repeat



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

// ```
<!-- client -->
Localhost/127.0.0.1
No of frame is:8
30
40
50
60
70
80
90
100
Received frame is: 30
Received frame is: 40
Received frame is: 50
Received frame is: 60
Received frame is: 70
Received frame is: 80
Received frame is: -1
Received frame is: 100
Request to retransmit from packet no 7 again!!

Received frame is: 90
quiting


<!-- server -->

waiting for connection
The number of packets sent is:8


// ### RESULT:

// Program to implement **Selective Repeat** has been successfully executed and output verified.


