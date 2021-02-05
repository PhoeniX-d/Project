import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.SwingConstants;

class PackerUnpackerFront extends GUITemplate implements Runnable, ActionListener
{
	JButton pack, unpack;
	JLabel label, status, welcome;

	
	PackerUnpackerFront()
	{
		welcome = new JLabel("Welcome : ");
		welcome.setBounds(170, 25, 350, 25);
		welcome.setFont(new Font("Courier New", Font.BOLD, 20));
		header.add(welcome);
		
		pack = new JButton("Pack");
		pack.setHorizontalAlignment(SwingConstants.CENTER);
		pack.setFont(new Font("Courier New", Font.BOLD, 20));
		pack.setBounds(150, 140, 145, 50);
		pack.setAlignmentX(JLabel.CENTER);
		content.add(pack);
		
		unpack = new JButton("Unpack");
		unpack.setHorizontalAlignment(SwingConstants.CENTER);
		unpack.setFont(new Font("Courier New", Font.BOLD, 20));
		unpack.setBounds(400, 140, 145, 50);
		unpack.setAlignmentX(JLabel.CENTER);
		content.add(unpack);
		
		status = new JLabel();
		status.setAlignmentX(JLabel.CENTER);
		status.setBounds(150, 200, 342, 22);
		content.add(status);
		
		label = new JLabel("Select Task");
		label.setBounds(235, 52, 203, 30);
		content.add(label);
		label.setHorizontalAlignment(SwingConstants.CENTER);
		label.setForeground(Color.WHITE);
		label.setFont(new Font("Courier New", Font.BOLD, 20));
		label.setAlignmentX(JLabel.CENTER);
		
		pack.addActionListener(this);
		unpack.addActionListener(this);
		this.setResizable(false);
		setVisible(true);
	}
	
	public void actionPerformed(ActionEvent ae)
	{
		if (ae.getSource() == pack) {
			status.setText("You Have Selected Pack Activity");
		} else if (ae.getSource() == unpack) {
			status.setText("You Have Selected Unpack Activity");
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
		status.setFont(new Font("Courier New", Font.BOLD, 13));
		status.setForeground(Color.GREEN);
	}
	
	public void run()
	{
		
	}
	public static void main(String[] args)
	{
		PackerUnpackerFront t = new PackerUnpackerFront();
	}
}
