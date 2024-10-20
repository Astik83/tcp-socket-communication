# tcp-socket-communication

Here’s how you can describe the project for your GitHub repository:

---

## Simple TCP Client-Server Communication in C

### Overview
This project demonstrates a simple implementation of **TCP (Transmission Control Protocol)** communication using **sockets** in C. The client and server programs establish a connection where messages are exchanged continuously until either the client or server sends an **"exit"** message to terminate the communication.

### Features
- **Client-Server Communication:** A TCP connection is established between a client and a server running on the same machine (localhost) using the `127.0.0.1` IP address.
- **Message Transfer:** Both the client and server can send and receive messages repeatedly until the communication is terminated by sending the "exit" message.
- **Graceful Termination:** The client or server can exit the communication loop by sending "exit". Both sides will close the connection gracefully.

### How It Works
1. **Server Setup:**
   - The server sets up a socket, binds it to a port (8001 in this case), and listens for incoming client connections.
   - Once a client connects, the server waits for messages from the client, processes them, and can send a response back.

2. **Client Setup:**
   - The client establishes a connection to the server and sends messages to it.
   - After each message sent, the client waits for the server's response and displays it.

3. **Continuous Message Exchange:**
   - Both the client and server can continuously exchange messages.
   - The connection is terminated when either the client or server sends the message `"exit"`.

### Files
- `client.c`: Contains the code for the TCP client.
- `server.c`: Contains the code for the TCP server.

### Usage
1. **Compile the code:**
   ```bash
   gcc client.c -o client
   gcc server.c -o server
   ```

2. **Run the server:**
   ```bash
   ./server
  

3. **Run the client (in a different terminal):**
   ```bash
   ./client
   

4. **Communication:**
   - The client and server can now send messages back and forth.
   - To terminate the communication, type `"exit"` from either the client or server.

### Example Interaction

 Server

Server creation successful.
Server binding successful.
Connection established.
Client request: Hello, Server!
Enter response to client (type 'exit' to quit): Hi, Client!
Client request: exit
Client requested to exit. Exiting...


Client

Connected to server.
Enter message for server (type 'exit' to quit): Hello, Server!
Server response: Hi, Client!
Enter message for server (type 'exit' to quit): exit
Exiting...


### Notes
- The server listens on port 8001 and runs locally on `127.0.0.1`.
- The code can be extended to handle multiple clients using threading or `select()` for concurrent connections.





 

