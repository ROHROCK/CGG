import javax.swing.JPanel;
import javax.swing.JFrame;
import java.awt.*;
import java.util.*;

public class ballbounce extends JPanel{

  //var for out ball
  int x =0,y=0;
  int angleX = 1, angleY =1;
  int speed  = 2;
  //method to move the ball
  // private void move()
  // {
  //   if(x+angleX < 0){
  //       g.setColor(Color.red);
  //       angleX = speed;
  //   }else if(x + angleX > getWidth() -50 ){
  //     g.setColor(Color.yellow);
  //     angleX = -speed;
  //   }else if(y + angleY < 0){
  //     angleY = speed;
  //   }else if(y + angleY > getHeight() - 50){
  //     angleY = -speed;
  //   }
  //   x = x + angleX;
  //   y = y + angleY;
  // }

  public void paint(Graphics g){

    super.paint(g);
    //Color c = new Color((int)Math.random()*255,(int)Math.random()*255,(int)Math.random()*255);
    //c = ;
    //g.setColor(Color.red);
  //  g.setColor(Color.yellow);
    g.setColor(new Color((int)(Math.random()*255),(int)(Math.random()*255),(int)(Math.random()*255)));
    g.fillOval(x,y,50,50); // our ball 50 X 50
    if(x+angleX < 0){
        angleX = speed;
    }else if(x + angleX > getWidth() -50 ){
      angleX = -speed;
    }else if(y + angleY < 0){
      angleY = speed;
    }else if(y + angleY > getHeight() - 50){
      angleY = -speed;
    }
    x = x + angleX;
    y = y + angleY;
  }

  public static void main(String[] args) throws InterruptedException{
      JFrame frame = new JFrame("Bouncing Ball !");
      ballbounce ballbounceobj = new ballbounce();
      frame.add(ballbounceobj);
      frame.setSize(400,400);
      frame.setVisible(true);
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

      while(true){
        //ballbounceobj.move();
        ballbounceobj.repaint();
        Thread.sleep(2);
      }
  }
}
