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
import de.flexiprovider.api.exceptions.InvalidKeySpecException;
import de.flexiprovider.pki.X509EncodedKeySpec;
import java.security.*;
import javax.crypto.*;
import java.io.*;
import java.net.Socket;
import java.nio.ByteBuffer;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import javax.xml.bind.DatatypeConverter;
public class RSAClient1 {
    
    static Cipher cipher;
    public final static int SOCKET_PORT = 4444;
    public final static String SERVER = "127.0.0.1";
   public final static String FILE_TO_SEND = "C:\\Users\\AkM\\Desktop\\java\\CryptoGraphic\\src\\cryptographic\\cleartext.txt";
    public final static int FILE_SIZE = 6022384;
    

public static void main (String [] args ) throws IOException, Exception {

    Socket sock = null;
    Key serverPubKey = null;
    FileInputStream fis = null;
    BufferedInputStream bis = null;
    OutputStream os = null;
    byte[] servPubKeyBytes;
try {
      sock = new Socket(SERVER, SOCKET_PORT);
      System.out.println("Connecting...");
      
      // get Server RSA public key
        try{
            byte[] lenb = new byte[4];
            sock.getInputStream().read(lenb,0,4);
            ByteBuffer bb = ByteBuffer.wrap(lenb);
            int len = bb.getInt();
            System.out.println(len);
            servPubKeyBytes = new byte[len];
            sock.getInputStream().read(servPubKeyBytes);
            System.out.println(DatatypeConverter.printHexBinary(servPubKeyBytes));
            X509EncodedKeySpec ks = new X509EncodedKeySpec(servPubKeyBytes);
            KeyFactory kf = KeyFactory.getInstance("RSA");
            serverPubKey = kf.generatePublic(ks);
            System.out.println(DatatypeConverter.printHexBinary(serverPubKey.getEncoded()));
        } catch (IOException e) {
            System.out.println("Error obtaining server public key 1.");
            System.exit(0);
        } catch (NoSuchAlgorithmException e) {
            System.out.println("Error obtaining server public key 2.");
            System.exit(0);
        } catch (InvalidKeySpecException e) {
            System.out.println("Error obtaining server public key 3.");
            System.exit(0);
        }   
      // till here verified ki .... sahi RSA key mil rhi hai ....
      // ab yha se nya khel start karo ... AES key banao .....
        
                 // encrypt file
                File myFile = new File(FILE_TO_SEND);
                byte[] mybytearray = new byte[(int) myFile.length()];
                fis = new FileInputStream(myFile);
                bis = new BufferedInputStream(fis);
                bis.read(mybytearray, 0, mybytearray.length);
                 
                KeyGenerator keyGen = KeyGenerator.getInstance("AES");
                keyGen.init(128);
                SecretKey secretKey = keyGen.generateKey();
                System.out.println(secretKey);
		//Key secretKey = new SecretKeySpec(key.getBytes(), "AES");
                cipher = Cipher.getInstance("AES");
                cipher.init(Cipher.ENCRYPT_MODE, secretKey);    
                byte[] outputBytes = cipher.doFinal(mybytearray);
                
                // cipher text is file me likh do
                Path path = Paths.get("C:\\Users\\AkM\\Desktop\\java\\CryptoGraphic\\src\\cryptographic\\ciphertextInClientRSA.txt");
                Files.write(path, outputBytes);
                os = sock.getOutputStream();
                String stri = "C:\\Users\\AkM\\Desktop\\java\\CryptoGraphic\\src\\cryptographic\\ciphertextInClientRSA.txt";
                System.out.println("Sending " + stri + "(" + outputBytes.length + " bytes)");
                os.write(outputBytes, 0, outputBytes.length);
                //  os.flush();  // Important    ... yha mat lagao .... nhi toh fat ke haath me aa gyi jaegi
                
                // encrypt AES key with RSA public key
                Cipher cipher1 = Cipher.getInstance("RSA/ECB/PKCS1Padding");
                cipher1.init(Cipher.ENCRYPT_MODE,serverPubKey );
                
                byte [] aesKeyByte=secretKey.getEncoded();
                System.out.println( aesKeyByte.length);
                outputBytes = cipher1.doFinal(aesKeyByte);
              //  System.out.println(outputBytes);
                // Encrypted AES key ko  is file me likh do
                path = Paths.get("C:\\Users\\AkM\\Desktop\\java\\CryptoGraphic\\src\\cryptographic\\encryptedAESKey.txt");
                Files.write(path, outputBytes);
                os = sock.getOutputStream();
                stri = "C:\\Users\\AkM\\Desktop\\java\\CryptoGraphic\\src\\cryptographic\\encryptedAESKey.txt";
                System.out.println("Sending " + stri + "(" + outputBytes.length + " bytes)");
                os.write(outputBytes, 0, outputBytes.length);
                DataOutputStream  out    = new DataOutputStream(sock.getOutputStream());
                out.writeUTF("Over");
                out.flush();
                os.flush();  // Important
                System.out.println("Done.");
                
                // yha tak AES ki key aur plane text Encrypt ho  jana chahiye..
                // Verifieddd.......
    }
    catch(Exception e ){
        e.printStackTrace();
    }finally {
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
}