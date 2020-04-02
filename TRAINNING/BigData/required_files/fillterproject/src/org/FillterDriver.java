package org;

import java.io.IOException;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.NullWritable;
import org.apache.hadoop.io.Text;

import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;


public class FillterDriver {

	public static void main(String[] args) throws IOException, ClassNotFoundException, InterruptedException {
		Configuration conf= new Configuration();
		Job job=Job.getInstance(conf);
		
		job.setJarByClass(FillterDriver.class);
		job.setMapperClass(FillterMapper.class);
		//job.setReducerClass(SportsReducer.class);
		//job.setCombinerClass(SportsReducer.class);
		
		job .setOutputKeyClass(NullWritable.class);
		job.setOutputValueClass(Text.class);
		//job.setMapOutputKeyClass(theClass);
		//job.setMapOutputValueClass(theClass);
		
		job.setNumReduceTasks(0);
		
		FileInputFormat.addInputPath(job,new Path("custs"));
		FileOutputFormat.setOutputPath(job,new Path("filterout"));
		
		job.waitForCompletion(true);
		
	}

}

