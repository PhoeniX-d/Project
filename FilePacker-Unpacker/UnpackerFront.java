import java.awt.Choice;
import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.SwingConstants;

class UnpackerFront extends GUITemplate implements Runnable, ActionListener
{
	JButton extract, previous;
	JLabel topLabel, sourceFile;
	JTextField sourceFileField;
	Choice choice;

	public UnpackerFront()
	{
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
		sourceFile.setToolTipText("Name of file to be unpacked");
		content.add(sourceFile);

		sourceFileField = new JTextField();
		sourceFileField.setBounds(327, 61, 285, 25);
		content.add(sourceFileField);
		sourceFileField.setColumns(10);
		sourceFileField.setToolTipText("Source Directory Name!");

		extract = new JButton("Extract Here");
		extract.setFont(new Font("Courier New", Font.BOLD, 17));
		extract.setBounds(105, 165, 175, 25);
		content.add(extract);

		previous = new JButton("Previous");
		previous.setFont(new Font("Courier New", Font.BOLD, 17));
		previous.setBounds(385, 165, 175, 25);
		content.add(previous);
		this.setResizable(false);
	}

	public void run()
	{

	}
	public static void main(String[] args) {
		UnpackerFront frame = new UnpackerFront();
		frame.setVisible(true);
	}
}
