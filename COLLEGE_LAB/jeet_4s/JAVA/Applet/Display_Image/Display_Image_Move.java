/**
 * @(#)Display_Image.java
 *
 * Display_Image Applet application
 *
 * @author 
 * @version 1.00 2014/7/23
 */
/* <applet code="Display_Image_Move" width=800 height=500 alt="Failed to Load">

</applet>
*/
import java.awt.*;
import java.applet.*;
import java.net.*;

public class Display_Image_Move extends Applet implements Runnable {
   private Image img;
   Thread t;
   int i=0;
   public void init()
   {
      img = null;
   }
   public void loadImage()
   {
      try
      { 
		
         img = getImage(getDocumentBase(),"1.jpg");
	   showStatus(getDocumentBase().toString());
      }
      catch(Exception e) { }
     t=new Thread(this);
    t.start();
   }
 public void run()
{
	while(true)
	{
		try{
		repaint();
		Thread.sleep(10);
		}
		catch(Exception E){}
	}
}
   public void paint(Graphics g)
   {
      if (img == null)
         loadImage();
      g.drawImage(img, i++, 0, this); 
    if(i==Integer.parseInt(getParameter("width")))i=0;
   }
}