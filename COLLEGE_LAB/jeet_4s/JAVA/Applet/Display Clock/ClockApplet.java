import java.applet.*;
import java.awt.*;
import java.util.*;

public class ClockApplet extends Applet implements Runnable
{
Thread t,t1;
public void start()
{
t = new Thread();
t.start();
}


public void run()
{
System.out.println("hello thread");
t1 = Thread.currentThread();
while(t1 == t)
{
repaint();
try
{
t1.sleep(1000);
}
catch(InterruptedException e)
{
System.out.println(e);
}
  }
}
public void paint(Graphics g)
{
Calendar cal = new GregorianCalendar();
String hour = String.valueOf(cal.get(Calendar.HOUR));
String minute = String.valueOf(cal.get(Calendar.MINUTE));
String second = String.valueOf(cal.get(Calendar.SECOND));
g.drawString(hour + ":" + minute + ":" + second, 20, 30);
}
}
/*
<applet code="ClockApplet" height="300" width="500"></applet>
*/
