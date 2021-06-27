import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Iterator;

import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.JTextField;
import javax.swing.SwingConstants;
import javax.swing.SwingUtilities;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;

public class DirCleanerWindow extends JFrame implements ActionListener{

	private JPanel panel;
	private JTextField textField;
	private JLabel heading, selectHeading;
	private JRadioButton recursive, nonRecursive;
	private JButton browse, submit;
	private ButtonGroup bg;
	private JFileChooser dirChooser;
	private int method;
	/**
	 * Launch the application.
	 * @throws UnsupportedLookAndFeelException 
	 * @throws IllegalAccessException 
	 * @throws InstantiationException 
	 * @throws ClassNotFoundException 
	 */
	public static void main(String[] args) throws ClassNotFoundException, InstantiationException, IllegalAccessException, UnsupportedLookAndFeelException {
		new DirCleanerWindow();
	}

	/**
	 * Create the application.
	 */
	public DirCleanerWindow() throws ClassNotFoundException, InstantiationException, IllegalAccessException, UnsupportedLookAndFeelException  {
		this.setBounds(500, 250, 650, 315);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.getContentPane().setLayout(null);
		UIManager.setLookAndFeel("javax.swing.plaf.metal.MetalLookAndFeel");
		
		panel = new JPanel();
		panel.setBounds(0, 0, 636, 278);
		panel.setBackground(UIManager.getColor("CheckBox.background"));
		panel.setLayout(null);
		getContentPane().add(panel);
		
		selectHeading = new JLabel("Select a Directory to Clean");
		selectHeading.setHorizontalAlignment(SwingConstants.CENTER);
		selectHeading.setFont(new Font("Courier New", Font.BOLD, 18));
		selectHeading.setBounds(130, 69, 383, 33);
		panel.add(selectHeading);
		
		heading = new JLabel("Directory Cleaner");
		heading.setForeground(Color.RED);
		heading.setBackground(Color.WHITE);
		heading.setHorizontalAlignment(SwingConstants.CENTER);
		heading.setFont(new Font("Courier New", Font.BOLD, 28));
		heading.setBounds(120, 10, 393, 41);
		panel.add(heading);
		
		textField = new JTextField();
		textField.setBounds(120, 112, 393, 33);
		panel.add(textField);
		textField.setColumns(10);
		
		browse = new JButton("Browse");
		browse.setFont(new Font("Courier New", Font.BOLD, 18));
		browse.setBounds(120, 223, 151, 33);
		panel.add(browse);
		
		submit = new JButton("Submit");
		submit.setFont(new Font("Courier New", Font.BOLD, 18));
		submit.setBounds(362, 223, 151, 33);
		panel.add(submit);
		
		recursive = new JRadioButton("Recursive Remove");
		recursive.setToolTipText("If Directory contains sub directory then it will remove empty and duplicate files from all subdirectory");
		recursive.setFont(new Font("Arial Black", Font.PLAIN, 12));
		recursive.setBounds(363, 166, 150, 20);
		recursive.setSelected(false);
		panel.add(recursive);
		
		nonRecursive = new JRadioButton("Non-Recursive Remove");
		nonRecursive.setToolTipText("It will remove empty and duplicate files from only specified directory");
		nonRecursive.setFont(new Font("Arial Black", Font.PLAIN, 12));
		nonRecursive.setBounds(120, 166, 190, 20);
		nonRecursive.setSelected(false);
		panel.add(nonRecursive);
		
		bg = new ButtonGroup();
		bg.add(recursive);
		bg.add(nonRecursive);
		
		this.setVisible(true);
		browse.addActionListener(this);
		submit.addActionListener(this);
		recursive.addActionListener(this);;
		nonRecursive.addActionListener(this);
	}
	public void actionPerformed(ActionEvent e) {
		if(e.getActionCommand().equals("Browse"))
		{
			dirChooser = new JFileChooser();
			dirChooser.setCurrentDirectory(new java.io.File("."));
			dirChooser.setDialogTitle("Select Directory to Clean");
			dirChooser.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);
			dirChooser.setAcceptAllFileFilterUsed(false);
			if (dirChooser.showOpenDialog(this) == JFileChooser.APPROVE_OPTION) {
				textField.setText(dirChooser.getSelectedFile().toString());
			}
		}
		if(e.getActionCommand().equals("Submit"))
		{
			if (textField.getText().isEmpty()) {
				String s = new String("Please select a directory to clean");
				JOptionPane.showMessageDialog(this, s, "Directory Cleaner", JOptionPane.INFORMATION_MESSAGE);
				try {
					SwingUtilities.invokeLater(new Runnable() {
						public void run() {
							textField.requestFocus();
						}
					});
				} catch (Exception e1) {
					JOptionPane.showMessageDialog(null, e1.getMessage());
				}
			}
			else
			{
				if(method == 0)
				{
					JOptionPane.showMessageDialog(this, "Please select a method to proceed", "Directory Cleaner", JOptionPane.INFORMATION_MESSAGE);
				}
				else
				{
					Cleaner cleaner = null;
					try {
						DirectoryCleaner directoryCleaner = new DirectoryCleaner();
						cleaner = new Cleaner(textField.getText(), method);
						cleaner.directoryCleanup();
					} catch (Exception e1) {
						JOptionPane.showMessageDialog(this, e1.getMessage(), "Directory Cleaner", JOptionPane.INFORMATION_MESSAGE);
					}
					
					DisplayDetails dd = new DisplayDetails();
					Iterator<?> itr = null;
					StringBuilder sb = new StringBuilder();
					
					sb.append("\n############################################## Directory Cleaner Log ##############################################\n");
					sb.append("Name of Directory\t\t:" + textField.getText() + "\n");
					sb.append("FullPath\t\t\t:" + DirectoryCleaner.absolutePath + "\n");
					sb.append("Total Files\t\t\t:" + Cleaner.totalFiles + "\n");
					
					// processed files
					sb.append("Total Empty Files Deleted\t\t:" + Cleaner.emptyFiles + "\n");
					if(Cleaner.emptyFiles != 0)
					{
						sb.append("--------------------\n");
						itr = Cleaner.empty.iterator();
						while(itr.hasNext())
						{
							sb.append(itr.next().toString() + "\n");
						}
						sb.append("--------------------");
					}
					
					sb.append("Total Duplicate Files Deleted\t:" + Cleaner.duplicateFiles + "\n");
					if(Cleaner.duplicateFiles != 0)
					{
						sb.append("--------------------\n");
						itr = Cleaner.duplicate.iterator();
						while(itr.hasNext())
						{
							sb.append(itr.next().toString() + "\n");
						}
						sb.append("--------------------\n");
					}
					
					// unable to process files
					sb.append("Total Empty Files Unable to Delete\t:" + Cleaner.unableEmpty.size() + "\n");
					if(Cleaner.unableEmpty.size() != 0)
					{
						sb.append("--------------------\n");
						itr = Cleaner.unableEmpty.iterator();
						while(itr.hasNext())
						{
							sb.append(itr.next().toString() + "\n");
						}
						sb.append("--------------------\n");
					}
					sb.append("Total Duplicate Files Unable to Delete\t:" + Cleaner.unableDuplicate.size() + "\n");
					if(Cleaner.unableDuplicate.size() != 0)
					{
						sb.append("--------------------\n");
						itr = Cleaner.unableDuplicate.iterator();
						while(itr.hasNext())
						{
							sb.append(itr.next().toString() + "\n");
						}
						sb.append("--------------------\n");
					}
					sb.append("Date and Time\t\t:" + DirectoryCleaner.dtf.format(DirectoryCleaner.now));  
					sb.append("\n################################################################################################################\n");
					dd.area.setText(sb.toString());
				}
			}			
		}
		if(e.getActionCommand().equals("Recursive Remove"))
			method = 2;
		if(e.getActionCommand().equals("Non-Recursive Remove"))
			method = 1;
	}
}
