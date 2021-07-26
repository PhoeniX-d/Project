<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>

<head>
<meta charset="ISO-8859-1">
<title>Add books to Library</title>
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
				<h3 class="navbar-brand">Add Book</h3>
			</div>

			<ul class="navbar-nav">
				<li><a href="<%=request.getContextPath()%>/list"
					class="nav-link">Users</a></li>
			</ul>
		</nav>
	</header>
	<br>
	<form action="book/insert" method="post">
		<div class="mb-3 row">
			<label for="bname" class="col-sm-2 col-form-label">Name of
				Book</label>
			<div class="col-sm-5">
				<input type="text" class="form-control" required name="bname">
			</div>
		</div>

		<div class="mb-3 row">
			<label for="bauthor" class="col-sm-2 col-form-label">Author
				of Book</label>
			<div class="col-sm-5">
				<input type="text" class="form-control" required name="bauthor">
			</div>
		</div>

		<div class="mb-3 row">
			<label for="bcategory" class="col-sm-2 col-form-label">Category
				Of Book</label>
			<div class="col-sm-5">
				<input type="text" class="form-control" required name="bcategory">
			</div>
		</div>
		<div class="mb-3 row">
			<label for="bprice" class="col-sm-2 col-form-label">Price of
				Book</label>
			<div class="col-sm-5">
				<input type="text" class="form-control" required name="bprice">
			</div>
		</div>
		<div class="mb-3 row">
			<label for="bpages" class="col-sm-2 col-form-label">Total
				Pages</label>
			<div class="col-sm-5">
				<input type="text" class="form-control" name="bpages">
			</div>
		</div>
		<button type="submit" class="btn btn-success">Submit</button>
	</form>
</body>

</html>