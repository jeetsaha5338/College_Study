package org;


import java.io.IOException;
import java.util.Iterator;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

public class SportsReducer1 extends Reducer<Text,Text,Text,IntWritable> {

	private IntWritable outvalue=new IntWritable();
	@Override
	protected void reduce(Text key, Iterable<Text> values,Context context)
			throws IOException, InterruptedException {
		
		Iterator<Text> itr=values.iterator();
		int sum=0;
		for(Text val: values){
			sum=sum+1;
		}
		/*while(itr.hasNext()){
			sum=sum+1;
		}*/
		
		outvalue.set(sum);
		context.write(key,outvalue);
	}

	
	
	
}

