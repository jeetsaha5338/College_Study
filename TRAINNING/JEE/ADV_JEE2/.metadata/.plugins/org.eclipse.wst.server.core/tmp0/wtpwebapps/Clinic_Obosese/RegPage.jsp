<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Patient_Reg.</title>
</head>
<body style="background-color: silver;">
		
	<h1 align="CENTER" style="color: blue; font-size: 75PX; font-family: monospace;">
		RECUPERATION CLINIC
	</h1>
		
	<hr color="green" width="100%" size="5">
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
				<td> <input type="text" placeholder="Enter Name" name="Pname"></td>
				</tr>
		
				<tr>
				<td>EMAIL</td>
				<td>&nbsp;</td>
				<td> <input type="email" placeholder="Enter Email Id" name="Pemail"></td>
				</tr>

				<tr>
				<td>MOBILE NO.</td>
				<td>&nbsp;</td>
				<td> <input type="number" placeholder="Enter Mobile No." name="Pmob"></td>
				</tr>
				
				<tr>
				<td>AGE</td>
				<td>&nbsp;</td>
				<td> <input type="number" placeholder="Enter Your Age" name="Age"></td>
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
				<td><input type="password" placeholder="Enter Password" name="Ppass"></td>
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