import javax.swing.JOptionPane;
import javax.swing.SwingUtilities;

public class FilePackerUnpacker {

	public static void main(String[] args)
	{
		try
		{
			PackerUnpackerLogin frame = new PackerUnpackerLogin();
			frame.setVisible(true);
			SwingUtilities.invokeLater(new Runnable()
			{
			      public void run() {
			        PackerUnpackerLogin.unameField.requestFocus();
			      }
			});
		}
		catch(Exception e)
		{
			JOptionPane.showMessageDialog(null, e.getMessage());
		}
	}
}
