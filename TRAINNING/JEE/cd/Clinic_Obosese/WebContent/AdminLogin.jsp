<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Admin Login</title>
</head>
<body style="background-color: silver;">


	<h1 align="CENTER" style="color:blue; font-size: 75PX; font-family: monospace;">
		ADMIN LOGIN
	</h1>
	<div align="center">
	<img src="first_aid.png" width="400" height="200">
	</div>
	<hr color="GREEN" width="100%" size="5">
	<BR/>
	<marquee behavior="alternate" style="color: green;">ENTER ADMIN USERID AND PASSWORD</marquee>
	<div align="center">
		
	<BR/>
	<form action="AdminServletnew">
		<div style="color: red; font-weight: bold;">
		 	<%
		 		if(request.getAttribute("errmsg")=="1")
		 		{
		 			out.println("WRONG ID OR PASSWORD");
		 		}
		 		
		 	%>
		 	
		</div>
		<table border="1">
			<tr>
			<td>USERNAME</td>
			<td>&nbsp;</td>
			<td> <input type="text" placeholder="Enter Username" name="Aname"></td>
			</tr>
	
			<tr>
			<td>PASSWORD</td>
			<td>&nbsp;</td>
			<td> <input type="password" placeholder="Enter Password" name="Apass"></td>
			</tr>
	
		</table>
		<BR/>
		<BR/>
		<input type="submit" value="LOGIN">
		<input type="reset" value="RESET">
		</form>
		
	</div>




</body>
</html>