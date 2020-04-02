import java.applet.*;
import java.awt.*;
import java.io.*;
import java.net.*;
/*<applet code="readFile" width=400 height=500></applet>*/
public class readFile extends Applet{
   String fileToRead = "test1.txt";
   String str="";
   TextArea txtArea;
 int i;
   public void init(){
      txtArea = new TextArea(150,100);
      txtArea.setEditable(false);
      add(txtArea, "center");
      readFile();
   }
   public void readFile(){
      try{
	FileInputStream fin=new FileInputStream("test1.txt");
	do
	{
		i=fin.read();
		if(i!=-1)
			str=str+(char)i;
	}while(i!=-1);
			
      }
      catch(IOException e){e.printStackTrace();}
 txtArea.append(str);	
}
}