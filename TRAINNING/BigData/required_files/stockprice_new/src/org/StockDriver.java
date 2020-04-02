package org;

import java.io.IOException;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.DoubleWritable;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;

import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;


public class StockDriver {

	public static void main(String[] args) throws IOException, ClassNotFoundException, InterruptedException {
		Configuration conf= new Configuration();
		Job job=Job.getInstance(conf);
		
		job.setJarByClass(StockDriver.class);
		job.setMapperClass(StockMapper.class);
		job.setReducerClass(StockReducer.class);
		job.setPartitionerClass(StockPartitioner.class);
		job.setGroupingComparatorClass(StockGrpCmp.class);
		
		job.setMapOutputKeyClass(SPKey.class);
		job.setMapOutputValueClass(DoubleWritable.class);
		job .setOutputKeyClass(Text.class);
		job.setOutputValueClass(Text.class);
		
		job.setNumReduceTasks(1);
		
		
		
		FileInputFormat.addInputPath(job,new Path("stocksdir"));
		FileOutputFormat.setOutputPath(job,new Path("stocksoutput_new"));
		
		
		job.waitForCompletion(true);
		
	}

}

