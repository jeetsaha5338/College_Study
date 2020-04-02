<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Doctor_View_Prescription</title>
</head>
<body  style="background-color: silver;">
	<div align="center">
	<h1 align="CENTER" style="color:green; font-size: 50PX; font-family:monospace;">
		RECUPERATION CLINIC
	</h1>
	
	<hr color="blue" width="100%" size="3">
	<BR/>
		<h1>VIEW PRESCRIPTION</h1>
		<form action="DocViewPrespServlet">
		<div style="color: red; font-weight: bold;">
		 	<%
		 		if(request.getAttribute("errmsg")=="invalid1")
		 			out.println("USERNAME NOT FOUND");
		 	%>
		 	
		</div>
		<table border="1">
			<tr>
			<td>PATIENT ID</td>
			<td>&nbsp;</td>
			<td> <input type="text" placeholder="Enter Patient Id" name="Pid"></td>
			</tr>
			</table>
		<BR/>
		<BR/>
		<input type="submit" value="SEARCH">
		<input type="reset" value="RESET">
		</form>
		<BR/>
		<BR/>	
		<a href="AfterDocLogin.jsp">CLICK HERE</a> &nbsp;&nbsp;&nbsp;
		TO GO DOCTOR HOME
		</div>
</body>
</html>