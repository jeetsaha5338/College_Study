//life cycle
import java.applet.*;
import java.awt.*;
public class AppletSkel extends Applet
{	
	public void init()
	{
		System.out.println("Init...");
	}
	public void start()
	{
		System.out.println("Start...");
	}	
	public void paint(Graphics g)
	{
		System.out.println("Paint...");
	}
	public void stop()
	{
		System.out.println("Stop...");
	}
	public void destroy()
	{
		System.out.println("Destroy");
	}
}
/*<applet code=AppletSkel.class width



=500 height=300> </applet>*/