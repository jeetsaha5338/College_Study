//life cycle
import java.applet.*;
import java.awt.*;
public class AppletSkel extends Applet
{	
	String str=" ";
	public void init()
	{
		setForeground(Color.blue);
		setBackground(Color.red);
		str+="Init...";
		System.out.println("Init...");
	}
	public void start()
	{
		str+="Start...";
		System.out.println("Start...");
	}	
	public void paint(Graphics g)
	{
		str+="Paint...";
		g.drawString(str,150,150);
		System.out.println("Paint...");
	}
	public void stop()
	{
		str+="Stop...";
		System.out.println("Stop...");
	}
	public void destroy()
	{
		System.out.println("Destroy");
	}
}
/*<applet code=AppletSkel.class width=500 height=300> </applet>*/