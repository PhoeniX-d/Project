import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.SimpleDateFormat;
import java.util.Date;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.SwingConstants;
import javax.swing.Timer;

class ClockLabel extends JLabel implements ActionListener {
	String type;
	SimpleDateFormat sdf;

	public ClockLabel(String type) {
		this.type = type;
		setForeground(Color.RED);

		switch (type) {
		case "date":
			sdf = new SimpleDateFormat("MMMM dd yyyy");
			setFont(new Font("Consolas", Font.BOLD, 17));
			setHorizontalAlignment(SwingConstants.CENTER);
			break;
		case "time":
			sdf = new SimpleDateFormat("hh:mm:ss a");
			setFont(new Font("Consolas", Font.BOLD, 17));
			setHorizontalAlignment(SwingConstants.CENTER);
			break;
		case "day":
			sdf = new SimpleDateFormat("EEEE");
			setFont(new Font("Consolas", Font.BOLD, 17));
			setHorizontalAlignment(SwingConstants.RIGHT);
			break;
		default:
			sdf = new SimpleDateFormat();
			break;
		}

		Timer t = new Timer(1000, this);
		t.start();
	}

	public void actionPerformed(ActionEvent ae) {
		Date d = new Date();
		setText(sdf.format(d));
	}
}

class GUITemplate extends JFrame implements ActionListener
{
	JPanel header;
	JPanel content;
	JPanel top;
	ClockLabel dayLabel;
	ClockLabel timeLabel;
	ClockLabel dateLabel;
	JButton minimize, exit;

	public GUITemplate() 
	{
		setBounds(380, 180, 700, 450);
		getContentPane().setLayout(null);		
		setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);
		//GridBagLayout grid = new GridBagLayout();
		//getContentPane().setLayout(grid);

		top = new JPanel();
		top.setBounds(0, 0, 684, 25);
		top.setBackground(Color.LIGHT_GRAY);
		top.setLayout(null);
		getContentPane().add(top);
		/*getContentPane().add(top, new GridBagConstraints(0, 0, 1, 1, 1, 5, GridBagConstraints.BASELINE,
				GridBagConstraints.BOTH, new Insets(0, 0, 0, 0), 0, 0));*/

		header = new JPanel();
		header.setBounds(0, 25, 684, 80);
		header.setLayout(null);
		header.setBackground(Color.white);
		getContentPane().add(header);
		/*getContentPane().add(header, new GridBagConstraints(0, 1, 1, 1, 1, 20, GridBagConstraints.BASELINE,
				GridBagConstraints.BOTH, new Insets(0, 0, 0, 0), 0, 0));*/

		content = new JPanel();
		content.setBounds(0, 105, 685, 305);
		content.setLayout(null);
		content.setBackground(new Color(0, 50, 120));
		getContentPane().add(content);
		/*getContentPane().add(content, new GridBagConstraints(0, 1, 1, 1, 1, 20, GridBagConstraints.BASELINE,
				GridBagConstraints.BOTH, new Insets(0, 0, 0, 0), 0, 0));*/
		
		setTitle("File Packer Unpacker");
		clock();
		closeAndMin();
	}

	void closeAndMin() {
		minimize = new JButton("-");
		minimize.setBounds(2, 0, 45, 25);
		minimize.setHorizontalAlignment(SwingConstants.CENTER);
		minimize.setBackground(Color.LIGHT_GRAY);
		minimize.setFont(new Font("Consolas", Font.BOLD, 15));
		minimize.setHorizontalTextPosition(0);

		exit = new JButton("X");
		exit.setBounds(47, 0, 45, 25);
		exit.setHorizontalAlignment(SwingConstants.CENTER);
		exit.setFont(new Font("Consolas", Font.BOLD, 15));
		exit.setBackground(Color.LIGHT_GRAY);
		exit.setHorizontalTextPosition(0);

		top.add(minimize);
		top.add(exit);
		
		minimize.addActionListener(this);
		exit.addActionListener(this);
		this.setResizable(false);
		
	}

	public void actionPerformed(ActionEvent ae) {
		if (ae.getSource() == exit)
		{
			this.setVisible(false);
			System.exit(0);
		}
		if (ae.getSource() == minimize)
		{
			setState(JFrame.ICONIFIED);
		}
	}

	void clock()
	{
		dateLabel = new ClockLabel("date");
		timeLabel = new ClockLabel("time");
		dayLabel = new ClockLabel("day");
		dayLabel.setHorizontalAlignment(SwingConstants.CENTER);
		
		dateLabel.setForeground(Color.RED);
		dateLabel.setAlignmentX(CENTER_ALIGNMENT);
		dateLabel.setAlignmentY(CENTER_ALIGNMENT);
		
		timeLabel.setForeground(Color.RED);
		timeLabel.setAlignmentX(CENTER_ALIGNMENT);
		timeLabel.setAlignmentY(CENTER_ALIGNMENT);
		
		dayLabel.setForeground(Color.RED);
		dayLabel.setAlignmentX(CENTER_ALIGNMENT);
		dayLabel.setAlignmentY(CENTER_ALIGNMENT);
		
		dateLabel.setFont(new Font("Consolas", Font.BOLD, 17));
		timeLabel.setFont(new Font("Consolas", Font.BOLD, 17));
		dayLabel.setFont(new Font("Consolas", Font.BOLD, 17));
		
		dayLabel.setBounds(270, 0, 130, 25);
		dateLabel.setBounds(395, 0, 150, 25);
		timeLabel.setBounds(545, 0, 140, 25);
		
		top.add(dayLabel);
		top.add(dateLabel);
		top.add(timeLabel);
	}

	void clockHome()
	{
		dateLabel = new ClockLabel("date");
		timeLabel = new ClockLabel("time");
		dayLabel = new ClockLabel("day");
		dayLabel.setHorizontalAlignment(SwingConstants.CENTER);

		dateLabel.setForeground(Color.RED);
		dateLabel.setAlignmentX(CENTER_ALIGNMENT);
		dateLabel.setAlignmentY(CENTER_ALIGNMENT);

		timeLabel.setForeground(Color.RED);
		timeLabel.setAlignmentX(CENTER_ALIGNMENT);
		timeLabel.setAlignmentY(CENTER_ALIGNMENT);

		dayLabel.setForeground(Color.RED);
		dayLabel.setAlignmentX(CENTER_ALIGNMENT);
		dayLabel.setAlignmentY(CENTER_ALIGNMENT);

		dateLabel.setFont(new Font("Consolas", Font.BOLD, 17));
		timeLabel.setFont(new Font("Consolas", Font.BOLD, 17));
		dayLabel.setFont(new Font("Consolas", Font.BOLD, 17));

		dayLabel.setBounds(270, 0, 130, 25);
		dateLabel.setBounds(395, 0, 150, 25);
		timeLabel.setBounds(545, 0, 140, 25);

		top.add(dayLabel);
		top.add(dateLabel);
		top.add(timeLabel);
	}
	
	public static void main(String[] args) {
		GUITemplate frame = new GUITemplate();
		frame.setVisible(true);
	}
}
