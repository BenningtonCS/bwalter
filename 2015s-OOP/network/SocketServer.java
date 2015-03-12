import java.io.*;
import java.net.*;

/**
 * SocketServer.java
 * 2015 March 10
 * Brendon Walter
 *
 * basic socket server program
 */
public class SocketServer {
    public static void main(String[]  args) {

        ServerSocket echoServer = null; // server that listens
        String line;            // text data that's exchanged
        BufferedReader input;   // used to read from network
        PrintStream output;     // used to write to network
        Socket clientSocket;    // used to talk back to client

        try {
            // claim port 9090
            echoServer = new ServerSocket(9090);
        } catch (IOException e) {
            e.printStackTrace();
            return;
        }

        try {
            // accept connection with the client
            clientSocket = echoServer.accept();
            // setup input from client
            input = new BufferedReader(
                    new InputStreamReader(clientSocket.getInputStream()));
            // setup output from server
            output = new PrintStream(clientSocket.getOutputStream());

            // infinite loop of the server. Wait for a request, then fulfill it
            while(true) {
                // read something from the network and store it in 'line'
                line = input.readLine();
                // print line to the screen for debugging
                System.out.println(line);
                // echo input back to client
                output.println(line);
            }

        } catch (IOException e) {
             e.printStackTrace();
             return;
        }
    }
}
