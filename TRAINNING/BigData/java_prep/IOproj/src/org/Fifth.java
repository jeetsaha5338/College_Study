package org;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;

public class Fifth {

	public static void main(String[] args) throws IOException, ClassNotFoundException {
		// TODO Auto-generated method stub
		FileInputStream fin = new FileInputStream("object.dat");
		ObjectInputStream objin = new ObjectInputStream(fin);
		Object obj = objin.readObject();//Deserialisation
		Product p = (Product)obj;
		System.out.println(p.getPid());
		objin.close();
	}

}
