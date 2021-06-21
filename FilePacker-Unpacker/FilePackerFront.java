import java.awt.Choice;
import java.awt.Color;
import java.awt.Font;
import java.awt.Frame;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
import javax.swing.SwingConstants;
import javax.swing.SwingUtilities;
import javax.swing.WindowConstants;


class FilePackerFront extends GUITemplate implements ActionListener, ItemListener, KeyListener
{
	JButton submit, previous, browse;
	JLabel topLabel, status, srcDir, destFile;
	static JTextField srcDirField, destFileField;
	Choice choice;
	JFileChooser fileChooser;
	String username, state;
	public FilePackerFront(String username) throws Exception
	{
		FilePackerUnpacker.log.info("To the window of File Packer Front");
		this.username = username;
		setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
		
		topLabel = new JLabel("File Packer Portal");
		topLabel.setHorizontalAlignment(SwingConstants.CENTER);
		topLabel.setBounds(185, 23, 320, 30);
		topLabel.setFont(new Font("Courier New", Font.BOLD, 20));
		topLabel.setAlignmentX(JLabel.CENTER);
		topLabel.setForeground(Color.BLUE);
		header.add(topLabel);

		srcDir = new JLabel("*Source Directory Name:");
		srcDir.setHorizontalAlignment(SwingConstants.CENTER);
		srcDir.setBounds(21, 57, 245, 30);
		srcDir.setBackground(new Color(0, 50, 120));
		srcDir.setForeground(Color.WHITE);
		srcDir.setFont(new Font("Courier New", Font.BOLD, 17));
		srcDir.setAlignmentX(JLabel.LEFT);
		srcDir.requestFocusInWindow();
		srcDir.addKeyListener(this);
		content.add(srcDir);

		destFileField = new JTextField();
		destFileField.setBounds(275, 155, 260, 25);
		content.add(destFileField);
		destFileField.addKeyListener(this);
		destFileField.setToolTipText("Destination File Name!");

		srcDirField = new JTextField();
		srcDirField.setBounds(275, 60, 260, 25);
		content.add(srcDirField);
		srcDirField.setColumns(10);
		srcDirField.addKeyListener(this);
		srcDirField.setToolTipText("Source Directory Name!");

		destFile = new JLabel("*Destination File Name:");
		destFile.setHorizontalAlignment(SwingConstants.CENTER);
		destFile.setForeground(Color.WHITE);
		destFile.setFont(new Font("Courier New", Font.BOLD, 17));
		destFile.setBounds(21, 155, 245, 30);
		content.add(destFile);

		submit = new JButton("Submit");
		submit.setFont(new Font("Courier New", Font.BOLD, 17));
		submit.setBounds(100, 240, 145, 25);
		content.add(submit);
		
		previous = new JButton("Previous");
		previous.setFont(new Font("Courier New", Font.BOLD, 17));
		previous.setBounds(435, 240, 145, 25);
		content.add(previous);
		
		browse = new JButton("Browse");
		browse.setFont(new Font("Courier New", Font.BOLD, 17));
		browse.setBounds(275, 105, 100, 25);
		content.add(browse);
		
		choice = new Choice();
		choice.setFont(new Font("Courier New", Font.BOLD, 11));
		choice.setBounds(400, 108, 80, 25);
		choice.add("All");choice.add(".txt");choice.add(".c");
		choice.add(".cpp");choice.add(".java");choice.add(".cs");
		choice.add(".jpge");choice.add(".jpg");choice.add(".h");

		state = choice.getSelectedItem();
		content.add(choice);
		
		
		this.setBounds(fSize.width / 4, fSize.height / 5, 700, 450);
		this.setVisible(true);
		this.setResizable(false);
		
		choice.addItemListener(this);
		submit.addActionListener(this);
		previous.addActionListener(this);
		browse.addActionListener(this);
		FilePackerUnpacker.log.info("Moving from window of File Packer Front");
	}
	
	public void submitTask()
	{
		
		if(destFileField.getText().isEmpty() || srcDirField.getText().isEmpty())
    	{
    		String s = new String("Please enter all required fields");
    		JOptionPane.showMessageDialog(this, s, "File Packer-Unpacker", JOptionPane.INFORMATION_MESSAGE);
    		try
			{
				SwingUtilities.invokeLater(new Runnable()
				{
				      public void run() {
				    	  FilePackerFront.srcDirField.requestFocus();
				      }
				});
			}
			catch(Exception e)
			{
				JOptionPane.showMessageDialog(null, e.getMessage());
			}
    	}
		else
		{
			try
			{
				FilePacker packer = new FilePacker(srcDirField.getText(), state, destFileField.getText(), username);
				srcDirField.setText("");
				destFileField.setText("");
				if(packer.isDirExists == false)
				{
					String str = new String("Source directory does not exists");
		    		JOptionPane.showMessageDialog(this, str, "File Packer-Unpacker", JOptionPane.INFORMATION_MESSAGE);
		    		
					SwingUtilities.invokeLater(new Runnable()
					{
					      public void run() {
					        FilePackerFront.srcDirField.requestFocus();
					      }
					});
				}
				else
				{
					this.setVisible(false);
					FilePackerUnpackerFront nextPage = new FilePackerUnpackerFront(username);
					nextPage.setVisible(true);					
				}
			}
			catch(Exception e)
			{
				JOptionPane.showMessageDialog(null, e.getMessage());
			}
		}
	}
	
	public void itemStateChanged(ItemEvent e)
	{
		state = choice.getSelectedItem();
	}
	
	public void actionPerformed(ActionEvent ae)
	{
		if (ae.getSource() == exit)
		{
			final Frame[] frames = Frame.getFrames();
			if (frames != null)
			{
				for (final Frame f : frames)
			    {
			        f.dispose();
			    }
			}
			System.exit(0);
		}
		if (ae.getSource() == minimize)
		{
			setState(JFrame.ICONIFIED);
		}
		if(ae.getSource() == submit)
		{
			submitTask();
		}
		if(ae.getSource() == browse)
		{
			fileChooser = new JFileChooser(); 
			fileChooser.setCurrentDirectory(new java.io.File("."));
			fileChooser.setDialogTitle("Select Directory");
			fileChooser.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);
		   
			fileChooser.setAcceptAllFileFilterUsed(false);  
		    if (fileChooser.showOpenDialog(this) == JFileChooser.APPROVE_OPTION)
		    { 
		      srcDirField.setText(fileChooser.getSelectedFile().toString());
		    }
		}
		if(ae.getSource() == previous)
		{
			
			try
			{
				FilePackerUnpackerFront nextPage = new FilePackerUnpackerFront(username);
				this.setVisible(false);
				nextPage.setVisible(true);
			}
			catch(Exception e)
			{
				JOptionPane.showMessageDialog(null, e.getMessage());
			}
		}
	}
	
	public void keyPressed(KeyEvent ke)
	{
		String keyName = KeyEvent.getKeyText(ke.getKeyCode());
		if(keyName.equals("Enter"))
		{
			submitTask();
		}
	}
	
	public void keyReleased(KeyEvent ke){}
	public void keyTyped(KeyEvent e){}
	
	/*
	public static void main(String[] args)throws Exception
	{
		new FilePackerFront("Admin");
	}*/
}
