package org;

import java.io.IOException;
import java.util.StringTokenizer;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

public class SportsMapper extends Mapper<LongWritable, Text, Pair, IntWritable>{

	private Pair outkey=new Pair();
	private IntWritable outvalue=new IntWritable(1);
	
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
		String sports=fields[2].toLowerCase();
		String country= fields[1].toLowerCase();//==>cricket
		outkey.set(sports,country);
		context.write(outkey, outvalue);
	}

	
}
