import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.HashMap;
import java.util.Set;

import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPasswordField;
import javax.swing.JTextField;
import javax.swing.SwingConstants;
import javax.swing.WindowConstants;

class RegisterUser extends GUITemplate implements  ActionListener, KeyListener
{
	JButton create, previous;
	JLabel topLabel, status, name, pwd, confirmPwd;
	JTextField nameField;
	JPasswordField pwdField, confirmpwdField;
	String userValue, pwdValue, confirmpwdValue;
	JCheckBox show1, show2;

	RegisterUser() throws Exception
	{
		setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
		
		topLabel = new JLabel("Register New User");
		topLabel.setHorizontalAlignment(SwingConstants.CENTER);
		topLabel.setBounds(185, 23, 320, 30);
		topLabel.setFont(new Font("Courier New", Font.BOLD, 20));
		topLabel.setAlignmentX(JLabel.CENTER);
		topLabel.setForeground(Color.BLUE);
		header.add(topLabel);

		name = new JLabel("*New Username:");
		name.setHorizontalAlignment(SwingConstants.CENTER);
		name.setBounds(40, 45, 260, 30);
		name.setBackground(new Color(0, 50, 120));
		name.setForeground(Color.WHITE);
		name.setFont(new Font("Courier New", Font.BOLD, 17));
		name.setAlignmentX(JLabel.LEFT);
		name.requestFocusInWindow();
		content.add(name);
		
		pwd = new JLabel("*Enter new password:");
		pwd.setHorizontalAlignment(SwingConstants.CENTER);
		pwd.setForeground(Color.WHITE);
		pwd.setFont(new Font("Courier New", Font.BOLD, 17));
		pwd.setBounds(40, 100, 260, 30);
		pwd.addKeyListener(this);
		content.add(pwd);
		
		confirmPwd = new JLabel("*Confirm new password:");
		confirmPwd.setHorizontalAlignment(SwingConstants.CENTER);
		confirmPwd.setForeground(Color.WHITE);
		confirmPwd.setFont(new Font("Courier New", Font.BOLD, 17));
		confirmPwd.setBounds(40, 155, 260, 30);
		confirmPwd.addKeyListener(this);
		content.add(confirmPwd);

		nameField = new JTextField();
		nameField.setBounds(300, 45, 260, 25);
		content.add(nameField);
		nameField.setColumns(10);
		nameField.setToolTipText("Enter a new username");
		
		pwdField = new JPasswordField();
		pwdField.setBounds(300, 100, 260, 25);
		content.add(pwdField);
		pwdField.setEchoChar((char)0);
		pwdField.setToolTipText("New user password, it must of length >= 8 characters ");
		
		show1 = new JCheckBox("Show", true);
		show1.setBounds(580, 100, 65, 25);
		show1.setToolTipText("See password");
		content.add(show1);

		confirmpwdField = new JPasswordField();
		confirmpwdField.setBounds(300, 155, 260, 25);
		content.add(confirmpwdField);
		confirmpwdField.setEchoChar((char)0);
		confirmpwdField.setToolTipText("Confirm Entered password");
		
		show2 = new JCheckBox("Show", true);
		show2.setBounds(580, 155, 65, 25);
		show2.setToolTipText("See password");
		content.add(show2);
		
		create = new JButton("Create");
		create.setFont(new Font("Courier New", Font.BOLD, 17));
		create.setBounds(125, 225, 145, 25);
		content.add(create);
		
		previous = new JButton("Previous");
		previous.setFont(new Font("Courier New", Font.BOLD, 17));
		previous.setBounds(400, 225, 145, 25);
		content.add(previous);
		
		this.setBounds(fSize.width / 4, fSize.height / 5, 700, 450);
		this.setVisible(true);
		this.setResizable(false);
		
		create.addActionListener(this);
		previous.addActionListener(this);
		show1.addActionListener(this);
		show2.addActionListener(this);
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
	
	public void actionPerformed(ActionEvent ae)
	{
		userValue = nameField.getText();
		pwdValue = new String(pwdField.getPassword());
		confirmpwdValue = new String(confirmpwdField.getPassword());
	
		if(show1.getModel().isSelected())
		{
			pwdField.setEchoChar((char)0);
		}
		else
		{
			pwdField.setEchoChar('*');
		}
		if(show2.getModel().isSelected())
		{
			confirmpwdField.setEchoChar((char)0);
		}
		else
		{
			confirmpwdField.setEchoChar('*');
		}
		
		if (ae.getSource() == exit)
		{
			this.setVisible(false);
			System.exit(0);
		}
		if (ae.getSource() == minimize)
		{
			setState(JFrame.ICONIFIED);
		}
		if(ae.getSource() == create)
		{
			createTask();
		}
		
		if(ae.getSource() == previous)
		{
			this.setVisible(false);
			try
			{
				FilePackerUnpackerLogin nextPage = new FilePackerUnpackerLogin();
			}
			catch(Exception e)
			{
				JOptionPane.showMessageDialog(null, e.getMessage());
			}
		}
	}
	
	public void createTask()
	{	
		if(isValid(userValue, pwdValue) == false)
		{
			nameField.setText("");
			pwdField.setText("");
			confirmpwdField.setText("");
			JOptionPane.showMessageDialog(this,"Short Username or Password", "File Packer-Unpacker", JOptionPane.ERROR_MESSAGE);
		}
		else
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
			
			Set<String> keys= creds.keySet();
			if(keys.contains(userValue))
			{
				JOptionPane.showMessageDialog(null, "Sorry!! username already exists, try different username", "File Packer-Unpacker2", JOptionPane.INFORMATION_MESSAGE);
				nameField.setText("");
				pwdField.setText("");
				confirmpwdField.setText("");
			}
			else if(pwdValue.equals(confirmpwdValue) == false)
			{
				JOptionPane.showMessageDialog(null, "Password didn\'t confirmed, try again", "File Packer-Unpacker", JOptionPane.INFORMATION_MESSAGE);
				confirmpwdField.setText("");
			}
			else
			{
				creds.put(userValue, pwdValue);
				JOptionPane.showMessageDialog(null, "New User Registered Successfully!", "File Packer-Unpacker", JOptionPane.INFORMATION_MESSAGE);
				nameField.setText("");
				pwdField.setText("");
				confirmpwdField.setText("");
				this.setVisible(false);
				try
				{
					serializeFos = new FileOutputStream("credentials.txt");
					mapOutput = new ObjectOutputStream(serializeFos);
					mapOutput.writeObject(creds);
					serializeFos.close();
					mapOutput.close();
					FilePackerUnpackerLogin nextPage = new FilePackerUnpackerLogin();
				}
				catch(Exception e)
				{
					JOptionPane.showMessageDialog(null, e.getMessage());
				}
			}
		}		
	}
	
	public void keyPressed(KeyEvent ke)
	{
		String keyName = KeyEvent.getKeyText(ke.getKeyCode());
		if(keyName.equals("Enter"))
		{
			createTask();
		}
	}

	@Override
	public void keyTyped(KeyEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void keyReleased(KeyEvent e) {
		// TODO Auto-generated method stub
		
	}
}
