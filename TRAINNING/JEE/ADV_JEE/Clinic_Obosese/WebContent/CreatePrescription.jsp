<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Create_Prescription</title>
</head>
<body style="background-color: SILVER;">
	<div align="center">
		<h1 style="color: navy;">RECUPERATION CLINIC</h1>
		<hr color="blue" width="100%" size="3">
	<BR/>
	</div>
	<form action="CreatePrespServlet">
		<%
	  String email = (String)session.getAttribute("demail");
	%>
		<table width="100">
		<tr>
		<td>Doc. Id.</td>
		<td>&nbsp;</td>
		<td><input type="email" name="DocId" value=<%=email%> readonly="readonly"></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
			<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
			<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td></td>
		<td>Patient. Id.</td>
		<td>&nbsp;</td>
		<td><input type="email" placeholder="Enter Patient Email" name="Pid" required></td>
		</tr>
		</table>
		
			<div align="center">
			<h1>MEDICINE DETAILS</h1>
			<table border="1">
			
				<tr>
					<th>Medicine Name</th>
					<td>&nbsp;</td>
					<th>Dosage</th>
					<td>&nbsp;</td>
					<th>Duration</th>
					
				</tr>
				<tr>
					<td> <input type="text" placeholder="Enter Medicine Name" name="Mname1" required></td>
					<td>&nbsp;</td>
					<td> <input type="number" placeholder="Enter Dosage" name="Mdose1" required></td>
					<td>&nbsp;</td>
					<td> <input type="number" placeholder="Enter Duration" name="Mdur1" required></td>
				</tr>
				<tr>
					<td> <input type="text" placeholder="Enter Medicine Name" name="Mname2" required></td>
					<td>&nbsp;</td>
					<td> <input type="number" placeholder="Enter Dosage" name="Mdose2" required></td>
					<td>&nbsp;</td>
					<td> <input type="number" placeholder="Enter Duration" name="Mdur2" required></td>
				</tr>
				
				</table>
				<br/>
				<br/>
				<br/>
				<h1>PATHOLOGY DETAILS</h1>
				<table border="1">
				<tr>
					<td style="font-style: inherit;">Test 1</td>
					<td>&nbsp;</td>
					<td>
						<input type="text" placeholder="Enter Test Name" name="Ptest1" required>
						
					</td>
				</tr>
				<tr>
					<td style="font-style: inherit;">Test 2</td>
					<td>&nbsp;</td>
					<td>
						<input type="text" placeholder="Enter Test Name" name="Ptest2" required>
						
					</td>
				</tr>
				
				
			</table>
			<br/>
				<br/>
			<input type="submit" value="SUBMIT">
			<br/>	<br/>	<br/>
		
		<a href="AfterDocLogin.jsp">CLICK HERE</a>&nbsp;&nbsp;&nbsp;
		TO GO DOCTOR HOME
			</div>
		</form>
		
</body>
</html>