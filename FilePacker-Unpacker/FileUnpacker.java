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
		try {
			new FileDecryption(src);
		} catch (Exception e) {
			throw new BadEncryptionFile("Invalid Encrypted File");
		}
		// Now file is decrypted, now perform unpacking of file

		fileUnpack(src, dest);
		FilePackerUnpacker.log.info("File Unacking completed..");

		// Move to its secure form after decryption
		new FileEncryption(src);
	}

	public void fileUnpack(String filePath, String destination) throws IOException {
		f = new File(filePath);
		if (f.exists() && f.isFile()) {
			try {
				inStream = new FileInputStream(filePath);
				int size = 0, i = 1, iLength = 0;
				byte header[] = new byte[100];
				byte magic[] = new byte[11];
				inStream.read(magic, 0, magic.length);

				// Check whether its a valid packed file or not
				String magicStr = new String(magic);
				if (!magicStr.equals("LeafyBeacon")) {
					throw new InvalidFileException("Invalid packed file format");
				}

				// create a directory in which you want to put your files
				size = inStream.read(header, 0, 100);
				String[] dirNames = new String(header).split(FilePackerUnpacker.fileSep + FilePackerUnpacker.fileSep);
				String dirName = dirNames[dirNames.length - 2];
				file = new File(destination, dirName);

				// If direcory is already there then create new directory with new name
				while (file.exists()) {
					file = new File(destination, dirName + "_" + i++);
				}

				// If directory creation is successfull then proceed
				if (file.mkdir()) {
					do {
						String str = new String(header);
						String ext = str.substring(str.lastIndexOf(FilePackerUnpacker.fileSep));
						ext = ext.substring(1);
						String words[] = ext.split("\\s");
						iLength = words.length;
						if (iLength > 2) {
							StringBuilder sb = new StringBuilder();
							for (int k = 0; k < iLength - 1; k++) {
								sb = sb.append(words[k]);
								if (k != iLength - 1)
									sb = sb.append(" ");
							}
							words[0] = sb.toString();
						}
						int fileSize = Integer.parseInt(words[iLength - 1]);
						byte[] temp = words[0].getBytes();
						String fileName = new String(temp);
						byte[] arr = new byte[fileSize];
						inStream.read(arr, 0, fileSize);
						FileOutputStream outStream = new FileOutputStream(file.getAbsoluteFile() + FilePackerUnpacker.fileSep + fileName);
						outStream.write(arr, 0, fileSize);
						outStream.close();
					} while ((size = inStream.read(header, 0, 100)) > 0);
				} else
					cannotCreateDir = true;
			} catch (InvalidFileException ie) {
				throw new InvalidFileException("Invalid packed file format");
			} finally {
				inStream.close();
			}
		} else {
			isFileThere = false;
		}
	}
}
