<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>

<head>
<meta charset="ISO-8859-1">
<title>User-Registration</title>
<link
	href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css"
	rel="stylesheet"
	integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC"
	crossorigin="anonymous">
</head>

<body>
	<header>
		<nav class="navbar navbar-expand-md navbar-dark"
			style="background-color: green;">
			<div>
				<h3 class="navbar-brand" >Users Book Library</h3>
			</div>

			<ul class="navbar-nav">
				<li><a href="<%=request.getContextPath()%>/users/list"
					class="nav-link">Users</a></li>
			</ul>
		</nav>
	</header>
	<br>
	<form action="./users/insert" method="post">
	<div class="mb-3 row">
		<label for="name" class="col-sm-2 col-form-label">Name</label>
		<div class="col-sm-5">
			<input type="text" class="form-control" id="name" required name="name"> 
		</div>
	</div>

	<div class="mb-3 row">
		<label for="pwd" class="col-sm-2 col-form-label">Password</label>
		<div class="col-sm-5">
			<input type="password" class="form-control" id="pwd" required name="pwd">
		</div>
	</div>

	<div class="mb-3 row">
		<label for="email" class="col-sm-2 col-form-label">Email</label>
		<div class="col-sm-5">
			<input type="text" class="form-control" id="email"
				placeholder="email@example.com" required name="email">
		</div>
	</div>
	<div class="mb-3 row">
		<label for="mob" class="col-sm-2 col-form-label">Mobile No.</label>
		<div class="col-sm-5">
			<input type="text" class="form-control" id="mob" required name="mob">
		</div>
	</div>
	<button type="submit" class="btn btn-success">Submit</button>
	</form>
</body>

</html>