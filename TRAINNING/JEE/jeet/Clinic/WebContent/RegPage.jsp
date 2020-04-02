<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Reg. Page</title>
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
		<h1 style="color: navy;">PATIENT REGISTRATION PAGE</h1>
		<form action="RegServletNew">
			<div style="color: red; font-weight: bold;">
		 	<%
		 		if(request.getAttribute("errmsg")=="RECORD NOT INSERTED")
		 		{
		 			out.println("RECORD NOT INSERTED PLEASE TRY AGAIN");
		 		}
		 	%>
		 	
			</div>
			<table border="1">
				<tr>
				<td>NAME</td>
				<td>&nbsp;</td>
				<td> <input type="text" placeholder="Enter Your Name" name="Pname"></td>
				</tr>
		
				<tr>
				<td>EMAIL</td>
				<td>&nbsp;</td>
				<td> <input type="email" placeholder="Enter Email Id" name="Pemail"></td>
				</tr>

				<tr>
				<td>MOBILE NO.</td>
				<td>&nbsp;</td>
				<td> <input type="number" name="Pmob"></td>
				</tr>
				
				<tr>
				<td>AGE</td>
				<td>&nbsp;</td>
				<td> <input type="number" name="Age"></td>
				</tr>
	
				<tr>
				<td>GENDER</td>
				<td>&nbsp;</td>
				<td> 
					<input type="radio" name="gender" value="Male" > Male
					<input type="radio" name="gender" value="Female" > Female
					
				</td>
				</tr>
				
				<tr>
				<td>PASSWORD</td>
				<td>&nbsp;</td>
				<td><input type="password" name="Ppass"></td>
				</tr>				
	
			</table>
			<BR/>
			<BR/>
			<input type="submit" value="SUBMIT">
			&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;
			<input type="reset" value="RESET">
		</form>
		
		<BR/>
		<BR/>
		ALREADY REGISTERED? 
		<br/>
		<a href="PatientLogin.jsp">CLICK TO LOGIN </a>
		<br/>
		<br/>
		
	</div>
</body>
</html>