<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Search_doc_name</title>
</head>
<body style="background-color: silver;">

<h1 align="CENTER" style="color:green; font-size: 50PX; font-family:monospace;">
		RECUPERATION CLINIC
	</h1>
	<hr color="blue" width="100%" size="3">
	<BR/>

	<div align="center">
		<h1>SEARCH DOCTOR BY NAME</h1>
		<form action="SearchNameServlet">
		<div style="color: red; font-weight: bold;">
		 	<%
		 		if(request.getAttribute("errmsg")=="invalid1")
		 		{
		 			out.println("INVALID");
		 		}
		 	%>
		 	
		</div>
		<table border="1">
			<tr>
			<td>DOCTOR'S"NAME</td>
			<td>&nbsp;</td>
			<td> <input type="text" placeholder="Enter Doctor's Name" name="Dname"></td>
			</tr>
	
		</table>
		<BR/>
		<BR/>
		<input type="submit" value="SEARCH">
		<input type="reset" value="RESET">
		</form>
		
		<BR/>
		<BR/>
		LOOKING FOR SPECIFIC SPECIALITY ?
		<br/>
		<a href="SearchSpeciality.jsp">CLICK</a>
		<br/>
		<br/>
		
	</div>




</body>
</html>