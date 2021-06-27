import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.security.MessageDigest;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;

import javax.swing.JOptionPane;

class DirectoryCleaner
{
	static String absolutePath = null;
	static int choice;
	static String dirName = null;
	static long start = 0, end = 0;
	static DateTimeFormatter dtf = null;
	static LocalDateTime now = null;
	DirectoryCleaner() throws Exception
	{
		dtf = DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss");  
		now = LocalDateTime.now();
	}
}

class Cleaner
{
	File dir = null;
	static int duplicateFiles = 0;
	static int emptyFiles = 0;
	static int totalFiles = 0;
	static int choice = 0;
	
	File filesList[] = null;
	File[] fArray = null;
	// To keep track of empty files
	static LinkedList<String> empty = new LinkedList<String>();
	
	// To keep track of empty files that are unable to remove
	static LinkedList<String> unableEmpty = new LinkedList<String>();
	
	// To keep track of duplicate files that
	static LinkedList<String> duplicate = new LinkedList<String>();
	
	// To keep track of duplicate files that are unable to remove
	static LinkedList<String> unableDuplicate = new LinkedList<String>();
	
	// To keep track of Method 2(Remove every) types of files
	static LinkedList<String> globalListOfFiles = new LinkedList<String>();
	
	// To keep track of Method 1(Remove only upper dir contents) types of files
	static LinkedList<String> localListofFiles = null;
	
	Cleaner(String dirName, int ch)
	{
		dir = new File(dirName);
		DirectoryCleaner.absolutePath = dir.getAbsolutePath();
		
		// check for directory exists or not if yes is it directory?
		if(dir.exists() == false && dir.isDirectory() == false)
		{
			String s = "Invalid Directory or Directory does not exists anymore";
			JOptionPane.showMessageDialog(null, s, "Directory Cleaner", JOptionPane.INFORMATION_MESSAGE);
			System.exit(0);
		}
		filesList = dir.listFiles();
		Arrays.sort(filesList, Collections.reverseOrder());
		choice = ch;
	}
	
	public void directoryCleanup()throws Exception
	{
		MessageDigest digest = MessageDigest.getInstance("SHA-256");
		if(digest == null)
		{
			JOptionPane.showMessageDialog(null, "Unable to get SHA-256 instance", "Directory Cleaner", JOptionPane.INFORMATION_MESSAGE);
			System.exit(0);
		}
		recursiveTravel(digest, filesList, 0);	
	}
	
	public void recursiveTravel(MessageDigest digest, File[] filesArr, int depth) throws IOException
	{
		byte bArr[] = new byte[1024];
		int bytesRead = 0;
		FileInputStream fis = null;
		if(choice == 1)
		{
			localListofFiles = new LinkedList<String>();
		}
		totalFiles = totalFiles + filesArr.length;
		for(File file : filesArr)
		{
			if(file.isDirectory() == false)
			{
				try
				{
					fis = new FileInputStream(file);
				}
				catch(Exception e)
				{
					JOptionPane.showMessageDialog(null, "System error while processing file " + file.getName(), "Directory Cleaner", JOptionPane.INFORMATION_MESSAGE);
				}
				
				if(file.length() == 0)
				{
					if(!file.delete())
					{
						unableEmpty.add(file.getName());
					}
					else
					{
						empty.add(file.getName());
						emptyFiles++;
					}				
				}
				else if(file.length() != 0)
				{
					while((bytesRead = fis.read(bArr)) != -1)
					{
						digest.update(bArr, 0, bytesRead);
					}
				}
				// Here you have to close fis object otherwise file won't get deleted 
				fis.close();
				byte bytes[] = digest.digest();				
				StringBuffer sb = new StringBuffer();
				
				for(int i = 0; i < bytes.length; i++)
				{
					// add each byte from decimal to hexadecimal StringBuffer
					sb.append(Integer.toString((bytes[i] & 0xff) + 0x100, 16).substring(1));
				}
				
				if(choice == 1 && localListofFiles.contains(sb.toString()))
				{
					if(!file.delete())
					{
						unableDuplicate.add(file.getName());
					}
					else
					{
						duplicate.add(file.getName());
						duplicateFiles++;				
					}
				}
				else if(choice == 2 && globalListOfFiles.contains(sb.toString()))
				{
					if(!file.delete())
					{
						unableDuplicate.add(file.getName());
					}
					else
					{
						duplicate.add(file.getName());
						duplicateFiles++;				
					}
				}
					
				else
				{
					if(choice == 1)
					{
						localListofFiles.add(sb.toString());
					}
					else if(choice == 2)
					{
						globalListOfFiles.add(sb.toString());
					}
				}
			}
			else
			{
				fArray = file.listFiles();
				//Arrays.sort(fArray, Collections.reverseOrder());
				recursiveTravel(digest, fArray, depth + 1);
				if(file.listFiles().length == 0)
				{
					file.delete();
				}
			}
		}
	}
}
