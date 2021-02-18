import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Stream;

import javax.swing.JFrame;
import javax.swing.JOptionPane;

public class FilePacker extends JFrame
{
    // create FileOutputStream object for destination file 
    FileOutputStream outStream = null;

    // We support files with following extensions to be packed    
    String validExtensions[] = {".txt", ".c", ".cpp", ".java", ".cs", ".js"};
      
    String validExt;
    static boolean flag = false;
    boolean isDirExists = true;

    // constructor
    public FilePacker(String src, String extension, String dest, String username) throws Exception
    {
    	// Implement Magic number code
        String magic = "LeafyBeacon";
        byte arr[] = magic.getBytes();
        
        arr = encryptData(arr);
        
        outStream = new FileOutputStream(dest);
        outStream.write(arr, 0, arr.length);

        File folder = new File(src);
        if(folder.exists() && folder.isDirectory())
        {
        	listAllFiles(folder.getAbsolutePath(), extension);
        }
        else
        {
        	String str = new String("Source directory does not exists");
    		JOptionPane.showMessageDialog(this, str, "File Packer-Unpacker", JOptionPane.INFORMATION_MESSAGE);
    		this.isDirExists = false;
        }
        outStream.close();
    }
    
    public void listAllFiles(String path, String extension)
    {
        try (Stream<Path> paths = Files.walk(Paths.get(path)))
        {
            paths.forEach(filePath ->
            {
                if (Files.isRegularFile(filePath))
                {
                    try
                    {
                        String name = filePath.getFileName().toString();
                        String ext = name.substring(name.lastIndexOf("."));
                        List<String> list = Arrays.asList(validExtensions);
                        
                        if(extension.equals("All"))
                        {               
                            if (list.contains(ext))
                            {
                                filePack(filePath.toString());
                            }
                        }
                        else
                        {
                        	if (list.contains(ext))
                            {
                        		if(ext.equals(extension))
                        		{
                        			filePack(filePath.toString());
                        		}                  
                            }                    
                        }
                    }
                    catch (Exception e)
                    {
                        e.printStackTrace();
                    }
                }
            });
        } 
        catch (IOException e) 
        {
            e.printStackTrace();
        }
        finally
        {
        	if(flag == false)
        	{
        		String str = new String("Source Directory does not contain file with selected extension");
        		JOptionPane.showMessageDialog(this, str, "File Packer-Unpacker", JOptionPane.INFORMATION_MESSAGE);
        	}
        }
    }
    
    public void filePack(String filePath)
    {
    	flag = true;
        FileInputStream inStream = null;
        try 
        {
            byte[] buffer = new byte[1024];
            int length = 0;
            byte[] temp = new byte[100];
            File fObj = new File(filePath);
            StringBuffer header = new StringBuffer();
            long fileSize = fObj.length();
            header.append(filePath).append(" ").append(fileSize);

            // filling extra space with whitespaces
            for (int i = header.length(); i < 100; i++) {
                header.append(" ");
            }

            // for simplicity convert header into byte array
            temp = header.toString().getBytes();
            
            // create object of FileInputStream to read data from file
            inStream = new FileInputStream(filePath);            
            
            temp = encryptData(temp);
            
            // first write our header to Dest file whose object is outstream
            outStream.write(temp, 0, temp.length);

            // read all data from that directory file and write it into Dest file(Pack file)
            while ((length = inStream.read(buffer)) > 0) 
            {
            	buffer = encryptData(buffer);
                outStream.write(buffer, 0, length);
            }

            // close file that we read in this function
            inStream.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    private byte[] encryptData(byte[] chunk)
    {
		byte[] cArr = new byte[chunk.length];		
		for(int i = 0; i < chunk.length; i++)
		{
			cArr[i] = (byte)(chunk[i] - 12);
		}
		return cArr;
	}
     
    public static void main(String[] args) throws Exception
    {
    	new FilePacker("demo", "All", "BBBB.txt", "Admin");
    }
}
