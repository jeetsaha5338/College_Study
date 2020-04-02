<%@page import="com.projname.model.StudentPersonalInfo"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Student Profile</title>
</head>
<body>
	<%
		StudentPersonalInfo ob= (StudentPersonalInfo) request.getAttribute("info");
	
	
	%>
	<h1 align="CENTER" style="color: navy; font-size: 100PX; font-family: serif;">
		AOT
	</h1>
	
	<h1 align="CENTER" style="color: black; font-family: fantasy;">
		ACADEMY OF TECHNOLOGY
	</h1>
	
	<hr color="RED" width="80%" size="5">
	<BR/>
	
	<div align="center">
		<h1 style="color: navy;">STUDENT PERSONAL DETAILS</h1>
	
	<table border="1">
		<tr>
			<td align="center">NAME</td>
			<td>&nbsp;</td>
			<td align="center">EMAIL</td>
			<td>&nbsp;</td>
			<td align="center">MOBILE NO.</td>
			<td >&nbsp;</td>
			<td align="center">DATE OF BIRTH</td>
			<td>&nbsp;</td>
			<td align="center">PASSWORD</td>
			<td>&nbsp;</td>
			<td align="center">GENDER</td>
			<td>&nbsp;</td>
			<td align="center">HOBBY</td>
			<td>&nbsp;</td>
			<td align="center">COUNTRY</td>
		</tr>
		<tr>
			<td align="center"><%= ob.getStname() %></td>
			<td>&nbsp;</td>
			<td align="center"><%= ob.getStemail() %></td>
			<td>&nbsp;</td>
			<td align="center"><%= ob.getStmob() %></td>
			<td>&nbsp;</td>
			<td align="center"><%= ob.getStdob() %></td>
			<td>&nbsp;</td>
			<td align="center"><%= ob.getStpass() %></td>
			<td>&nbsp;</td>
			<td align="center"><%= ob.getGender() %></td>
			<td>&nbsp;</td>
			<td align="center"><%= ob.getHobby() %></td>
			<td>&nbsp;</td>
			<td align="center"><%= ob.getStcountry() %></td>
		</tr>
	</table>
		<br/>
		<br/>
		<img src="Image/A.png" width="200" height="100">
	</div>
</body>
</html>