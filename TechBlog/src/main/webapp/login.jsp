<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>
<%@ page import="com.acn.blog.utility.Message"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Login</title>
<!-- CSS -->

<link
	href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css"
	rel="stylesheet"
	integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3"
	crossorigin="anonymous">
<link href="css/mystyle.css" rel="stylesheet" type="text/css">
<link rel="stylesheet"
	href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
<style>
.banner-background {
	clip-path: polygon(30% 0, 70% 0%, 100% 0, 100% 100%, 70% 85%, 30% 100%, 0 85%, 0 0);
}
</style>
</head>

<body>
	<!-- Navbar -->
	<%@include file="general_navbar.jsp"%>

	<!-- Login Form  -->
	<main
		class="d-flex align-items-center primary-background banner-background"
		style="height:75vh;">
	<div class="container">
		<div class="row">
			<div class="col-md-4 offset-md-4">
				<div class="card">
					<div class="card-header primary-background text-white text-center">
						<span class="fa fa-user fa-3x"></span><br />Login Here
					</div>

					<%
						Message msg = (Message) session.getAttribute("msg");
						if (msg != null) {
					%>
					<div class="alert <%=msg.getCssClass()%> text-center" role="alert">
						<%=msg.getContent()%>
					</div>
					<%
						session.removeAttribute("msg");
						}
					%>

					<div class="card-body">
						<form action="LoginServlet" method="POST">
							<div class="mb-3">
								<label for="email" class="form-label">Email address</label> <input
									name="email" required type="email" class="form-control"
									id="email">
							</div>
							<div class="mb-3">
								<label for="password" class="form-label">Password</label> <input
									name="password" required type="password" class="form-control"
									id="password">
							</div>
							<div class="container text-center">
								<button type="submit" class="btn primary-background text-white">Submit</button>
							</div>
						</form>
					</div>

				</div>
			</div>
		</div>
	</div>

	</main>

	<!-- Javascript -->
	<script src="https://code.jquery.com/jquery-3.6.0.min.js"
		integrity="sha256-/xUj+3OJU5yExlq6GSYGSHk7tPXikynS7ogEvDej/m4="
		crossorigin="anonymous"></script>
	<script
		src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.10.2/dist/umd/popper.min.js"
		integrity="sha384-7+zCNj/IqJ95wo16oMtfsKbZ9ccEh31eOz1HGyDuCQ6wgnyJNSYdrPa03rtR1zdB"
		crossorigin="anonymous"></script>
	<script
		src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.min.js"
		integrity="sha384-QJHtvGhmr9XOIpI6YVutG+2QOK9T+ZnN4kzFN1RtK3zEFEIsxhlmWl5/YESvpZ13"
		crossorigin="anonymous"></script>
</body>
</html>
