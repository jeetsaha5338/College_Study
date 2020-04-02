package com.projname.p1;

public class StudentInfo {

	private String Stname;
	private int rollno;
	private double cmarks;
	private double javamarks;
	private double sum=cmarks+javamarks;
	
	public String getStname() {
		return Stname;
	}
	public void setStname(String stname) {
		Stname = stname;
	}
	public int getRollno() {
		return rollno;
	}
	public void setRollno(int rollno) {
		this.rollno = rollno;
	}
	public double getCmarks() {
		return cmarks;
	}
	public void setCmarks(double cmarks) {
		this.cmarks = cmarks;
	}
	public double getJavamarks() {
		return javamarks;
	}
	public void setJavamarks(double javamarks) {
		this.javamarks = javamarks;
	}
	public double getSum() {
		return sum;
	}
	public void setSum(double sum) {
		this.sum = sum;
	}
	
}
