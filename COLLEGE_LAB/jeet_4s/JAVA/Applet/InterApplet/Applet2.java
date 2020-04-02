import java.awt.*;

public class Applet2 extends java.applet.Applet {
  TextField textBox;

  public void init() {
    setLayout(new FlowLayout());
    textBox = new TextField( 20 );
    add( textBox );
  }

  public void append( String msg ) {
    textBox.setText( msg );
  
  }
}