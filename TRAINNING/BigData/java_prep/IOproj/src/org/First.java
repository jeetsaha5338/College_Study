package org;

import java.io.FileInputStream;
import java.io.IOException;

public class First {

	public static void main(String[] args)  {
		// TODO Auto-generated method stub
		try{
			FileInputStream finput = new FileInputStream("data.txt");
			while(true)
			{
				int data=finput.read();
				char cdata=(char)data;
				if(data == -1)
						break;
				System.out.print(cdata);
				//finput.close();
			}
			finput.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		//this create a virtual pipe object
		
		
	}

}