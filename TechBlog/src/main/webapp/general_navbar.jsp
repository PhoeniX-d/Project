<%@page import="java.text.DateFormat"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>
<%@ page import="java.text.*"%>
<html>
<head>
</head>
<body>
	<nav class="navbar navbar-expand-lg navbar-dark primary-background">
		<div class="container-fluid">
			<a class="navbar-brand" href="index.jsp"><span
				class="fa fa-graduation-cap"></span> Tech-Blog</a>
			<button class="navbar-toggler" type="button"
				data-bs-toggle="collapse" data-bs-target="#navbarSupportedContent"
				aria-controls="navbarSupportedContent" aria-expanded="false"
				aria-label="Toggle navigation">
				<span class="navbar-toggler-icon"></span>
			</button>
			<div class="collapse navbar-collapse" id="navbarSupportedContent">
				<ul class="navbar-nav me-auto mb-2 mb-lg-0">
					<li class="nav-item"><a class="nav-link active"
						aria-current="page" href="index.jsp"><span class="fa fa-home"></span>
							Home</a></li>
					<li class="nav-item"><a class="nav-link" aria-current="page"
						href="#!" data-bs-toggle="modal" data-bs-target="#contact-modal"><span
							class="fa fa-phone-square"></span> Contact Us</a></li>
				</ul>
				<ul class="navbar-nav mr-right">
					<!-- Link trigger modal -->
					<li class="nav-item"><a class="nav-link" aria-current="page"
						href="login.jsp"><span class="fa fa-user-circle"></span> Login</a></li>
					<li class="nav-item"><a class="nav-link" aria-current="page"
						href="registration.jsp"><span class="fa fa-sign-in"></span>
							Sign-Up</a></li>
				</ul>
			</div>
		</div>
	</nav>

	<!-- Start of Contact Modal -->
	<div class="modal fade" id="contact-modal" tabindex="-1"
		aria-labelledby="exampleModalLabel" aria-hidden="true">
		<div class="modal-dialog">
			<div class="modal-content">
				<div class="modal-header primary-background text-white">
					<h5 class="modal-title" id="exampleModalLabel">Creator</h5>
					<button type="button" class="btn-close" data-bs-dismiss="modal"
						aria-label="Close"></button>
				</div>
				<div class="modal-body">
					<div class="card text-center">
						<div class="card-header" style="font-weight: bold;">Pranav
							P. Chaudhari</div>

						<div class="card-body">
							<img src="profiles/creators.jpg" class="card-img-top"
								class="img-fluid"
								style="width: 100%; max-width: 250px; padding: 1%; border-radius: 25%;"
								onerror="this.onerror=null; this.src='blogpics/default.png'">
							<h5 class="card-title">Contact Info</h5>
							<table class="table table-borderless text-start">
								<tbody>
									<tr>
										<th scope="row">Email</th>
										<td>: pranav24choudhary@gmail.com</td>
									</tr>
									<tr>
										<th scope="row">Mobile No</th>
										<td>: 8989898989</td>
									</tr>
									<tr>
										<td colspan="2" scope="row" style="text-align: center;"><a
											href="https://github.com/PhoeniX-d">My Github</a></td>
									</tr>
									<tr>
										<td colspan="2" "row" style="text-align: center;"><a
											href="https://www.linkedin.com/in/pranav-choudhary-75188a159">My
												LinkedIn</a></td>
									</tr>

								</tbody>
							</table>
						</div>
						<div class="card-footer">
							<p>
								Created On

								<%=DateFormat.getDateInstance().format(new SimpleDateFormat("dd-MM-yyyy").parse("25-04-2022"))%></p>
						</div>
					</div>
				</div>
			</div>
		</div>
	</div>
	<!-- End of Contact Modal -->
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