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
import java.io.*;
import java.security.*;
import java.security.KeyPairGenerator;
import javax.crypto.Cipher;
import static filetransfer.ServerAES.SOCKET_PORT;
import java.net.*;
import java.nio.ByteBuffer;
import java.nio.file.Files;
import java.nio.file.Paths;
import javax.crypto.*;
import javax.crypto.spec.*;
import javax.xml.bind.DatatypeConverter;

public class RSAServer1 {

    public static void main(String[] args) throws Exception {

	KeyPairGenerator kpg = KeyPairGenerator.getInstance("RSA");
	Cipher cipher = Cipher.getInstance("RSA/ECB/PKCS1Padding");
	kpg.initialize(1024);
	KeyPair keyPair = kpg.generateKeyPair();
	PrivateKey privKey = keyPair.getPrivate();
	PublicKey pubKey = keyPair.getPublic();
          
	// server apni RSA public key bhej dega client ko...client AES key generate karega aur usse data encrypt karega
        // aur RSA wali key jo paya hai usse AES ki key ko encrypt karega...fir Server1 ko bhejga aur bs aage sambhal lo..

	cipher.init(Cipher.ENCRYPT_MODE, pubKey);
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
               
            // send RSA public key to CLient    
            try {
               System.out.println(DatatypeConverter.printHexBinary(pubKey.getEncoded()));
                ByteBuffer bb = ByteBuffer.allocate(4);
                bb.putInt(pubKey.getEncoded().length);
                sock.getOutputStream().write(bb.array());
                sock.getOutputStream().write(pubKey.getEncoded());
                sock.getOutputStream().flush();
            } catch (IOException e) {
                System.out.println("I/O Error");
                System.exit(0);
            }             
            BufferedReader in = new BufferedReader(
                            new InputStreamReader(sock.getInputStream()));
            String fromClient;
            
            while ((fromClient = in.readLine())!=null) {
                
           }

                // decrypt AES Key using RSA priavte Key
                String stri="C:\\Users\\AkM\\Desktop\\java\\CryptoGraphic\\src\\cryptographic\\encryptedAESKey.txt";
                File myFile = new File(stri);
                byte[] mybytearray = new byte[(int) myFile.length()];
                fis = new FileInputStream(myFile);
                bis = new BufferedInputStream(fis);
                bis.read(mybytearray, 0, mybytearray.length);
                cipher = Cipher.getInstance("RSA/ECB/PKCS1Padding");
                cipher.init(Cipher.DECRYPT_MODE, privKey);
                int len =  mybytearray.length;
                System.out.println(len);
                byte[] outputBytes = cipher.doFinal(mybytearray,0,len);
                //   System.out.println("huiii");
                SecretKey originalaesKey = new SecretKeySpec(outputBytes , 0, outputBytes.length, "AES");
                System.out.println("AES Key is  :"+originalaesKey);
              
               // yha tak verify ho gya...aes ki sahi key aa rhi hai 
               
               //decrypt the file
                stri="C:\\Users\\AkM\\Desktop\\java\\CryptoGraphic\\src\\cryptographic\\ciphertextInClientRSA.txt";
                myFile = new File(stri);
                mybytearray = new byte[(int) myFile.length()];
                fis = new FileInputStream(myFile);
                bis = new BufferedInputStream(fis);
                bis.read(mybytearray, 0, mybytearray.length);
                
                Cipher aesCipher = Cipher.getInstance("AES");
                aesCipher.init(Cipher.DECRYPT_MODE, originalaesKey);
                byte[] bytePlainText = aesCipher.doFinal(mybytearray);
                String plainText = new String(bytePlainText);
                System.out.println("Decrypted Text is :"+plainText);
                File ff = new File("C:\\Users\\AkM\\Desktop\\java\\CryptoGraphic\\src\\cryptographic\\decaesRSA.txt");
                Files.write(Paths.get("C:\\Users\\AkM\\Desktop\\java\\CryptoGraphic\\src\\cryptographic\\decaesRSA.txt"), plainText.getBytes());
               //  System.out.println("Done.");
                 
              //  flag = 1;
               // if(flag==1) break;
         //   }            
            }catch(Exception e){e.printStackTrace();}
            finally {
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
        
    
/*(Paragraph from Chilkat website)
Demonstrates how to use RSA to protect a key for AES encryption. 
It can be used in this scenario: 
You will provide your RSA public key to any number of counterparts.
Your counterpart will generate an AES key, encrypt data (or a file) using it,
then encrypt the AES key using your RSA public key. Your counterpart sends you both the encrypted
data and the encrypted key. Since you are the only one with access to the RSA private key, only you
can decrypt the AES key. You decrypt the key, then decrypt the data using the AES key.

This example will show the entire process. (1) Generate an RSA key and save both private and public 
parts to PEM files. (2) Encrypt a file using a randomly generated AES encryption key.
(3) RSA encrypt the AES key. (4) RSA decrypt the AES key. (5) Use it to AES decrypt the file or data.
*/