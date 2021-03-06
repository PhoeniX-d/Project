import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
import javax.swing.SwingConstants;
import javax.swing.WindowConstants;

class InvalidFileException extends RuntimeException
{
	public InvalidFileException(String str)
	{
		super(str);
	}
}
class FileUnpackerFront extends GUITemplate implements ActionListener
{
	JButton extract, previous;
	JLabel topLabel, sourceFile;
	JTextField sourceFileField;
	String username;

	public FileUnpackerFront(String username) 
	{
		this.username = username;
		setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
		
		topLabel = new JLabel("File Unpacker Portal");
		topLabel.setHorizontalAlignment(SwingConstants.CENTER);
		topLabel.setBounds(185, 23, 320, 30);
		topLabel.setFont(new Font("Courier New", Font.BOLD, 20));
		topLabel.setAlignmentX(JLabel.CENTER);
		topLabel.setForeground(Color.BLUE);
		header.add(topLabel);

		sourceFile = new JLabel("Packed File Name:");
		sourceFile.setHorizontalAlignment(SwingConstants.CENTER);
		sourceFile.setBounds(50, 57, 258, 30);
		sourceFile.setBackground(new Color(0, 50, 120));
		sourceFile.setForeground(Color.WHITE);
		sourceFile.setFont(new Font("Courier New", Font.BOLD, 17));
		sourceFile.setAlignmentX(JLabel.LEFT);
		sourceFile.requestFocusInWindow();
		content.add(sourceFile);

		sourceFileField = new JTextField();
		sourceFileField.setBounds(327, 61, 285, 25);
		content.add(sourceFileField);
		sourceFileField.setColumns(30);
		sourceFileField.setToolTipText("Name of file to be unpacked");
		sourceFileField.setToolTipText("Source Directory Name!");

		extract = new JButton("Extract Here");
		extract.setFont(new Font("Courier New", Font.BOLD, 17));
		extract.setBounds(105, 165, 175, 25);
		extract.addActionListener(this);
		content.add(extract);

		previous = new JButton("Previous");
		previous.setFont(new Font("Courier New", Font.BOLD, 17));
		previous.setBounds(385, 165, 175, 25);
		previous.addActionListener(this);
		content.add(previous);

		this.setBounds(fSize.width / 4, fSize.height / 5, 700, 450);
		this.setVisible(true);
		this.setResizable(false);
	}
	
	public void actionPerformed(ActionEvent ae)
	{
		if (ae.getSource() == exit)
		{
			this.dispose();
			System.exit(0);
		}
		if (ae.getSource() == minimize)
		{
			setState(JFrame.ICONIFIED);
		}
		if(ae.getSource() == extract)
		{
			if(sourceFileField.getText().isEmpty())
	    	{
	    		String s = new String("Please enter all required fields");
	    		JOptionPane.showMessageDialog(this, s, "File Packer-Unpacker", JOptionPane.INFORMATION_MESSAGE);
	    		this.setVisible(false);
	    		FileUnpackerFront nextPage = new FileUnpackerFront(username);
	    	}
			else
			{
				this.setVisible(false);
				try
				{
					FileUnpacker unpacker = new FileUnpacker(sourceFileField.getText());
					if(unpacker.isFileThere == false)
					{
						JOptionPane.showMessageDialog(this, "Packed File Does not exists", "Error", JOptionPane.ERROR_MESSAGE);
						FileUnpackerFront unpack = new FileUnpackerFront(username);
					}
					else
					{
						FilePackerUnpackerFront nextPage = new FilePackerUnpackerFront(username);
					}
					//this.setVisible(false);
				}
				catch(InvalidFileException ie)
				{
					this.dispose();
					JOptionPane.showMessageDialog(this, "Invalid Packed File", "Error", JOptionPane.ERROR_MESSAGE);
					FilePackerUnpackerFront nextPage = new FilePackerUnpackerFront(username);
				}
				catch(Exception e)
				{
					JOptionPane.showMessageDialog(null, e.getMessage());
					FilePackerUnpackerFront nextPage = new FilePackerUnpackerFront(username);
				}
			}
		}
		
		if(ae.getSource() == previous)
		{
			this.dispose();
			try
			{
				FilePackerUnpackerFront nextPage = new FilePackerUnpackerFront(username);
			}
			catch(Exception e)
			{
				JOptionPane.showMessageDialog(null, e.getMessage());
			}
		}
	}
}
