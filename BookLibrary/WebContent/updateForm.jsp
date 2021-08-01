<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>
<!doctype html>
<html lang="en">
<head>
<!-- Required meta tags -->
<meta charset="utf-8">
<meta name="viewport"
	content="width=device-width, initial-scale=1, shrink-to-fit=no">

<!-- Bootstrap CSS -->
<link rel="stylesheet"
	href="https://cdn.jsdelivr.net/npm/bootstrap@4.6.0/dist/css/bootstrap.min.css">
<link href="css/update_style.css" rel="stylesheet" type="text/css" />
<title>UpdateInfo</title>

<script type="text/javascript">
	function validate() {
		if (document.getElementById('password').value == document
				.getElementById('confirm_password').value) {
			document.getElementById('sub').disabled = false;
		} else {
			document.getElementById('sub').disabled = true;
			alert("Password Mismatched");
		}
	}

	function success() {
		alert('Information Updated successfully!!!');
	}
</script>
</head>

<body>
	<%
		response.setHeader("Cache-Control", "no-cache");
	response.setHeader("Cache-Control", "no-store");
	response.setHeader("Pragma", "no-cache");
	response.setDateHeader("Expires", 0);

	if (session.getAttribute("session_user") == null && session.getAttribute("session_pwd") == null)
		response.sendRedirect("login.jsp");
	%>
	<nav class="navbar navbar-expand-lg navbar-dark bg-dark">
		<span class="navbar-brand mb-0 h1">${message}</span>
		<button class="navbar-toggler" type="button" data-toggle="collapse"
			data-target="#navbarSupportedContent"
			aria-controls="navbarSupportedContent" aria-expanded="false"
			aria-label="Toggle navigation">
			<span class="navbar-toggler-icon"></span>
		</button>

		<div class="collapse navbar-collapse" id="navbarSupportedContent">
			<ul class="navbar-nav mr-auto">
				<li class="nav-item"><a class="nav-link" href="welcome.jsp">Home
				</a></li>
				<li class="nav-item"><a
					class="btn btn-outline-secondary my-2 my-sm-0"
					href="./loginServlet/listBooks">MyBooks</a></li>
			</ul>
			<div class="form-inline my-2 my-lg-0">
				<ul class="navbar-nav mr-auto">
					<li class="nav-item active"><a class="nav-link" href="#">Edit
							Profile<span class="sr-only">(current)</span>
					</a></li>
				</ul>
				<a href="<%=request.getContextPath()%>/logout"
					class="btn btn-outline-danger my-2 my-sm-0">Logout</a>
			</div>
		</div>
	</nav>
	<div class="container">
		<div class="update">
			<h1>Update Profile</h1>
			<form action="loginServlet" method="post">
				<div class="form-group">
					<label for="uname">New User Name</label> <input type="text"
						class="form-control" name="uname" required
						value="${sessionScope.message}">
				</div>

				<div class="form-group">
					<label for="uemail">Email address:</label> <input type="email"
						name="uemail" readonly class="form-control-plaintext"
						value="${sessionScope.session_user}">
				</div>

				<div class="form-group">
					<label for="upwd">New Password:</label> <input type="password"
						class="form-control" name="upwd" id="password" required>
				</div>

				<div class="form-group">
					<label for="confirmupwd">Confirm New Password:</label> <input
						type="password" class="form-control" name="confirmupwd"
						id="confirm_password" required onchange='validate();'>
				</div>
				<div class="form-group">
					<label for="umob">New Mobile No.</label> <input type="tel"
						class="form-control" name="umob">
				</div>
				<div class="position-absolute top-left">
					<button type="submit" class="btn btn-success" id="sub"
						style="border-radius: 10px;" value="Update" name="submit" disabled
						onclick='success();'>Update User</button>
				</div>
			</form>
			<form action="./loginServlet">
				<div class="text-right">
					<button type="submit" class="btn btn-danger"
						style="border-radius: 10px;" value="Delete" name="submit">Delete
						User</button>
				</div>
			</form>
		</div>
	</div>
</body>
</html>