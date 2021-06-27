import java.awt.Font;
import java.awt.Frame;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.UnsupportedLookAndFeelException;

public class DisplayDetails implements ActionListener {

	private JFrame frmDetails;
	private JButton ok, previous;
	JTextArea area;
	private JScrollPane scrollPane;
	private JPanel panel;

	public DisplayDetails() {
		initialize();
	}

	private void initialize() {
		frmDetails = new JFrame();
		frmDetails.setTitle("Details");
		frmDetails.setBounds(450, 150, 800, 430);
		frmDetails.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frmDetails.getContentPane().setLayout(null);

		panel = new JPanel();
		panel.setBounds(10, 10, 766, 383);
		frmDetails.getContentPane().add(panel);
		panel.setLayout(null);

		ok = new JButton("Ok");
		ok.setFont(new Font("Courier New", Font.BOLD, 18));
		ok.setBounds(310, 330, 122, 38);
		panel.add(ok);

		scrollPane = new JScrollPane();
		scrollPane.setBounds(10, 10, 748, 310);
		panel.add(scrollPane);

		area = new JTextArea("");
		scrollPane.setViewportView(area);
		area.setFont(new Font("Arial Narrow", Font.BOLD, 14));

		frmDetails.setVisible(true);

		ok.addActionListener(this);
	}

	public void actionPerformed(ActionEvent ae) {
		if (ae.getSource() == ok) {
			final Frame[] frames = Frame.getFrames();
			if (frames != null) {
				for (final Frame f : frames) {
					f.dispose();
				}
			}
			System.exit(0);
		}
	}
}
