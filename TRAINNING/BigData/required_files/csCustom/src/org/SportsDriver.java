package org;

import java.io.IOException;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;

import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;


public class SportsDriver {

	public static void main(String[] args) throws IOException, ClassNotFoundException, InterruptedException {
		Configuration conf= new Configuration();
		Job job=Job.getInstance(conf);
		
		job.setJarByClass(SportsDriver.class);
		job.setMapperClass(SportsMapper.class);
		job.setReducerClass(SportsReducer.class);
		job.setCombinerClass(SportsReducer.class);
		
		job .setOutputKeyClass(Pair.class);
		job.setOutputValueClass(IntWritable.class);
		//job.setMapOutputKeyClass(theClass);
		//job.setMapOutputValueClass(theClass);
		
		job.setNumReduceTasks(3);
		
		
		
		FileInputFormat.addInputPath(job,new Path("sportsdir"));
		FileOutputFormat.setOutputPath(job,new Path("sportsoutput2"));
		
		
		job.waitForCompletion(true);
		
	}

}

