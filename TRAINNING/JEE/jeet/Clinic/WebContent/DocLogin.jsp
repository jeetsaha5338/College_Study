<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Insert title here</title>
</head>
<body>
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
		<h1 style="color: navy;">DOCTOR LOGIN PAGE</h1>
		
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
			<td> <input type="password" name="Dpass"></td>
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
		<BR/>
		<BR/>
		 <a href="Home.jsp">GO TO HOME</a>
		
		
	</div>



	
</body>
</html>