import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class FileUnpacker
{
    FileUnpacker(String src) throws IOException
    {
        fileUnpack(src);
    }

    public void fileUnpack(String filePath)
    {
        try
        {
            FileInputStream inStream = new FileInputStream(filePath);

            byte header[] = new byte[100];
            int size = 0;
            byte magic[] = new byte[11];
            inStream.read(magic, 0, magic.length);

            String magicStr = new String(magic);
            if (!magicStr.equals("LeafyBeacon")) {
                System.out.println("Invalid File for unpacking");
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
        catch (InvalidFileException ie) 
        {
            throw new InvalidFileException("Invalid packed file format");
        }
        catch (Exception e) 
        {
            e.printStackTrace();
        }
    }
}
