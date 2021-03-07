import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.security.MessageDigest;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Iterator;
import java.util.LinkedList;

class DirectoryCleaner
{
	static String absolutePath = null;
	static String dirName = null;
	static long start = 0, end = 0;
	static DateTimeFormatter dtf = null;
	static LocalDateTime now = null;
	public static void main(String[] args) throws Exception
	{
		dtf = DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss");  
		now = LocalDateTime.now();
		System.out.println("Enter the directory name");
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));		
		dirName = br.readLine();
		Cleaner cleaner = new Cleaner(dirName);
		cleaner.directoryCleanup();
		cleaner.details();
	}
}

class Cleaner
{
	File dir = null;
	int duplicateFiles = 0;
	int emptyFiles = 0;
	int totalFiles = 0;
	
	File filesList[] = null;
	LinkedList<String> empty = new LinkedList<String>();
	LinkedList<String> unableEmpty = new LinkedList<String>();
	LinkedList<String> duplicate = new LinkedList<String>();
	LinkedList<String> unableDuplicate = new LinkedList<String>();
	LinkedList<String> l = new LinkedList<String>();
	
	Cleaner(String dirName)
	{
		dir = new File(dirName);
		DirectoryCleaner.absolutePath = dir.getAbsolutePath();
		// check for directory exists or not if yes is it directory?
		if(dir.exists() == false && dir.isDirectory() == false)
		{
			System.out.println("Invalid Directory or Directory does not exists");
			System.exit(0);
		}
		filesList = dir.listFiles();
	}
	
	public void directoryCleanup()
	{
		try
		{
			MessageDigest digest = MessageDigest.getInstance("SHA-256");
			if(digest == null)
			{
				System.out.println("Unable to get the SHA-256 instance");
				System.exit(0);
			}
			recursiveTravel(digest, filesList, 0);
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}		
	}
	
	public void recursiveTravel(MessageDigest digest, File[] filesArr, int depth) throws IOException
	{
		byte bArr[] = new byte[1024];
		int bytesRead = 0;
		FileInputStream fis = null;
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
					System.out.println("System error while processing file " + file.getName());
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
				
				if(l.contains(sb.toString()))
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
					l.add(sb.toString());
				}
			}
			else
			{
				recursiveTravel(digest, file.listFiles(), depth + 1);
				if(file.listFiles().length == 0)
				{
					file.delete();
				}
			}
		}
	}
	
	
	public void details()
	{
		Iterator itr = null;		   
		System.out.println("\n##################### Directory Cleaner Log #####################\n");
		System.out.println("Name of Directory\t\t\t:" + DirectoryCleaner.dirName);
		System.out.println("FullPath\t\t\t\t:" + DirectoryCleaner.absolutePath);
		System.out.println("Total Files\t\t\t\t:" + totalFiles);
		
		// processed files
		System.out.println("Total Empty Files Deleted\t\t:" + emptyFiles);
		if(emptyFiles != 0)
		{
			System.out.println("--------------------");
			itr = empty.iterator();
			while(itr.hasNext())
			{
				System.out.println(itr.next().toString());
			}
			System.out.println("--------------------");
		}
		
		System.out.println("Total Duplicate Files Deleted\t\t:" + duplicateFiles);
		if(duplicateFiles != 0)
		{
			System.out.println("--------------------");
			itr = duplicate.iterator();
			while(itr.hasNext())
			{
				System.out.println(itr.next().toString());
			}
			System.out.println("--------------------");
		}
		
		// unable to process files
		System.out.println("Total Empty Files Unable to Delete\t:" + unableEmpty.size());
		if(unableEmpty.size() != 0)
		{
			System.out.println("--------------------");
			itr = unableEmpty.iterator();
			while(itr.hasNext())
			{
				System.out.println(itr.next().toString());
			}
			System.out.println("--------------------");
		}
		System.out.println("Total Duplicate Files Unable to Delete\t:" + unableDuplicate.size());
		if(unableDuplicate.size() != 0)
		{
			System.out.println("--------------------");
			itr = unableDuplicate.iterator();
			while(itr.hasNext())
			{
				System.out.println(itr.next().toString());
			}
			System.out.println("--------------------");
		}
		System.out.println("Date and Time\t\t\t\t:" + DirectoryCleaner.dtf.format(DirectoryCleaner.now));  
		System.out.println("\n#################################################################");
	}
}
