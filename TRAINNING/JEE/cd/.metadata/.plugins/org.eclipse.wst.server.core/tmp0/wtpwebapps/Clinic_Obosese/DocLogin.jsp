<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Doctor_login</title>
</head>
<body>
	<body style="background-color: silver;">


	<h1 align="CENTER" style="color: blue; font-size: 50PX; font-family: monospace;">
		RECUPERATION CLINIC
	</h1>
	
	<hr color="green" width="100%" size="3">
	<BR/>
	
	<div align="center">
		<h1 style="color: navy;">DOCTOR LOGIN PAGE</h1>
		<img src="doctors.jpg" width="500" height="300">
	<BR/>
	<form action="DocLoginServlet">
		<div style="color: red; font-weight: bold;">
		 	<%
		 		if(request.getAttribute("errmsg") != null)
		 		{
		 			out.println( ""+request.getAttribute("errmsg"));
		 		}
		 		if(request.getAttribute("errmsg1") != null)
	 			{
	 				out.println("You Are Not Authorised Yet");
	 			}
		 	%>
		 	
		</div>
		<table border="1">
			<tr>
			<td>USERNAME</td>
			<td>&nbsp;</td>
			<td> <input type="text" placeholder="Enter Username" name="Demail"></td>
			</tr>
	
			<tr>
			<td>PASSWORD</td>
			<td>&nbsp;</td>
			<td> <input type="password" placeholder="Enter Password"name="Dpass"></td>
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
		<a href="DoctorRegistration.jsp">GO TO REGISTRATION PAGE</a>
		<br/><br/>
		<a href="Home.jsp">CLICK HERE</a>&nbsp;&nbsp;&nbsp;
		TO BACK HOME
		
	</div>



	
</body>
</html>