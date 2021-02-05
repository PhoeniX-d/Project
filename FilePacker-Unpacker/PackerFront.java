import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.SwingConstants;
import java.awt.Choice;

class PackerFront extends GUITemplate implements Runnable, ActionListener {
	JButton submit, previous;
	JLabel topLabel, status, srcDir, destFile;
	JTextField srcDirField, destFileField;
	Choice choice;

	public PackerFront() {
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
		content.add(choice);
		this.setResizable(false);
	}

	public void run()
	{
		
	}
	public static void main(String[] args) {
		PackerFront frame = new PackerFront();
		frame.setVisible(true);
	}
}
