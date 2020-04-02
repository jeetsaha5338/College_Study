import java.awt.*;
import java.awt.event.*;
import java.applet.*;

public class Applet1 extends Applet implements ActionListener {
  TextField inputText;
  Button    b;

  public void init() {
    inputText = new TextField( "", 15 );
    b = new Button("Send to Applet 2");
    add(inputText);
    add(b);
   b.addActionListener(this);
  }

  // JDK 1.02 style evant handling
 	 public void actionPerformed(ActionEvent E) 
	{
		Applet2 applet2=(Applet2)getAppletContext().getApplet("applet2");
		if(applet2!=null)
		applet2.append(inputText.getText());
    }

  
}