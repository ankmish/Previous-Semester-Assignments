/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package filetransfer;
/**
 *
 * @author AkM
 */
import java.security.*;
import javax.crypto.*;
import java.io.*;
import java.net.Socket;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Arrays;

import javax.crypto.spec.SecretKeySpec;
public class ClientAES {
    
    static Cipher cipher;
    public final static int SOCKET_PORT = 4444;
    public final static String SERVER = "127.0.0.1";
    public final static String FILE_TO_RECEIVED = "C:\\Users\\AkM\\Desktop\\java\\CryptoGraphic\\src\\cryptographic\\ciphertextInClient.txt";
    public final static int FILE_SIZE = 6022384;

    public static void main (String [] args ) throws IOException, Exception {
    int bytesRead;
    int current = 0;
    FileOutputStream fos = null;
    BufferedOutputStream bos = null;
    Socket sock = null;
   
try {
      sock = new Socket(SERVER, SOCKET_PORT);
      System.out.println("Connecting...");
      // receive file
      byte [] mybytearray  = new byte [FILE_SIZE];
      InputStream is = sock.getInputStream();
      fos = new FileOutputStream(FILE_TO_RECEIVED);
      bos = new BufferedOutputStream(fos);
      bytesRead = is.read(mybytearray,0,mybytearray.length);
   
      current = bytesRead;
      do {
         bytesRead = is.read(mybytearray, current, (mybytearray.length-current));
         if(bytesRead >= 0) current += bytesRead;
      } while(bytesRead > -1);
      
        byte[] todo = new byte[current];
        todo = Arrays.copyOf(mybytearray, current);
       System.out.println("File " + FILE_TO_RECEIVED
          + " downloaded (" + current + " bytes read)");
        String rc = new String(todo);
   
        String key ="1234567812345678";
  
        Key secretKey = new SecretKeySpec(key.getBytes(), "AES");
        Cipher cipher = Cipher.getInstance("AES");
        cipher.init(Cipher.DECRYPT_MODE, secretKey);
        String enc = new String(todo);
        String decrypted =new String( cipher.doFinal(todo),"UTF8") ;
        File ff = new File("C:\\Users\\AkM\\Desktop\\java\\CryptoGraphic\\src\\cryptographic\\decaes.txt");
        Files.write(Paths.get("C:\\Users\\AkM\\Desktop\\java\\CryptoGraphic\\src\\cryptographic\\decaes.txt"), decrypted.getBytes());
        System.out.println("Decrypted is : "+decrypted);
        bos.flush();
    }
    catch(Exception e ){
        e.printStackTrace();
    }
  
  }
}















      // decode the base64 encoded string
     // byte[] decodedKey = Base64.getDecoder().decode(encodedKey);
     // rebuild key using SecretKeySpec
   //  SecretKey originalKey = new SecretKeySpec(decodedKey, 0, decodedKey.length, "AES"); 
    //  String encypted =   new String(mybytearray);
    //  ClientAES cc = new ClientAES();
    //   System.out.println("Dheere se bol do key : " +originalKey);
    //  String dec = cc.decrypt(encypted,originalKey);