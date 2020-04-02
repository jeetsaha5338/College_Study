import java.awt.*;
import java.awt.event.*;
import java.applet.*;
import java.net.*;
/*<applet code="Applet_Link" width=100 height=100></applet>*/
public class Applet_Link extends Applet implements ActionListener {
  TextField inputText;
  Button    b;

  public void init() {
    inputText = new TextField( "", 15 );
    b = new Button("Open A lInk");
    add(inputText);
    add(b);
   b.addActionListener(this);
  }

  // JDK 1.02 style evant handling
 	 public void actionPerformed(ActionEvent E) 
	{
		try{
		new URL(inputText.getText());
		}
		catch(MalformedURLException E1){}
    	}

  
}