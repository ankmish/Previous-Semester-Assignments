/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package filetransfer;
import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import javax.crypto.Cipher;
import javax.crypto.spec.SecretKeySpec;
import java.io.BufferedInputStream;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.security.Key;
/**
 *
 * @author AkM
 */
public class ServerAES {
   
  static Cipher cipher;
  public final static int SOCKET_PORT = 4444;
  public final static String FILE_TO_SEND = "C:\\Users\\AkM\\Desktop\\java\\CryptoGraphic\\src\\cryptographic\\cleartext.txt";

 public static void main(String[] args) throws Exception {

    FileInputStream fis = null;
    BufferedInputStream bis = null;
    OutputStream os = null;
    ServerSocket servsock = null;
    Socket sock = null;
    try {
        servsock = new ServerSocket(SOCKET_PORT);
        while (true) {
            System.out.println("Waiting...");
            try {
                sock = servsock.accept();
                System.out.println("Accepted connection : " + sock);
                
                // send file
                File myFile = new File(FILE_TO_SEND);
                byte[] mybytearray = new byte[(int) myFile.length()];
                fis = new FileInputStream(myFile);
                bis = new BufferedInputStream(fis);
                bis.read(mybytearray, 0, mybytearray.length);
                 
                // encrypt file
                String key = "1234567812345678";
               // KeyGenerator keyGen = KeyGenerator.getInstance("DES");
               // SecretKey key = keyGen.generateKey();
		Key secretKey = new SecretKeySpec(key.getBytes(), "AES");
                cipher = Cipher.getInstance("AES");
                cipher.init(Cipher.ENCRYPT_MODE, secretKey);
                byte[] outputBytes = cipher.doFinal(mybytearray);
 
                Path path = Paths.get("C:\\Users\\AkM\\Desktop\\java\\CryptoGraphic\\src\\cryptographic\\ciphertextInClient.txt");
                Files.write(path, outputBytes);
                os = sock.getOutputStream();
                String stri = "C:\\Users\\AkM\\Desktop\\java\\CryptoGraphic\\src\\cryptographic\\ciphertextInClient.txt";
                System.out.println("Sending " + stri + "(" + outputBytes.length + " bytes)");
                os.write(outputBytes, 0, outputBytes.length);
                os.flush();  // Important
                System.out.println("Done.");
            } finally {
                if (bis != null) {
                    bis.close();
                }
                if (os != null) {
                    os.close();
                }
                if (sock != null) {
                    sock.close();
                }
            }
        }
    } finally {
        if (servsock != null) {
            servsock.close();
        }
    }
 }
}


//KeyGenerator keyGen = KeyGenerator.getInstance("AES");
//keyGen.init(256); // for example
//SecretKey secretKey = keyGen.generateKey();