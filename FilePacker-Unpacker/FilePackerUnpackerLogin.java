import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.io.File;
import java.io.FileInputStream;
import java.io.ObjectInputStream;
import java.util.HashMap;

import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPasswordField;
import javax.swing.JTextField;
import javax.swing.SwingConstants;

class FilePackerUnpackerLogin extends GUITemplate implements ActionListener, KeyListener, Runnable
{
	Thread t = new Thread();	
	JButton submit, clear, register;
	JLabel topLabel, status, username, password, warning;
	JCheckBox show;
	JPasswordField passwordField;
	static JTextField unameField; 
	static String userValue, pwdValue;
	static int attempt = 5;
	
	public FilePackerUnpackerLogin()
	{
		t.start();
		getCredentials();
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
		passwordField.addKeyListener(this);
		
		show = new JCheckBox("Show");
		show.setBounds(275, 193, 65, 25);
		show.setToolTipText("See password");
		content.add(show);		
		
		unameField = new JTextField();
		unameField.setBounds(275, 97, 322, 26);
		content.add(unameField);
		unameField.setColumns(15);

		unameField.setToolTipText("Enter your username here!");
		
		password = new JLabel("PASSWORD :");
		password.setHorizontalAlignment(SwingConstants.CENTER);
		password.setForeground(Color.WHITE);
		password.setFont(new Font("Courier New", Font.BOLD, 17));
		password.setBounds(100, 147, 120, 30);
		content.add(password);
		
		warning = new JLabel();
		warning.setBounds(265, 180, 300, 30);
		warning.setHorizontalAlignment(SwingConstants.CENTER);
		warning.setForeground(Color.RED);
		warning.setFont(new Font("Courier New", Font.BOLD, 17));
		content.add(warning);
		
		submit = new JButton("Submit");
		submit.setFont(new Font("Courier New", Font.BOLD, 17));
		submit.setBounds(100, 238, 145, 23);
		content.add(submit);
		
		clear = new JButton("Clear");
		clear.setFont(new Font("Courier New", Font.BOLD, 17));
		clear.setBounds(275, 238, 145, 23);
		content.add(clear);
		
		register = new JButton("Register");
		register.setFont(new Font("Courier New", Font.BOLD, 17));
		register.setBounds(450, 238, 145, 23);
		content.add(register);
		
		pack();
		validate();
		//clockHome();
		this.setBounds(fSize.width / 4, fSize.height / 5, 700, 450);
		this.setVisible(true);
		this.setResizable(false);
		submit.addActionListener(this);
		clear.addActionListener(this);
		register.addActionListener(this);
		show.addActionListener(this);
	}
	
	public boolean isValid(String username, String password)
	{
		if(username.length() < 8 || password.length() < 8)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	
	public void submitTask()
	{	
		String credentials = creds.get(userValue);
		if(isValid(userValue, pwdValue) == false)
		{
			unameField.setText("");
			passwordField.setText("");
			JOptionPane.showMessageDialog(this,"Short Username or Password", "File Packer-Unpacker", JOptionPane.ERROR_MESSAGE);
		}
		else if(credentials == null)
		{
			JOptionPane.showMessageDialog(this,"User does not exists, create a new user login", "File Packer-Unpacker", JOptionPane.INFORMATION_MESSAGE);
			unameField.setText("");
			passwordField.setText("");
		}
		else
		{
			if(pwdValue.equals(credentials))
			{
				FilePackerUnpackerFront nextPage = new FilePackerUnpackerFront(userValue);
				this.setVisible(false);
				nextPage.pack();
				nextPage.setVisible(true);
				nextPage.setBounds(fSize.width / 4, fSize.height / 5, 700, 450);
			}
			else
		    {
		        attempt--;		        
		        if(attempt == 0)
		        {
		        	JOptionPane.showMessageDialog(this, "Number of attempts finished","File Packer-Unpacker", JOptionPane.ERROR_MESSAGE);
		        	this.dispose();
		        	System.exit(0);
		        }
		        if(attempt < 3)
		        {
		        	JOptionPane.showMessageDialog(this,"Incorrect username or password, \n     Attempt Remaining " + attempt,"Error", JOptionPane.ERROR_MESSAGE);
		        }
		        else
		        {
		        	JOptionPane.showMessageDialog(this,"Incorrect username or password","Error", JOptionPane.ERROR_MESSAGE);
		        }
		    }
		}
	}

	public void actionPerformed(ActionEvent ae)
	{	
		userValue = unameField.getText();
		pwdValue = new String(passwordField.getPassword());
			
		if(ae.getSource() == minimize)
		{
			this.setState(JFrame.ICONIFIED);
		}
		if(ae.getSource() == exit)
		{
			this.setVisible(false);
			System.exit(0);
		}
		
		if(show.getModel().isSelected())
		{
			passwordField.setEchoChar((char)0);
		}
		else
		{
			passwordField.setEchoChar('*');
		}
		
		if(ae.getSource() == clear)
		{
			unameField.setText("");
			passwordField.setText("");
		}
		
		if(ae.getSource() == submit)
		{			
			submitTask();
		}	
		
		if(ae.getSource() == register)
		{
			this.setVisible(false);
			try
			{
				RegisterUser reg = new RegisterUser();
			}
			catch(Exception e)
			{
				JOptionPane.showMessageDialog(this, e,"Error", JOptionPane.ERROR_MESSAGE);
			}
		}
	}

	public void keyPressed(KeyEvent ke)
	{
		userValue = unameField.getText();
		pwdValue = new String(passwordField.getPassword());
		
		String keyName = KeyEvent.getKeyText(ke.getKeyCode());
		if(keyName.equals("Enter"))
		{
			submitTask();
		}
	}

	public void keyReleased(KeyEvent ke){}
	public void keyTyped(KeyEvent e) {}
	
	public void run()
	{
		for(;;)
		{
			 if(unameField.getText().length() < 8)
			 {
				 submit.setEnabled(false);
			 }
		}
	}
	
	public void getCredentials()
	{
		serializeFile = new File("credentials.txt");
		if(serializeFile.exists() && serializeFile.isFile())
		{
			try
			{
				serializeFis = new FileInputStream("credentials.txt");
				mapInput = new ObjectInputStream(serializeFis);
				creds = (HashMap<String, String>)mapInput.readObject();
				serializeFis.close();
				mapInput.close();
			}
			catch(Exception e)
			{
				
			}
		}
	}
	public static void main(String[] args)
	{
		new FilePackerUnpackerLogin();
	}
}