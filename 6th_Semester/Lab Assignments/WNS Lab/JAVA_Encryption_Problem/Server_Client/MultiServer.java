/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Server;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author AkM
 */
class MultiServer  {
    
    public static void main(String args[]) throws IOException{
        ServerSocket serve = null;
        serve = new ServerSocket(4000);
        System.out.println("Server Listening");
        
        while(true)
        {
             Socket sock = null;
            try {
            sock = serve.accept();
             DataInputStream dis = null;
            DataOutputStream dos = null;
            System.out.println("Client Accepted");
            dis = new DataInputStream(sock.getInputStream());
            dos = new DataOutputStream(sock.getOutputStream());
            
            System.out.println("Assigning new Thread to this client");
            
            Thread t = new ThreadHandler(sock,dis,dos);
            t.start();
            }
            catch(Exception e){sock.close();}
            
        }
    }
    
}
class ThreadHandler extends Thread
{
    Socket sock;
    DataInputStream dis;
    DataOutputStream dos;
    DataInputStream in;
    public ThreadHandler(Socket sock,DataInputStream dis,DataOutputStream dos)
    {
        this.sock = sock;
        this.dis = dis;
        this.dos = dos;
        in = new DataInputStream(System.in);
    }
    public void run()
    {
        String rec;
        String send;
        while(true)
        {
            try {
                 rec = dis.readUTF();
                 System.out.println(rec);
                  send = in.readLine();
                 dos.writeUTF(send);
                 if(rec.equals("Over")){
                     break;
                 }
            } catch (IOException ex) {
                Logger.getLogger(ThreadHandler.class.getName()).log(Level.SEVERE, null, ex);
            }

        }
        try {
            this.dis.close();
            this.dos.close();
            this.in.close();
        } catch (IOException ex) {
            Logger.getLogger(ThreadHandler.class.getName()).log(Level.SEVERE, null, ex);
        }
        
    }
}
