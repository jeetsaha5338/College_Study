<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
    <%@page import="com.projname.model.PatientInfo"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Update_Patient_Profile</title>
</head>
<body  style="background-color: silver;">
<div align="center">
<h1 align="CENTER" style="color:green; font-size: 50PX; font-family:monospace;">
		RECUPERATION CLINIC
	</h1>
<hr color="blue" width="100%" size="3">
	<BR/>
	<h1>Update Patient Profile</h1>
		<table border="1">
		
		<tr>
			<td align="center">NAME</td>
			<td>&nbsp;</td>
			<td align="center">EMAIL</td>
			<td>&nbsp;</td>
			<td align="center">MOBILE NO.</td>
			<td >&nbsp;</td>
			<td align="center">AGE</td>
			<td>&nbsp;</td>
			<td align="center">GENDER</td>
		</tr>
		
		
		<%
		String email = (String)session.getAttribute("pemail");
		String name = (String)session.getAttribute("pname");
		PatientInfo ob=(PatientInfo)request.getAttribute("info");
		%>
	<tr>
		<td align="center"> <%=name %> </td>
		<td>&nbsp;</td>
		<td align="center"> <%=ob.getPemail() %> </td>
		<td>&nbsp;</td>
		<td align="center"> <%=ob.getPmob() %> </td>
		<td>&nbsp;</td>
		<td align="center"> <%=ob.getAge() %> </td>
		<td>&nbsp;</td>
		<td align="center"> <%=ob.getGender() %> </td>
		
	</tr>
		
	</table>
	<br/><br/><br/><br/><br/>
		 <a href="PatientAfterLogin.jsp">CLICK HERE</a>&nbsp;&nbsp;&nbsp;
		 TO GO PATIENT HOME
		 </div>
</body>
</html>