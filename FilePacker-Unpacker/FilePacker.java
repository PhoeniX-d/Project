import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;
import java.util.stream.Stream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Arrays;

public class FilePacker
{
    // create FileOutputStream object for destination file 
    FileOutputStream outStream = null;

    // We support files with following extensions to be packed
    String validExtensions[] = {".txt", ".c", ".cpp", ".java", ".cs", ".js"};

    // constructor
    FilePacker(String src, String dest) throws IOException
    {
        // Implement Magic number code
        String magic = "LeafyBeacon";
        byte arr[] = magic.getBytes();

        outStream = new FileOutputStream(dest);
        outStream.write(arr, 0, arr.length);

        File folder = new File(src);
        listAllFiles(folder.getAbsolutePath());
    }
    
    public void listAllFiles(String path)
    {
        try (Stream<Path> paths = Files.walk(Paths.get(path))) {
            paths.forEach(filePath -> {
                if (Files.isRegularFile(filePath)) {
                    try {
                        String name = filePath.getFileName().toString();
                        String ext = name.substring(name.lastIndexOf("."));
                        List<String> list = Arrays.asList(validExtensions);

                        if (list.contains(ext)) {
                            filePack(filePath.toString());
                        }
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                }
            });
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
    public void filePack(String filePath)
    {
        FileInputStream inStream = null;
        try {
            byte[] buffer = new byte[1024];
            int length = 0;
            byte[] temp = new byte[100];
            File fObj = new File(filePath);
            StringBuffer header = new StringBuffer();
            header.append(filePath).append(" ").append(fObj.length());

            // filling extra space with whitespaces
            for (int i = header.length(); i < 100; i++) {
                header.append(" ");
            }

            // for simplicity convert header into byte array
            temp = header.toString().getBytes();

            // create object og FileInputStream to read data from file
            inStream = new FileInputStream(filePath);

            // first write our header to Dest file whose object is outstream
            outStream.write(temp, 0, temp.length);

            // read all data from that directory file and write it into Dest file(Pack file)
            while ((length = inStream.read(buffer)) > 0) {
                outStream.write(buffer, 0, length);
            }

            // close file that we read in this function
            inStream.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    public static void main(String[] args) throws IOException
    {
        new FilePacker(args[0], args[1]);   
    }
}
