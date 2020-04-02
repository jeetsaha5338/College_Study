import java.applet.*;
import java.awt.*;
import java.net.*;
import java.awt.event.*;
/*<applet code="tesURL" width=400 height=400></applet>*/
public class tesURL extends Applet implements ActionListener{
   public void init(){
      String link = "google";
      Button b = new Button(link);
      b.addActionListener(this);
      add(b);
   }
   public void actionPerformed(ActionEvent ae){
      Button src = (Button)ae.getSource();
      String link = "http://www."+src.getLabel()+".com";
     System.out.println("-->"+link);
      try{
         AppletContext a = getAppletContext();
         URL u = new URL(link);
         a.showDocument(u,"_self");
      }
      catch (MalformedURLException e){
         System.out.println(e.getMessage());
      }
   }
}