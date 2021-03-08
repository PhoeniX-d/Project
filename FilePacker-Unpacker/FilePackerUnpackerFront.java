import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.FileOutputStream;
import java.io.ObjectOutputStream;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.SwingConstants;

class FilePackerUnpackerFront extends GUITemplate implements ActionListener
{
	JButton pack, unpack;
	JLabel task, welcome;
	String username;
	
	FilePackerUnpackerFront(String username) 
	{
		this.username = username;
		welcome = new JLabel("Welcome : " + username);
		welcome.setBounds(200, 25, 350, 25);
		welcome.setFont(new Font("Courier New", Font.BOLD, 20));
		welcome.setForeground(new  Color(34, 177, 76));
		header.add(welcome);		

		task = new JLabel("Select Task");
		task.setBounds(235, 52, 203, 30);
		content.add(task);
		task.setHorizontalAlignment(SwingConstants.CENTER);
		task.setForeground(Color.WHITE);
		task.setFont(new Font("Courier New", Font.BOLD, 20));
		task.setAlignmentX(JLabel.CENTER);
		
		pack = new JButton("Pack Files");
		pack.setHorizontalAlignment(SwingConstants.CENTER);
		pack.setFont(new Font("Courier New", Font.BOLD, 20));
		pack.setBounds(140, 140, 155, 50);
		pack.setAlignmentX(JButton.CENTER);
		content.add(pack);
		
		unpack = new JButton("Unpack File");
		unpack.setHorizontalAlignment(SwingConstants.CENTER);
		unpack.setFont(new Font("Courier New", Font.BOLD, 20));
		unpack.setBounds(380, 140, 180, 50);
		unpack.setAlignmentX(JButton.CENTER);
		content.add(unpack);
		
		pack.addActionListener(this);
		unpack.addActionListener(this);
		
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
		if(ae.getSource() == pack)
		{
			this.setVisible(false);
			try
			{
				FilePackerFront packer = new FilePackerFront(username);
			}
			catch(Exception e)
			{
				JOptionPane.showMessageDialog(null, e.getMessage());
			}
		}
		
		if(ae.getSource() == unpack)
		{
			this.setVisible(false);
			FileUnpackerFront unpacker = new FileUnpackerFront(username);
		}
	}
}
