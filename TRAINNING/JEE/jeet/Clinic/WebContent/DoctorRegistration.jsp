<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Insert title here</title>
</head>
<body>

	<div align="center">
		<h1 style="color: navy;">DOCTOR REGISTRATION PAGE</h1>
		<form action="DoctorRegServlet">
		
			<table border="1">
			
				<tr>
					<td>Name</td>
					<td>&nbsp;</td>
					<td> <input type="text" placeholder="Enter Your Name" name="Dname" required></td>
				</tr>
				
				<tr>
					<td>Email</td>
					<td>&nbsp;</td>
					<td> <input type="email" placeholder="Enter Email Id" name="Demail" required></td>
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
					<td> <input type="number" placeholder="Enter Registration number" name="Reg" required></td>
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
			<BR/>
		<BR/>
		
			<input type="submit" value="SUBMIT">
		</form>
	</div>
</body>
</html>