package org;

import java.io.DataInput;
import java.io.DataOutput;
import java.io.IOException;

import org.apache.hadoop.io.DoubleWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.io.WritableComparable;

public class SPKey implements WritableComparable<SPKey>{

	private Text symbol = new Text();
	private DoubleWritable price = new DoubleWritable();
	
	public void set(String s, double p){
		symbol.set(s);
		price.set(p);
	}
	
	public DoubleWritable getPrice(){
		return price;
	}
	
	public Text getSymbol(){
		return symbol;
	}
		
	@Override
	public int hashCode() {
		// TODO Auto-generated method stub
		int new_hc= symbol.hashCode()*31+price.hashCode();
		return new_hc;
	}

	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return "["+symbol+","+price+"]";
	}

	@Override
	public void readFields(DataInput datain) throws IOException {
		// TODO Auto-generated method stub
		symbol.readFields(datain);
		price.readFields(datain);
	}

	@Override
	public void write(DataOutput dataout) throws IOException {
		// TODO Auto-generated method stub
		symbol.write(dataout);
		price.write(dataout);
		
	}

	@Override
	public int compareTo(SPKey o) {
		// TODO Auto-generated method stub
		int c = symbol.compareTo(o.symbol);
		if(c==0)
		{
			c = price.compareTo(o.price);
		}
		return c;
	}
	

}
