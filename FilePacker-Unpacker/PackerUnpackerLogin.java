import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;
import javax.swing.SwingConstants;

class PackerUnpackerLogin extends GUITemplate implements Runnable, ActionListener
{
	JButton submit, clear;
	JLabel topLabel, status, username, password;
	JPasswordField passwordField;
	JTextField textField;

	public PackerUnpackerLogin() 
	{		
		topLabel = new JLabel("File Packer and Unpacker");
		topLabel.setHorizontalAlignment(SwingConstants.CENTER);
		topLabel.setBounds(185, 23, 320, 30);
		topLabel.setFont(new Font("Courier New", Font.BOLD, 20));
		topLabel.setAlignmentX(JLabel.CENTER);
		topLabel.setForeground(Color.BLUE);
		header.add(topLabel);
		
		
		status = new JLabel("User Login");
		status.setHorizontalAlignment(SwingConstants.CENTER);
		status.setBackground(new Color(0, 50, 120));
		status.setForeground(Color.WHITE);
		status.setFont(new Font("Courier New", Font.BOLD, 20));
		status.setAlignmentX(JLabel.CENTER);
		status.setBounds(275, 30, 145, 30);
		content.add(status);
		
		username = new JLabel("USERNAME :");
		username.setHorizontalAlignment(SwingConstants.CENTER);
		username.setBounds(100, 94, 120, 30);
		username.setBackground(new Color(0, 50, 120));
		username.setForeground(Color.WHITE);
		username.setFont(new Font("Courier New", Font.BOLD, 17));
		username.setAlignmentX(JLabel.LEFT);
		content.add(username);
		
		passwordField = new JPasswordField();
		passwordField.setBounds(275, 148, 322, 30);
		content.add(passwordField);
		passwordField.setToolTipText("Enter your password here!");
		
		textField = new JTextField();
		textField.setBounds(275, 97, 322, 26);
		content.add(textField);
		textField.setColumns(15);
		textField.setToolTipText("Enter your username here!");
		
		password = new JLabel("PASSWORD :");
		password.setHorizontalAlignment(SwingConstants.CENTER);
		password.setForeground(Color.WHITE);
		password.setFont(new Font("Courier New", Font.BOLD, 17));
		password.setBounds(100, 147, 120, 30);
		content.add(password);
		
		submit = new JButton("Submit");
		submit.setFont(new Font("Courier New", Font.BOLD, 17));
		submit.setBounds(102, 238, 145, 23);
		content.add(submit);

		clear = new JButton("Clear");
		clear.setFont(new Font("Courier New", Font.BOLD, 17));
		clear.setBounds(452, 238, 145, 23);
		content.add(clear);

		this.setResizable(false);
	}

	public static void main(String[] args)
	{
		PackerUnpackerLogin frame = new PackerUnpackerLogin();
		frame.setVisible(true);
	}

	@Override
	public void run() {
		// TODO Auto-generated method stub
		
	}
}
