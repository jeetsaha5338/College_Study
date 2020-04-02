import java.applet.*;
import java.awt.*;
import java.io.*;
import java.net.*;
/*<applet code="readFileApplet" width=400 height=500></applet>*/
public class readFileApplet extends Applet{
   String fileToRead = "test1.txt";
   StringBuffer strBuff;
   TextArea txtArea;
   Graphics g;
   public void init(){
      txtArea = new TextArea(150,100);
      txtArea.setEditable(false);
      add(txtArea, "center");
// String prHtml= "test1.txt";
    String prHtml = this.getParameter("fileToRead");
      if (prHtml != null) fileToRead = new String(prHtml);  
      readFile();
   }
   public void readFile(){
      String line;
      URL url = null;
      try{
         url = new URL(getCodeBase(), fileToRead);
      }
      catch(MalformedURLException e){}
      try{
         InputStream in = url.openStream();
         BufferedReader bf = new BufferedReader(new InputStreamReader(in));
         strBuff = new StringBuffer();
         while((line = bf.readLine()) != null){
            strBuff.append(line + "\n");
         }
         txtArea.append("File Name : " + fileToRead + "\n");
         txtArea.append(strBuff.toString());
      }
      catch(IOException e){
      e.printStackTrace();
   }
}
}