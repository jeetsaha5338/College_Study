<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Update_Patient_Info</title>
</head>
<body  style="background-color: silver;">
		
	<div align="center">
		<h1 align="CENTER" style="color:green; font-size: 50PX; font-family:monospace;">
		RECUPERATION CLINIC
	</h1>
	<hr color="blue" width="100%" size="3">
	<BR/>
	<h1>Update Patient Information</h1>
		
		<form action="UpdatePatient">
			<div style="color: red; font-weight: bold;">
		 	<%
		 		if(request.getAttribute("errmsg")=="RECORD NOT INSERTED")
		 		{
		 			out.println("RECORD NOT INSERTED PLEASE TRY AGAIN");
		 		}
		 	String email = (String)session.getAttribute("pemail");
			String name = (String)session.getAttribute("pname");
		 	%>
		 	
			</div>
			<table border="1">
				<tr>
				<td>NAME</td>
				<td>&nbsp;</td>
				<td> <input type="text" name="Pname" value=<%=name%> readonly="readonly"></td>
				</tr>
		
				<tr>
				<td>EMAIL</td>
				<td>&nbsp;</td>
				<td> <input type="email" name="Pemail" value=<%=email%> readonly="readonly"></td>
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
			<input type="submit" value="UPDATE">
		</form>
		
		<BR/>
		<BR/>
		<br/>
	
		<br/><br/><br/><br/><br/>
		 <a href="PatientAfterLogin.jsp">CLICK HERE</a>&nbsp;&nbsp;&nbsp;
		 TO GO PATIENT HOME
		
	</div>
</body>
</html>