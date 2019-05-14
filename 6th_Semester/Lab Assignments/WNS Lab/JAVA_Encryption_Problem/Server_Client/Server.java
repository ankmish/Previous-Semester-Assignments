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
import java.net.ServerSocket;
import java.net.Socket;

/**
 *
 * @author AkM
 */
public class Server {
    
    private Socket sock = null;
    private ServerSocket servsock = null;
    private DataInputStream dis = null;
    private DataOutputStream dos = null;
    
    public Server(int port) throws IOException
    {
        servsock = new ServerSocket(port);
        
        System.out.println("Server waiting on port :4000");
        
        sock = servsock.accept();
        System.out.println("Client Connected");
        
        dis = new DataInputStream(new BufferedInputStream(sock.getInputStream()));
        String line = "";
        DataInputStream in = new DataInputStream(System.in);
        String ll ="";
        dos = new DataOutputStream(sock.getOutputStream());
        while(!line.equals("Over"))
        {
            line = dis.readUTF();
            System.out.println(line);
            ll = in.readLine();
            dos.writeUTF(ll);
        }
        
        dis.close();
        in.close();
        dos.close();
        sock.close();
        
    }
    public static void main(String args[]) throws IOException
    {
        Server ss = new Server(4000);
    }
    
}
