<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!doctype html>
<html lang="en">
<head>

<meta charset="utf-8">
<meta name="viewport"
	content="width=device-width, initial-scale=1, shrink-to-fit=no">

<link rel="stylesheet"
	href="https://cdn.jsdelivr.net/npm/bootstrap@4.6.0/dist/css/bootstrap.min.css">
<style type="text/css">
#division {
	background-image: url("./images/reader.jpg");
	height: 270px;
}
</style>
<title>Welcome</title>
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
				<li class="nav-item active"><a class="nav-link" href=#>Home
						<span class="sr-only">(current)</span>
				</a></li>
				<li class="nav-item"><a
					class="btn btn-outline-secondary my-2 my-sm-0"
					href="./loginServlet/listBooks">MyBooks </a></li>
			</ul>
			<div class="form-inline my-2 my-lg-0">
				<ul class="navbar-nav mr-auto">
					<li class="nav-item"><a class="nav-link"
						href="<%=request.getContextPath()%>/updateform.jsp">Edit
							Profile</a></li>
				</ul>
				<a href="<%=request.getContextPath()%>/logout"
					class="btn btn-outline-danger my-2 my-sm-0">Logout</a>
			</div>
		</div>
	</nav>
	<div class="jumbotron" id="division">
		<div class="container">
			<h1 class="display-3">Hey, ${message} Welcome back</h1>
			<p>This is a simple application to manage User's books.</p>
		</div>
	</div>
	<footer class="container">
		<p>&copy; Pranav Choudhary 2021</p>
	</footer>
</body>
</html>