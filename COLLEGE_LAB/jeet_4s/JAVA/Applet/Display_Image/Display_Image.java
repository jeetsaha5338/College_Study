/**
 * @(#)Display_Image.java
 *
 * Display_Image Applet application
 *
 * @author 
 * @version 1.00 2014/7/23
 */
/* <applet code="Display_Image" width=400 height=500 alt="Failed to Load">
<param name=image  value=1.jpg>
</applet>
*/
import java.awt.*;
import java.applet.*;
import java.net.*;

public class Display_Image extends Applet {
   private Image img;

   public void init()
   {
      img = null;
   }
   public void loadImage()
   {
      try
      { 
		
         img = getImage(getDocumentBase(),getParameter("image"));
	   showStatus(getDocumentBase().toString());
      }
      catch(Exception e) { }
   }
   public void paint(Graphics g)
   {
      if (img == null)
         loadImage();
      g.drawImage(img, 0, 0, this);
   }
}