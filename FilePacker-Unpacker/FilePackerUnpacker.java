import javax.swing.JOptionPane;
import javax.swing.SwingUtilities;

public class FilePackerUnpacker {

	public static void main(String[] args)
	{
		try
		{
			FilePackerUnpackerLogin frame = new FilePackerUnpackerLogin();
			frame.setVisible(true);
			SwingUtilities.invokeLater(new Runnable()
			{
			      public void run() {
			        FilePackerUnpackerLogin.unameField.requestFocus();
			      }
			});
		}
		catch(Exception e)
		{
			JOptionPane.showMessageDialog(null, e.getMessage());
		}
	}
}
