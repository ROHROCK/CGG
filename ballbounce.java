import javax.swing.JPanel;
import javax.swing.JFrame;
import java.awt.Graphics;

public class ballbounce extends JPanel{

  //var for out ball
  int x =0,y=0;
  int angleX = 1, angleY =1;
  int speed  = 5;
  //method to move the ball
  private void move()
  {
    if(x+angleX < 0){
        angleX = speed;
    }else if(x + angleX > getWidth() -50 ){
      angleX = -speed;
    }else if(y + angleY < 0){
      angleY = speed;
    }else if(y+ angleY > getHeight() - 50){
      angleY = -speed;
    }
    x = x + angleX;
    y = y + angleY;
  }

  @Override
  public void paint(Graphics g){
    super.paint(g);
    g.fillOval(x,y,50,50); // our ball 50 X 50
    g.fillOval(x+50,y+50,50,50);
  }

  public static void main(String[] args) throws InterruptedException{
      JFrame frame = new JFrame("Bouncing Ball !");
      ballbounce ballbounceobj = new ballbounce();
      frame.add(ballbounceobj);
      frame.setSize(400,400);
      frame.setVisible(true);
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

      while(true){
        ballbounceobj.move();
        ballbounceobj.repaint();
        Thread.sleep(5);
      }
  }
}
