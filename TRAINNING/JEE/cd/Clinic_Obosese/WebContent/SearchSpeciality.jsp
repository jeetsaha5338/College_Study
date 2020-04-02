<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Search_Speciality</title>
</head>
<body style="background-color: silver;">
<h1 align="CENTER" style="color:green; font-size: 50PX; font-family:monospace;">
		RECUPERATION CLINIC
	</h1>
	<hr color="blue" width="100%" size="3">
	<BR/>


	<div align="center">
		<h1>SEARCH DOCTOR BY SPECIALITY</h1>
		<form action="SearchSpecialityServlet">
		<div style="color: red; font-weight: bold;">
		 	<%
		 		if(request.getAttribute("errmsg")=="2")
		 		{
		 			out.println("INVALID");
		 		}
		 	%>
		 	
		</div>
		<table border="1">
			<tr>
			<td>SPECIALITY</td>
			<td>&nbsp;</td>
			<td>
						<select name="Dspec" required>
							<option>General Physician</option>
							<option>E.N.T</option>
							<option>Eye</option>
							<option>Heart</option>
							<option>Pediatrician</option>
							<option>Nuerologist</option>
							<option>Gynaecologist</option>
							<option>Orthopedic</option>
						</select>
					</td>
			</tr>
	
		</table>
		<BR/>
		<BR/>
		<input type="submit" value="SEARCH">
		<input type="reset" value="RESET">
		</form>
		
		<BR/>
		<BR/>
		LOOKING FOR SPECIFIC DOCTOR ?
		<br/>
		<a href="SearchName.jsp">CLICK</a>
		<br/>
		<br/>
		
	</div>




</body>
</html>