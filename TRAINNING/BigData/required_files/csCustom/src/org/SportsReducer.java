package org;


import java.io.IOException;
import java.util.Iterator;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

public class SportsReducer extends Reducer<Pair,IntWritable,Pair,IntWritable> {

	private IntWritable outvalue=new IntWritable();
	@Override
	protected void reduce(Pair key, Iterable<IntWritable> values,Context context)
			throws IOException, InterruptedException {
		
		int sum=0;
		for(IntWritable val: values){
			sum=sum+val.get();
		}
		
		outvalue.set(sum);
		context.write(key,outvalue);
	}

	
	
	
}


