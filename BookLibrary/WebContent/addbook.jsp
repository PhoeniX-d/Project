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
<title>AddNewBook</title>
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
				<li class="nav-item"><a class="nav-link"
					href="<%=request.getContextPath()%>/welcome.jsp">Home </a></li>
				<li class="nav-item"><a
					class="btn btn-outline-secondary my-2 my-sm-0"
					href="./loginServlet/listBooks">MyBooks</a></li>
			</ul>
			<div class="form-inline my-2 my-lg-0">
				<ul class="navbar-nav mr-auto">
					<li class="nav-item"><a class="nav-link" href="updateform.jsp">Edit
							Profile<span class="sr-only"></span>
					</a></li>
				</ul>
				<a href="<%=request.getContextPath()%>/logout"
					class="btn btn-outline-danger my-2 my-sm-0">Logout</a>
			</div>
		</div>
	</nav>
	<div class="container">
		<div class="update">
			<h1>Add New book</h1>
			<form action="loginServlet" method="post"
				enctype="multipart/form-data">
				<div class="form-group">
					<label for="bname">Book Name</label> <input type="text"
						class="form-control" name="bname" required>
				</div>
				<div class="form-group">
					<label for="bauthor">Author Name</label> <input type="text"
						class="form-control" name="bauthor" required>
				</div>
				<div class="form-group">
					<label for="bcategory">Category</label> <input type="text"
						class="form-control" name="bcategory" required>
				</div>
				<div class="form-group">
					<label for="bprice">Price</label> <input type="number"
						class="form-control" name="bprice">
				</div>
				<div class="form-group">
					<label for="bpages">Total Pages</label> <input type="number"
						class="form-control" name="bpages">
				</div>
				<div class="form-group">
					<label for="blang">Select Language</label> <select name="blang"
						class="form-select form-select-sm"
						aria-label=".form-select-sm example">
						<option selected>Select Language</option>
						<option value="English">English</option>
						<option value="Hindi">Hindi</option>
						<option value="Marathi">Marathi</option>
						<option value="German">German</option>
						<option value="Spanish">Spanish</option>
					</select>
				</div>
				<div>
					<label for="bauthorimg">Author Image</label> <input id="bauthorimg"
						name="bauthorimg" type="file" class="file"
						data-show-preview="false" />
				</div>
				<div class="position-absolute">
					<button type="submit" class="btn btn-success" id="sub"
						style="border-radius: 10px; position: relative; left: 135px;"
						value="AddBook" name="submit">Add Book</button>
				</div>
			</form>
		</div>
	</div>
</body>
</html>