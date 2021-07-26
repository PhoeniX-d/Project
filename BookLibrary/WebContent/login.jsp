<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>User Login</title>
<link
	href="//maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css"
	rel="stylesheet" id="bootstrap-css">
<script
	src="//maxcdn.bootstrapcdn.com/bootstrap/4.0.0/js/bootstrap.min.js"></script>
<script src="//code.jquery.com/jquery-1.11.1.min.js"></script>
<link rel="stylesheet" href="css/login_style.css">
</head>
<body>
	<div class="container">
		<p class="text-center">${message}</p>
		<div class="regbox box">
			<h1>User Login</h1>
			<form id="login-form" class="form" action="loginServlet"
				method="post">
				<div class="form-group">
					<label for="username" class="text-info">Username:</label><br>
					<input type="text" name="username" required class="form-control">
				</div>
				<div class="form-group">
					<label for="password" class="text-info">Password:</label><br>
					<input type="text" name="password" required class="form-control">
				</div>
				<div class="form-group">
					<input type="submit" name="submit"
						class="btn btn-success float-left" value="Login"><br>
					<a href="registration.jsp">Register Here</a> <a
						 href="users-list.jsp">Users list</a>
				</div>
			</form>
		</div>
	</div>
</body>
</html>