
package org;

import java.io.IOException;
import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.NullWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

public class SUMapper extends Mapper<LongWritable, Text, NullWritable, Text>{

	private NullWritable outkey=NullWritable.get();
	private Text outvalue=new Text();
	@Override
	
	protected void map(LongWritable key, Text value,Context context)
			throws IOException, InterruptedException {
		
		String line=value.toString();
		String[] f = line.split("'");
		String s1="";
		for(int i=0;i<f.length;i++)
		{
			if(i%2!=0)
			{
				f[i]=f[i].replaceAll(",", "");
			}
		}
		if(f.length==1)
			s1 += f[0];
		for(int i=0;i<f.length-1;i++)
		{
			s1 += f[i];
		}
		line = s1;
		
		
		
		
		
		
		
		
		String[] values = line.split(",");
		String writableString = ""; 
		ArrayList<String> al = new ArrayList<String>();
		for (int i=0;i<values.length;i++) {
			if (values[i]==null || values[i].length()==0) {
				al.add("null");
			}
			else {
				al.add(values[i]);
			}
		}
		for (String s : al){ 
			writableString += s + ",";
		}
		line = writableString.substring(0,writableString.length() - 1);
		String field[]=line.split(",");
		if(field.length<9)
		{
			int k= 9-(field.length);
			for(int i=0;i<k;i++)
			{
				if(i==k-1)
					line += ",0";
				else
					line += ",NULL";
			}
		}
		String[] fields=line.split(",");
		fields[1]=fields[1].replaceAll("\\.", "/");
		String[] s3=fields[1].split("/");
		fields[1]=s3[s3.length-1];
		String n = fields[0]+","+fields[1]+" , "+fields[2]+" , "+fields[3]+" , "
		+fields[5]+" , "+fields[6]+","+fields[7];
		if(fields[8].equalsIgnoreCase("0"))
			n += " , "+"0";
		else
			n += " , "+"1";
		outvalue.set(n);
		context.write(outkey,outvalue);
	}
}
