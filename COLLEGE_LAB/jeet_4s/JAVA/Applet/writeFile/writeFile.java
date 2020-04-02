import java.applet.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.net.*;
/*<applet code="writeFile" width=400 height=500></applet>*/
public class writeFile extends Applet implements ActionListener{
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
      txtArea.setEditable(true);
     add(txtArea, "center");
   }
   public void actionPerformed(ActionEvent E)
   {
	   
	System.out.println(t.getText());
	readFile(t.getText(),"Hello World");   //txtArea.getText()
    }
     public void readFile(String S,String S1){
      try{
	FileOutputStream fout=new FileOutputStream(S);
	
		byte b[]=S1.getBytes();
		fout.write(b);  
     		fout.close();  
      }
      catch(IOException e){e.printStackTrace();}
 txtArea.append(str);	
System.out.println(str);
}
}