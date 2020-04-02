package org;

import java.io.DataOutputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class Secord {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		double values[]= {2.345,45.56,78.9,4.5};
		FileOutputStream fout = new FileOutputStream("float.dat");
		DataOutputStream dout = new DataOutputStream(fout);
		for(double val:values)
		{
			//val is getting 2.345
			//fout.write(40000);
			dout.writeDouble(val);
			//required to break a double into byte sequence
		}
		dout.close();
	}

}
