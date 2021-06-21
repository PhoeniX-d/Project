import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class FileUnpacker {
	File f, file;
	FileInputStream inStream;
	boolean isFileThere = true, cannotCreateDir = false;

	public FileUnpacker(String src, String dest) throws Exception {
		FilePackerUnpacker.log.info("File Unpacking started..");
		if (dest.isEmpty())
			dest = ".";
		
		// Perform Decryption of file here...
		new FileDecryption(src);
		// Now file is decrypted, now perform unpacking of file
		
		fileUnpack(src, dest);
		FilePackerUnpacker.log.info("File Unacking completed..");
	}

	public void fileUnpack(String filePath, String destination) throws IOException {
		f = new File(filePath);
		if (f.exists() && f.isFile()) {
			try {
				inStream = new FileInputStream(filePath);
				int size = 0, i = 1;
				byte header[] = new byte[100];
				byte magic[] = new byte[11];
				inStream.read(magic, 0, magic.length);
				String magicStr = new String(magic);
				if (!magicStr.equals("LeafyBeacon")) {
					throw new InvalidFileException("Invalid packed file format");
				}

				// create a directory in which you want to put your files
				size = inStream.read(header, 0, 100);
				String[] dirNames = new String(header).split("\\\\");
				String dirName = dirNames[dirNames.length - 2];
				file = new File(destination, dirName);
				while (file.exists()) {
					file = new File(destination, dirName + "_" + i++);
				}
				if (file.mkdir()) {
					do {
						String str = new String(header);
						String ext = str.substring(str.lastIndexOf("\\"));
						ext = ext.substring(1);
						String words[] = ext.split("\\s");
						int fileSize = Integer.parseInt(words[1]);
						byte[] temp = words[0].getBytes();
						String fileName = new String(temp);
						byte[] arr = new byte[fileSize];
						inStream.read(arr, 0, fileSize);
						FileOutputStream outStream = new FileOutputStream(file.getAbsoluteFile() + "\\" + fileName);
						outStream.write(arr, 0, fileSize);
						outStream.close();
					} while ((size = inStream.read(header, 0, 100)) > 0);
				} else
					cannotCreateDir = true;
			} catch (InvalidFileException ie) {
				throw new InvalidFileException("Invalid packed file format");
			} finally {
				inStream.close();
				Runtime.getRuntime().gc();
			}
		} else {
			isFileThere = false;
		}
	}
	
	 public static void main(String[] args)throws Exception { 
		 new FileUnpacker("cryp", "C:\\Users\\Dell\\Desktop\\FinalProjects"); }
	 
}
