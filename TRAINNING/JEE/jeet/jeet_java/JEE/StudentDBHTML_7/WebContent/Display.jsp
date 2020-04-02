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
		StudentPersonalInfo sobj=(StudentPersonalInfo) request.getAttribute("info");
	
	
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
		<h1 style="color: navy;">STUDENT REGISTRATION DETAILS</h1>
		<div style="color: red; font-weight: bold;">
		 	<%
		 		if(request.getAttribute("success")=="RECORD INSERTED")
		 			out.println("YOU HAVE BEEN SUCCESSFULLY REGISTERED");
		 	%>
		 	
		</div>
	
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
			<td align="center"><%= sobj.getStname() %></td>
			<td>&nbsp;</td>
			<td align="center"><%= sobj.getStemail() %></td>
			<td>&nbsp;</td>
			<td align="center"><%= sobj.getStmob() %></td>
			<td>&nbsp;</td>
			<td align="center"><%= sobj.getStdob() %></td>
			<td>&nbsp;</td>
			<td align="center"><%= sobj.getStpass() %></td>
			<td>&nbsp;</td>
			<td align="center"><%= sobj.getGender() %></td>
			<td>&nbsp;</td>
			<td align="center"><%= sobj.getHobby() %></td>
			<td>&nbsp;</td>
			<td align="center"><%= sobj.getStcountry() %></td>
		</tr>
	</table>
		<BR/>
		<BR/>
		WANT TO LOGIN TO STUDENT PORTAL ?
		<br/>
		<a href="login.jsp">GO TO LOGIN PAGE</a>
		
		<br/>
		<br/>
		<img src="Image/A.png" width="200" height="100">
	</div>
</body>
</html>