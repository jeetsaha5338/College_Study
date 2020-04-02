<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Insert title here</title>
</head>
<body style="background-color: silver;">
	<h1 align="CENTER" style="color:green; font-size: 50PX; font-family:monospace;">
		RECUPERATION CLINIC
	</h1>
	<hr color="blue" width="100%" size="3">
	<BR/>
	
	<div align="center">
	<h3>TOTAL EARNINGS = <%= request.getAttribute("info") %></h3>
	<a href="AdminAfterLogin.jsp">Go  To Admin Home</a>
	</div>
</body>
</html>