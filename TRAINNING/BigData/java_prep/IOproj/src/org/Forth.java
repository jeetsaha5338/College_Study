package org;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;

public class Forth {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		FileOutputStream fout = new FileOutputStream("object.dat");
		ObjectOutputStream objout = new ObjectOutputStream(fout);
		Product p = new Product(10,"pendrive",400.5);
		
		objout.writeObject(p);
		objout.close();
	}

}
