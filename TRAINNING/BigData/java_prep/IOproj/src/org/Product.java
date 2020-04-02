package org;

import java.io.Serializable;

public class Product implements Serializable {
	private int pid;
	private String title;
	private double price;
	public int getPid() {
		return pid;
	}
	public void setPid(int pid) {
		this.pid = pid;
	}
	public String getTitle() {
		return title;
	}
	public void setTitle(String title) {
		this.title = title;
	}
	public double getPrice() {
		return price;
	}
	public void setPrice(double price) {
		this.price = price;
	}
	public Product(int pid, String title, double price) {
		super();
		this.pid = pid;
		this.title = title;
		this.price = price;
	}
	public Product() {
		super();
	}
	

}
