package org;

import java.io.IOException;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;

import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;


public class SportsDriver1 {

	public static void main(String[] args) throws IOException, ClassNotFoundException, InterruptedException {
		Configuration conf= new Configuration();
		Job job=Job.getInstance(conf);
		
		job.setJarByClass(SportsDriver1.class);
		job.setMapperClass(SportsMapper1.class);
		job.setReducerClass(SportsReducer1.class);
		//job.setCombinerClass(SportsReducer.class);
		job.setPartitionerClass(SportsPartitioner.class);
		
		job.setMapOutputKeyClass(Text.class);
		job.setOutputValueClass(Text.class);
		job .setOutputKeyClass(Text.class);
		job.setOutputValueClass(IntWritable.class);
		//job.setMapOutputKeyClass(theClass);
		//job.setMapOutputValueClass(theClass);
		
		job.setNumReduceTasks(3);
		
		
		
		FileInputFormat.addInputPath(job,new Path("sportsdir"));
		FileOutputFormat.setOutputPath(job,new Path("sportsoutput1"));
		
		
		job.waitForCompletion(true);
		
	}

}
