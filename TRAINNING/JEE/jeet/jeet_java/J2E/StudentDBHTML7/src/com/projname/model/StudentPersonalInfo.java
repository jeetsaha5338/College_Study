package com.projname.model;

public class StudentPersonalInfo 
{
	private String Stname;
	private String Stemail;
	private String Stmob;
	private String Stdob;
	private String Stpass;
	private String gender;
	private String hobby1;
	private String hobby2;
	private String hobby;
	private String Stcountry;
	//StudentPersonalInfo ob =new StudentPersonalInfo();
	public String getStname() {
		return Stname;
	}
	public void setStname(String stname) {
		Stname = stname;
	}
	public String getStemail() {
		return Stemail;
	}
	public void setStemail(String stemail) {
		Stemail = stemail;
	}
	public String getStmob() {
		return Stmob;
	}
	public void setStmob(String stmob) {
		Stmob = stmob;
	}
	public String getStdob() {
		return Stdob;
	}
	public void setStdob(String stdob) {
		Stdob = stdob;
	}
	public String getStpass() {
		return Stpass;
	}
	public void setStpass(String stpass) {
		Stpass = stpass;
	}
	
	public String getGender() {
		return gender;
	}
	public void setGender(String gender) {
		this.gender = gender;
	}
	
	public String getStcountry() {
		return Stcountry;
	}
	public void setStcountry(String stcountry) {
		Stcountry = stcountry;
	}
	public String getHobby1() {
		return hobby1;
	}
	public void setHobby1(String hobby1) {
		this.hobby1 = hobby1;
	}
	public String getHobby2() {
		return hobby2;
	}
	public void setHobby2(String hobby2) {
		this.hobby2 = hobby2;
	}
	public String getHobby() {
		return hobby;
	}
	public void setHobby(String hobby) {
		this.hobby = hobby;
	}
	
}
