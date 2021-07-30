<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<!DOCTYPE html>
<html lang="en">

<head>

<meta charset="utf-8">
<meta name="viewport"
	content="width=device-width, initial-scale=1, shrink-to-fit=no">

<link rel="stylesheet"
	href="https://cdn.jsdelivr.net/npm/bootstrap@4.6.0/dist/css/bootstrap.min.css">

<title>ViewBook</title>
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
					href="<%=request.getContextPath()%>/welcome.jsp">Home <span
						class="sr-only">(current)</span>
				</a></li>
				<li class="nav-item"><a
					class="btn btn-outline-secondary my-2 my-sm-0" href="./listBooks">MyBooks
				</a></li>
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
	<main role="main">
		<section class="jumbotron text-center">
			<div class="container">
				<h1 class="jumbotron-heading">${param.bauthor}</h1>
				<p class="lead text-muted">
					<a
						href="https://www.google.com/search?q=${param.bauthor}%20${param.bname}">Read
						Here</a>
				</p>
			</div>
			<div>
				<%-- 			<c:set var="id" value= "${param.bid}"/> --%>
				<%-- 			<%=  %> --%>
				<form action="loginServlet" method="post"
					enctype="multipart/form-data">
					<label for="bauthorimg"></label>
					<h4>Edit Image</h4>
					<br> <input id="bauthorimg" name="bauthorimg" type="file"
						class="file" data-show-preview="true" required />
					<button type="submit" class="btn btn-success" id="sub"
						style="border-radius: 10px;" value="EditAuthor" name="submit">Update</button>
					<input name="bid" value="${param.bid}" type="hidden" />
				</form>
			</div>
		</section>

		<div class="album bg-light">
			<div class="container">
				<img class="img-fluid rounded-circle float-left"
					src="data:image/jpg;base64,${imgPath}"
					style="max-width: 40%; height: 500px; position: relative; left: 345px;"
					onerror="this.onerror=null; this.src='../images/avatar.png'" alt="">
			</div>
		</div>
	</main>
</body>

</html>