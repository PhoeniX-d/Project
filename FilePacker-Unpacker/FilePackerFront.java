import java.awt.Choice;
import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
import javax.swing.SwingConstants;
import javax.swing.WindowConstants;

class FilePackerFront extends GUITemplate implements ActionListener, ItemListener, KeyListener
{
	JButton submit, previous;
	JLabel topLabel, status, srcDir, destFile;
	JTextField srcDirField, destFileField;
	Choice choice;
	String username, state;
	public FilePackerFront(String username)
	{
		this.username = username;
		setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
		
		topLabel = new JLabel("File Packer Portal");
		topLabel.setHorizontalAlignment(SwingConstants.CENTER);
		topLabel.setBounds(185, 23, 320, 30);
		topLabel.setFont(new Font("Courier New", Font.BOLD, 20));
		topLabel.setAlignmentX(JLabel.CENTER);
		topLabel.setForeground(Color.BLUE);
		header.add(topLabel);

		srcDir = new JLabel("Source Directory Name:");
		srcDir.setHorizontalAlignment(SwingConstants.CENTER);
		srcDir.setBounds(21, 57, 245, 30);
		srcDir.setBackground(new Color(0, 50, 120));
		srcDir.setForeground(Color.WHITE);
		srcDir.setFont(new Font("Courier New", Font.BOLD, 17));
		srcDir.setAlignmentX(JLabel.LEFT);
		srcDir.requestFocusInWindow();
		content.add(srcDir);

		destFileField = new JTextField();
		destFileField.setBounds(276, 131, 260, 25);
		content.add(destFileField);
		destFileField.setToolTipText("Destination File Name!");

		srcDirField = new JTextField();
		srcDirField.setBounds(276, 60, 260, 25);
		content.add(srcDirField);
		srcDirField.setColumns(10);
		srcDirField.setToolTipText("Source Directory Name!");

		destFile = new JLabel("Destination File Name:");
		destFile.setHorizontalAlignment(SwingConstants.CENTER);
		destFile.setForeground(Color.WHITE);
		destFile.setFont(new Font("Courier New", Font.BOLD, 17));
		destFile.setBounds(21, 130, 245, 30);
		destFile.addKeyListener(this);
		content.add(destFile);

		submit = new JButton("Submit");
		submit.setFont(new Font("Courier New", Font.BOLD, 17));
		submit.setBounds(75, 240, 145, 25);
		content.add(submit);
		
		previous = new JButton("Previous");
		previous.setFont(new Font("Courier New", Font.BOLD, 17));
		previous.setBounds(325, 240, 145, 25);
		content.add(previous);

		choice = new Choice();
		choice.setFont(new Font("Courier New", Font.BOLD, 11));
		choice.setBounds(582, 57, 60, 20);
		choice.add("All");choice.add(".txt");choice.add(".c");
		choice.add(".cpp");choice.add(".java");choice.add(".cs");
		state = choice.getSelectedItem();
		content.add(choice);
		
		
		this.setBounds(380, 180, 700, 450);
		this.setVisible(true);
		this.setResizable(false);
		
		choice.addItemListener(this);
		submit.addActionListener(this);
		previous.addActionListener(this);
	}
	
	public void submitTask()
	{
		this.setVisible(false);
		try
		{
			FilePacker packer = new FilePacker(srcDirField.getText(), state, destFileField.getText());
			this.setEnabled(false);
			PackerUnpackerFront nextPage = new PackerUnpackerFront(username);
		}
		catch(Exception e)
		{
			JOptionPane.showMessageDialog(null, e.getMessage());
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
			this.setVisible(false);
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
		
		if(ae.getSource() == previous)
		{
			this.setVisible(false);
			this.setEnabled(false);
			try
			{
				PackerUnpackerFront nextPage = new PackerUnpackerFront(username);
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
}
