package org;

import java.io.IOException;
import java.util.StringTokenizer;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.NullWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

public class FillterMapper extends Mapper<LongWritable, Text, NullWritable, Text>{

	private NullWritable outkey=NullWritable.get();//create nullwriteable object
	private Text outvalue=new Text();
	
	@Override
	protected void map(LongWritable key, Text value,Context context)
			throws IOException, InterruptedException {
		String line=value.toString();//p1,india,cricket
		String fields[]=line.split(",");
		
		if (fields != null && fields.length==5){
			if(fields[4].equalsIgnoreCase("pilot")){
				context.write(outkey, value);
			}
		}
		
	}

	
}
