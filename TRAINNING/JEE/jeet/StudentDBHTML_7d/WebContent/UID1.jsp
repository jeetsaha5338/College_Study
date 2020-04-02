<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>USER ID</title>
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
		<h1>STUDENT ID SEARCH PAGE</h1>
		<form action="UserDel">
		<div style="color: red; font-weight: bold;">
		 	<%
		 		if(request.getAttribute("errmsg")=="2")
		 		{
		 			out.println("INVALID USER ID");
		 		}
		 		if(request.getAttribute("errmsg")=="1")
	 			{
	 				out.println("NOT DELETED");
	 			}
		 		if(request.getAttribute("errmsg")=="0")
	 			{
	 				out.println("DELETED");
	 			}
		 	%>
		 	
		</div>
		<table border="1">
			<tr>
			<td>USERNAME</td>
			<td>&nbsp;</td>
			<td> <input type="text" placeholder="Enter Username" name="Uname"></td>
			</tr>
	
		</table>
		<BR/>
		<BR/>
		<input type="submit" value="DELETE">
		<input type="reset" value="RESET">
		</form>
		<img src="Image/A.png" width="200" height="100">
	</div>
	
</body>
</html>