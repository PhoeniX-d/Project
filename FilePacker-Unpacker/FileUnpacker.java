import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class FileUnpacker
{
	File f;
	FileInputStream inStream;
	boolean isFileThere = true;
    FileUnpacker(String src) throws IOException
    {
        fileUnpack(src);
    }

    public void fileUnpack(String filePath) throws IOException
    {
    	f = new File(filePath);
    	if(f.exists() && f.isFile())
    	{
    		try
            {            	
                inStream = new FileInputStream(filePath);
                int size = 0;
                byte header[] = new byte[100];
                byte magic[] = new byte[11];
                inStream.read(magic, 0, magic.length); 
                
                magic = decryptData(magic);
                
                String magicStr = new String(magic);
                
                if (!magicStr.equals("LeafyBeacon")) 
                {
                	throw new InvalidFileException("Invalid packed file format");
                }
                while ((size = inStream.read(header, 0, 100)) > 0)
                {
                	header = decryptData(header);                	
                    String str = new String(header);
                    System.out.println(str);
                    String ext = str.substring(str.lastIndexOf("\\"));
                    ext = ext.substring(1);
                    String words[] = ext.split("\\s");
                    int fileSize = Integer.parseInt(words[1]);
                    
                    byte[] temp = words[0].getBytes();
                    String fileName = new String(temp);
                    System.out.println(fileName);
                    
                    byte[] arr = new byte[fileSize];
                    arr = decryptData(arr);
                    inStream.read(arr, 0, fileSize);
                    FileOutputStream outStream = new FileOutputStream(fileName);
                    outStream.write(arr, 0, fileSize);
                    outStream.close();
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
            finally
            {
            	inStream.close();
            }
    	}
    	else
    	{
    		isFileThere = false;
    	}
    }
     
    
    private byte[] decryptData(byte[] chunk)
    {
		byte[] cArr = new byte[chunk.length];		
		for(int i = 0; i < chunk.length; i++)
		{
			cArr[i] = (byte)(chunk[i] + 12);
		}
		return cArr;
	}
    
    public static void main(String[] args) throws IOException
    {
    	System.out.println("Hiii");
    	new FileUnpacker("BBBB.txt");
    }
}
