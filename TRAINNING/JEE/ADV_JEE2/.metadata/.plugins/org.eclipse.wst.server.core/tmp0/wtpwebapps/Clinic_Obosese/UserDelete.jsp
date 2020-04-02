<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>USER ID</title>
</head>
<body  style="background-color: silver;">
	<h1 align="CENTER" style="color:green; font-size: 50PX; font-family:monospace;">
		RECUPERATION CLINIC
	</h1>
	<hr color="blue" width="100%" size="3">
	<BR/>
	<div align="center">
		<h1>DELETE DOCTOR ID</h1>
		<form action="UserDel">
		<div style="color: red; font-weight: bold;">
		 	<%
		 		if(request.getAttribute("errmsg")=="2")
		 		{
		 			out.println("INVALID USER ID");
		 			request.setAttribute("errmsg", "5");
		 		}
		 		if(request.getAttribute("errmsg")=="1")
	 			{
	 				out.println("NOT DELETED");
	 				request.setAttribute("errmsg", "5");
	 			}
		 		if(request.getAttribute("errmsg")=="0")
	 			{
	 				out.println("DELETED");
	 				request.setAttribute("errmsg", "5");
	 			}
		 	%>
		 	
		</div>
		<table border="1">
			<tr>
			<td>USERNAME</td>
			<td>&nbsp;</td>
			<td> <input type="email" placeholder="Enter Email Id" name="Demail"></td>
			</tr>
	
		</table>
		<BR/>
		<BR/>
		<input type="submit" value="DELETE">
		<input type="reset" value="RESET">
		</form>
		<BR/>
		<BR/>
		<a href="AdminAfterLogin.jsp">CLICK HERE</a>&nbsp;&nbsp;&nbsp;
		TO GO ADMIN HOME
		
	</div>
	
</body>
</html>