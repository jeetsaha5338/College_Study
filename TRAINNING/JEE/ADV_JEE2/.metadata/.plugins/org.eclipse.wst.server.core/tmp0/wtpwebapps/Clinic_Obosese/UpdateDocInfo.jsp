<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Update_Doc_Info</title>
</head>
<body style="background-color: silver;">
<h1 align="CENTER" style="color:green; font-size: 50PX; font-family:monospace;">
		RECUPERATION CLINIC
	</h1>
	
<hr color="blue" width="100%" size="3">
<br/>
	<div align="center">
	
			<form action="UpdateDoc">
			<%
			if(request.getAttribute("errmsg") == "invalid1")
	 		{
	 			out.println("RECORD NOT UPDATED");
	 		}
			String email = (String)session.getAttribute("demail");
			String name = (String)session.getAttribute("dname");
			String reg = (String)session.getAttribute("dreg");
	%>
			<table border="1">
			
				<tr>
					<td>Name</td>
					<td>&nbsp;</td>
					<td> <input type="text" name="Dname" value=<%=name%> readonly="readonly"></td>
				</tr>
				
				<tr>
					<td>Email</td>
					<td>&nbsp;</td>
					<td> <input type="email" name="Demail" value=<%=email%> readonly="readonly"></td>
				</tr>
				
				<tr>
					<td>Mobile No.</td>
					<td>&nbsp;</td>
					<td> <input type="number" placeholder="Enter Mobile Number" name="Dmob" required></td>
				</tr>
				
				<tr>
					<td>Qualification</td>
					<td>&nbsp;</td>
					<td>
						<select name="Qual" required>
							<option>M.B.B.S</option>
							<option>M.D/M.S</option>
							<option>F.R.C.S</option>
							<option>Any Other</option>
						</select>
					</td>
				</tr>
				
				<tr>
					<td>Specialisation</td>
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
				
				<tr>
					<td>Experience</td>
					<td>&nbsp;</td>
					<td> <input type="number" placeholder="Enter Number of Years" name="Exp" required></td>
				</tr>
				
				<tr>
					<td>Choose PassWord</td>
					<td>&nbsp;</td>
					<td> <input type="password" placeholder="Choose Password" name="Dpass" required></td>
				</tr>
				
				<tr>
					<td>Registration</td>
					<td>&nbsp;</td>
					<td> <input type="number" name="Reg" value=<%=reg%> readonly="readonly"></td>
				</tr>
				
				<tr>
					<td>Fees</td>
					<td>&nbsp;</td>
					<td> <input type="number" placeholder="Enter Amount" name="Dfees" required></td>
				</tr>
				
				<tr>
					<td>Time</td>
					<td>&nbsp;</td>
					<td> <input type="text" placeholder="Enter Time" name="Dtime" required></td>
				</tr>
				
				<tr>
					<td>Enter Max Number of Patient</td>
					<td>&nbsp;</td>
					<td> <input type="number" placeholder="Enter Number" name="Dpno" required></td>
				</tr>
				
			</table>
			<br/>	<br/>
			<input type="submit" value="UPDATE">
		</form>
		<br/>	<br/>	<br/>
		
		<a href="AfterDocLogin.jsp">CLICK HERE:</a>
		TO GO DOCTOR HOME
	</div>
</body>
</html>