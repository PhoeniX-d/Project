<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
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
<link href="../css/update_style.css" rel="stylesheet" type="text/css" />
<title>EditBook</title>
<script src="https://code.jquery.com/jquery-1.10.2.min.js"></script>
</head>
<body>
	<%
		response.setHeader("Cache-Control", "no-cache");
	response.setHeader("Cache-Control", "no-store");
	response.setHeader("Pragma", "no-cache");
	response.setDateHeader("Expires", 0);

	if (session.getAttribute("session_user") == null && session.getAttribute("session_pwd") == null)
		response.sendRedirect(request.getContextPath() + "/login.jsp");
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
					class="btn btn-outline-secondary my-2 my-sm-0" href="./listBooks">MyBooks</a></li>
			</ul>
			<div class="form-inline my-2 my-lg-0">
				<ul class="navbar-nav mr-auto">
					<li class="nav-item"><a class="nav-link"
						href="<%=request.getContextPath()%>updateform.jsp">Edit
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
			<h1>Edit Book</h1>
			<form action="loginServlet" method="post">
				<div class="form-group">
					<label for="bid">Book ID</label> <input type="text"
						class="form-control" name="bid" readonly
						class="form-control-plaintext" value="${book.bId}">
				</div>
				<div class="form-group">
					<label for="bname">Book Name</label> <input type="text"
						class="form-control" name="bname" value="${book.bName}" required>
				</div>
				<div class="form-group">
					<label for="bauthor">Author Name</label> <input type="text"
						class="form-control" name="bauthor" value="${book.bAuthor}"
						required>
				</div>
				<div class="form-group">
					<label for="bcategory">Category</label> <input type="text"
						class="form-control" name="bcategory" value="${book.bCategory}"
						required>
				</div>
				<div class="form-group">
					<label for="bprice">Price</label> <input type="number"
						class="form-control" name="bprice" value="${book.bPrice}">
				</div>
				<div class="form-group">
					<label for="bpages">Total Pages</label> <input type="number"
						class="form-control" name="bpages" value="${book.bPageCounts}">
				</div>
				<div class="form-group">
					<label for="blang">Select Language</label> <select name="blang"
						class="form-select form-select-sm"
						aria-label=".form-select-sm example">
						<option value="${book.bLang}" selected>${book.bLang}</option>
						<option value="Hindi">Hindi</option>
						<option value="Marathi">Marathi</option>
						<option value="Spanish">Spanish</option>
						<option value="German">German</option>
						<option value="English">English</option>
					</select>
				</div>
				<div class="position-absolute">
					<button type="submit" class="btn btn-success" id="sub"
						style="border-radius: 10px; position: relative; left: 170px;"
						value="EditBook" name="submit">Edit Info</button>
				</div>
			</form>
		</div>
	</div>
</body>
<script type="text/javascript">
	var code = {};
	$("select[name='blang'] > option").each(function() {
		if (code[this.text]) {
			$(this).remove();
		} else {
			code[this.text] = this.value;
		}
	});
</script>
</html>