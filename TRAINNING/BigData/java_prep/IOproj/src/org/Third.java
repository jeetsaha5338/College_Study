package org;

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;

public class Third {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		FileInputStream fin = new FileInputStream("float.dat");
		DataInputStream din = new DataInputStream(fin);
		for(int i=0;i<4;i++)
		{
			double v = din.readDouble();
			System.out.println(v);
		}
		din.close();
	}
}
