package org;

import java.io.IOException;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.*;
import org.apache.hadoop.mapreduce.Mapper;

public class SportsMapper1 extends Mapper<LongWritable, Text, Text, Text>{

	private Text outkey=new Text();
	private Text outvalue=new Text();
	@Override
	protected void map(LongWritable key, Text value,Context context)
			throws IOException, InterruptedException {
		String line=value.toString();//p1,india,cricket
		String fields[]=line.split(",");
		//StringTokenizer st=new StringTokenizer(line);
		/*for(int i=0;i<fields.length;i++)
			String word=st.nextToken();
			outkey.set(word);
			context.write(outkey,outval);
		}*/
		String sports=fields[2].toLowerCase();//==>cricket
		String country=fields[1].toLowerCase();//==>india
		//cricket,india
		outkey.set(sports);
		outvalue.set(country);
		context.write(outkey, outvalue);
	}

	
}