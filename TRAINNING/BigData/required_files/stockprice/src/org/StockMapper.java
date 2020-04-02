package org;

import java.io.IOException;
import java.util.StringTokenizer;

import org.apache.hadoop.io.DoubleWritable;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

public class StockMapper extends Mapper<LongWritable, Text, Text,DoubleWritable>{

	private Text outkey=new Text();
	private DoubleWritable outvalue=new DoubleWritable(1);
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
		double price = Double.parseDouble(fields[2]);//price
		String stock = fields[0].toLowerCase();//tcs
		outkey.set(stock);
		outvalue.set(price);
		context.write(outkey, outvalue);
	}

	
}
