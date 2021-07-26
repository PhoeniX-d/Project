<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Register Account</title>
<link href="https://fonts.googleapis.com/css?family=ZCOOL+XiaoWei"
	rel="stylesheet">
<link href="css/reg_style.css" rel="stylesheet" type="text/css" />

<script type="text/javascript">
	function validate() {
		if (document.getElementById('password').value == document
				.getElementById('confirm_password').value) {
			document.getElementById('submit').disabled = false;
		} else {
			document.getElementById('submit').disabled = true;
			alert("Password Mismatched");
		}
	}

	function success() {
		alert('User added successfully!!!');
	}
</script>
</head>
<body>
	<div class="container">
		<div class="regbox box">
			<h1>Register User</h1>
			<form action="loginServlet" method="post">
				<div class="form-group">
					<label for="uname">User Name</label> <input type="text"
						class="form-control" name="uname" required>
				</div>

				<div class="form-group">
					<label for="uemail">Email address:</label> <input type="text"
						name="uemail" required>
				</div>

				<div class="form-group">
					<label for="upwd">Password:</label> <input type="password"
						class="form-control" name="upwd" id="password" required>
				</div>

				<div class="form-group">
					<label for="confirmupwd">Confirm Password:</label> <input
						type="password" class="form-control" name="confirmupwd"
						id="confirm_password" required onchange='validate();'>
				</div>
				<div class="form-group">
					<label for="umob">Mobile No.</label> <input type="text"
						class="form-control" name="umob">
				</div>
				<div class="text-center">
					<input type="submit" class="btn btn-md btn-info" value="Register"
						id="submit" name="submit" disabled onclick='success();'>
				</div>
			</form>
			<a href="login.jsp" class="btn btn-block btn-danger"> Already
				Register ? </a>
		</div>
	</div>
</body>
</html>