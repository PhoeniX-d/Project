import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.io.FileInputStream;
import java.io.FileOutputStream;

public class FileUnpacker
{
    FileUnpacker(String src) throws IOException
    {
        fileUnpack(src);
    }

    public void fileUnpack(String filePath)
    {
        try {
            FileInputStream inStream = new FileInputStream(filePath);

            byte header[] = new byte[100];
            int size = 0;
            byte magic[] = new byte[11];
            inStream.read(magic, 0, magic.length);

            String magicStr = new String(magic);
            if (!magicStr.equals("LeafyBeacon")) {
                System.out.println("Invslid File for unpacking");
            }
            while ((size = inStream.read(header, 0, 100)) > 0) {
                String str = new String(header);
                String ext = str.substring(str.lastIndexOf("\\"));
                ext = ext.substring(1);

                String words[] = ext.split("\\s");
                int fileSize = Integer.parseInt(words[1]);
                byte[] arr = new byte[fileSize];
                inStream.read(arr, 0, fileSize);
                FileOutputStream outStream = new FileOutputStream(words[0]);
                outStream.write(arr, 0, fileSize);
            }
        } 
        catch (IOException ie) 
        {
            ie.printStackTrace();
        }
        catch (Exception e) 
        {
            e.printStackTrace();
        }
    }
    
    public static void main(String[] args) throws IOException
    {
        new FileUnpacker(args[0]);
    }
}
