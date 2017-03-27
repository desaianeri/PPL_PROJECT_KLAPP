import javax.swing.*;
import java.awt.*;

public class pro extends Canvas
{
	JButton b1, b2, b3, b4;

	public void CreateToolbox(JToolBar tb)
	{

		/*	Creating Buttons	*/
		b1 = new JButton("ALPHABETS");
		b2 = new JButton("NUMBERS");
		b3 = new JButton("SHAPES");
		b4 = new JButton("STORIES");
		
		/*	Adding Buttons to toolbar	*/
		tb.add(b1);
		tb.add(b2);
		tb.add(b3);
		tb.add(b4);
	}

	public void paint(Graphics g)
	{
		Toolkit t = Toolkit.getDefaultToolkit();
		Image i = t.getImage("ppl_3.jpg");
		g.drawImage(i, 0, 0, this);
	}

        public static void main(String[] args)
        {
                pro p = new pro();

                /*      creating instance of JFrame     */
                JFrame f = new JFrame("Kids Learning App");

                /*      Creating toolbar        */
                JToolBar tb = new JToolBar("FUN!!");

                /*      set full screen */
                f.setExtendedState(JFrame.MAXIMIZED_BOTH);

                f.setLayout(null);      //      toolbar not visible
                f.setLayout(new BorderLayout());        // toolbar is visible

                p.CreateToolbox(tb);
                f.add(tb, BorderLayout.NORTH);

		f.add(p);	//	image is visible

		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

                f.setVisible(true);

        }
}

