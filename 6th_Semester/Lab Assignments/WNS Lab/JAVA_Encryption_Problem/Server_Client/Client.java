/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Server;

import java.io.BufferedInputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;

/**
 *
 * @author AkM
 */
public class Client {
    
    private Socket socket = null;
    private DataInputStream dis = null;
    private DataOutputStream dos = null;
    
    
    public Client(String address,int port) throws IOException
    {
        socket = new Socket(address,port);
        System.out.println("Client Connected ");
        
        // take input from terminal
        dis = new DataInputStream(System.in);
        // send output to socket
        dos = new DataOutputStream(socket.getOutputStream());
        
        DataInputStream in = new DataInputStream(new BufferedInputStream(socket.getInputStream()));
        String line="";
        while(!line.equals("Over"))
        {
            line = dis.readLine();
            dos.writeUTF(line);
            String l = in.readUTF();
            System.out.println(l);
        }
        dis.close();
        dos.close();
        socket.close();
    }
    
    public static void main(String args[]) throws IOException{   
        
        Client cc = new Client("127.0.0.1",4000);
    } 
}
