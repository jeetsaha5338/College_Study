<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Login Page</title>
</head>
<body>
	<h1 align="CENTER" style="color: navy; font-size: 100PX; font-family: serif;">
		AOT
	</h1>
	
	<h1 align="CENTER" style="color: black; font-family: fantasy;">
		ACADEMY OF TECHNOLOGY
	</h1>
	
	<hr color="RED" width="80%" size="5">
	<BR/>
	<div align="center">
		<h1>PATIENT LOGIN PAGE</h1>
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
			<td> <input type="password" name="Ppass"></td>
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
		<BR/>
		<BR/>
		 <a href="Home.jsp">GO TO HOME</a>
		
	</div>
</body>
</html>