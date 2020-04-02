<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Patient_Login</title>
</head>
<body style="background-color: silver;">
	
	<h1 align="CENTER" style="color: blue; font-size: 50PX; font-family: monospace;">
		RECUPERATION CLINIC
	</h1>
	
	<hr color="green" width="100%" size="3">
	
	<BR/>
	<div align="center">
		<h1>PATIENT LOGIN PAGE</h1>
		<img src="Patient-Portal-Banner.jpg" width="400" height="200">
		<form action="LoginServletNew">
		<div style="color: red; font-weight: bold;">
		 	<%
		 		if(request.getAttribute("errmsg")=="1")
		 		{
		 			out.println("WRONG PASSWORD");
		 		}
		 		if(request.getAttribute("errmsg")=="2")
		 		{
		 			out.println("INVALID USER ID");
		 		}
		 	%>
		 	
		</div>
		<table border="1">
			<tr>
			<td>USERNAME</td>
			<td>&nbsp;</td>
			<td> <input type="text" placeholder="Enter E-mail" name="Pemail"></td>
			</tr>
	
			<tr>
			<td>PASSWORD</td>
			<td>&nbsp;</td>
			<td> <input type="password" placeholder="Enter Password" name="Ppass"></td>
			</tr>
	
		</table>
		<BR/>
		<BR/>
		<input type="submit" value="LOGIN">
		<input type="reset" value="RESET">
		</form>
		
		<BR/>
		<BR/>
		YET NOT REGISTERED ?
		<br/>
		<a href="RegPage.jsp">GO TO REGISTRATION PAGE</a>
		<br/>
		<br/>
		<a href="Home.jsp">CLICK HERE</a>&nbsp;&nbsp;&nbsp;
		TO GO HOME
	</div>
</body>
</html>