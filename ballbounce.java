import javax.swing.JPanel;
import javax.swing.JFrame;

public class ballbounce extends JPanel{
  public static void main(String[] args) {
      JFrame frame = new JFrame("Bouncing Ball !");
      frame.setSize(400,400);
      frame.setVisible(true);
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
  }
}
