<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
    <%@page import="com.projname.model.DoctorInfo"%>
<%@page import="java.util.ArrayList"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Update_doc_pro</title>
</head>
<body style="background-color: silver;">
	<h1 align="CENTER" style="color:green; font-size: 50PX; font-family:monospace;">
		RECUPERATION CLINIC
	</h1>
	
<hr color="blue" width="100%" size="3">
<br/>
	
	<div align="center">
		<h1 style="color: navy;">AVAILABLE DOCTORS</h1>
	<table border="1">
		
		<tr>
			<td align="center">NAME</td>
			<td>&nbsp;</td>
			<td align="center">EMAIL</td>
			<td>&nbsp;</td>
			<td align="center">MOBILE NO.</td>
			<td >&nbsp;</td>
			<td align="center">QUALIFICATION</td>
			<td>&nbsp;</td>
			<td align="center">SPECIALISATION</td>
			<td>&nbsp;</td>
			<td align="center">EXPERIENCE</td>
			<td>&nbsp;</td>
			<td align="center">REGISTRATION NO.</td>
			<td>&nbsp;</td>
			<td align="center">FESS</td>
			<td>&nbsp;</td>
			<td align="center">TIME</td>
			<td>&nbsp;</td>
			<td align="center">NO.OF PATIENTS</td>
			
		</tr>
		
		
		<%
		String email = (String)session.getAttribute("demail");
		String name = (String)session.getAttribute("dname");
		String reg = (String)session.getAttribute("dreg");
		DoctorInfo ob=(DoctorInfo)request.getAttribute("info");
		%>
	<tr>
		<td align="center"> <%=name %> </td>
		<td>&nbsp;</td>
		<td align="center"> <%=ob.getDemail() %> </td>
		<td>&nbsp;</td>
		<td align="center"> <%=ob.getDmob() %> </td>
		<td>&nbsp;</td>
		<td align="center"> <%=ob.getQual() %> </td>
		<td>&nbsp;</td>
		<td align="center"> <%=ob.getDspec() %> </td>
		<td>&nbsp;</td>
		<td align="center"> <%=ob.getExp() %> </td>
		<td>&nbsp;</td>
		<td align="center"> <%=reg %> </td>
		<td>&nbsp;</td>
		<td align="center"> <%=ob.getDfees() %> </td>
		<td>&nbsp;</td>
		<td align="center"> <%=ob.getDtime() %> </td>
		<td>&nbsp;</td>
		<td align="center"> <%=ob.getDpno() %> </td>
	</tr>
		
	</table>
	<br/>	<br/>	<br/>
		
		<a href="AfterDocLogin.jsp">CLICK HERE</a>&nbsp;&nbsp;&nbsp;
		TO GO DOCTOR HOME
	
</body>
</html>