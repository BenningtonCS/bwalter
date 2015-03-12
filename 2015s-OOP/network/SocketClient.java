import java.net.*;
import java.io.*;

/**
 * SocketClient.java
 * 2015 March 10
 * Brendon Walter
 *
 * Basic socket client program
 */
public class SocketClient {
    public static void main(String[] args) {
        String line;
        BufferedReader input;       // used to get information from server
        PrintStream output;         // used to send info to server
        Socket clientSocket;        

        try {
            // connect to server on local computer and port
            clientSocket = new Socket(args[0], 9090);
        } catch (IOException e) {
            e.printStackTrace();
            return;
        } catch (ArrayIndexOutOfBoundsException e) {
            e.printStackTrace();
            return;
        }

        try {
            // setup input from client
            input = new BufferedReader(
                    new InputStreamReader(clientSocket.getInputStream()));
            // setup output from server
            output = new PrintStream(clientSocket.getOutputStream());
            // get input from keyboard
            BufferedReader kbd = new BufferedReader(
                    new InputStreamReader(System.in));
            
            // infinite loop of the server. Wait for a request, then fulfill it
            while(true) {
                line = kbd.readLine();
                // echo input back to client
                output.println(line);
                // read something from the network and store it in 'line'
                line = input.readLine();
                // print line to the screen for debugging
                System.out.println(line);
            }
        } catch (IOException e) {
            e.printStackTrace();
            return;
        }
    }
}
