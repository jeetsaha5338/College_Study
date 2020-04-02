package org;

import java.io.DataInput;
import java.io.DataOutput;
import java.io.IOException;

import org.apache.hadoop.io.*;

public class Pair implements WritableComparable<Pair>{

	
	private Text sports = new Text(),country = new Text();
	public void set(String s,String c){
		sports.set(s);
		country.set(c);
	}
	public String getSports(){
		return sports.toString();
	}
	public String getCountry(){
		return country.toString();
	}
	
	
	@Override
	public int hashCode() {
		// TODO Auto-generated method stub
		int newhashcode = sports.hashCode()*31 + country.hashCode();
		return newhashcode;
	}
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		String s = "["+sports.toString()+","+country.toString()+"]";
		return s;
	}
	@Override
	public void readFields(DataInput datain) throws IOException {
		// TODO Auto-generated method stub
		sports.readFields(datain);
		country.readFields(datain);
	}

	@Override
	public void write(DataOutput dataout) throws IOException {
		// TODO Auto-generated method stub
		sports.write(dataout);
		country.write(dataout);
	}

	@Override
	public int compareTo(Pair o) {
		// TODO Auto-generated method stub
		int c=sports.compareTo(o.sports);
		if(c==0){
			c=country.compareTo(o.country);
		}
		return c;
	}


}
