<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Insert title here</title>
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
		<h1>STUDENT SEARCH PAGE</h1>
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
		<br/>	<br/>	<br/>
		
		<a href="AfterDocLogin.jsp">GO TO DOCTOR HOME</a>
		</div>
</body>
</html>