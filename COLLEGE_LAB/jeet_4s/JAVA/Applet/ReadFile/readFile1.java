import java.applet.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.net.*;
/*<applet code="readFile1" width=400 height=500></applet>*/
public class readFile1 extends Applet implements ActionListener{
   String fileToRead = "test1.txt";
   String str="";
   TextArea txtArea;
   TextField t;
   Button b=new Button();
   
   String path="";
    int i;
   public void init(){
      t=new TextField(20);
     add(t);
     add(b);
      b.addActionListener(this);
     txtArea = new TextArea(70,100);
     txtArea.setEditable(false);
     add(txtArea, "center");

    
   }
   public void actionPerformed(ActionEvent E)
   {
	   
	System.out.println(t.getText());
	readFile(t.getText());
    }
     public void readFile(String S){
      try{
	FileInputStream fin=new FileInputStream(S);
	do
	{
		i=fin.read();
		if(i!=-1)
			str=str+(char)i;
	}while(i!=-1);
			
      }
      catch(IOException e){e.printStackTrace();}
 txtArea.append(str);	
System.out.println(str);
}
}