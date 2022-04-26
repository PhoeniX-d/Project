<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>
<!doctype html>
<html lang="en">
<head>
<!-- Required meta tags -->
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">

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
	clip-path: polygon(30% 0%, 70% 0%, 100% 0, 100% 90%, 74% 100%, 43% 92%, 0 100%, 0 0);
}
</style>
</head>
<body>

	<!-- Navbar -->
	<%@include file="generic_navbar.html"%>

	<!-- Banner -->
	<div class="container-fluid p-0 m-0 banner-background">
		<div class="jumbotron primary-background text-white">
			<div class="container" style="padding: 1.5%">
				<h3 class="display-4">Welcome to Technical Blog</h3>
				<p>A programming language is any set of rules that converts
					strings, or graphical program elements in the case of visual
					programming languages, to various kinds of machine code output.
					Programming languages are one kind of computer language, and are
					used in computer programming to implement algorithms.
				<p>Most programming languages consist of instructions for
					computers. There are programmable machines that use a set of
					specific instructions, rather than general programming languages.
					Since the early 1800s, programs have been used to direct the
					behavior of machines such as Jacquard looms, music boxes and player
					pianos.</p>
				<button class="btn btn-outline-light">
					<span class="	fa fa-external-link-square"></span> Start Reading
				</button>
				<a href="login.jsp" class="btn btn-outline-light"> <span
					class="fa fa-user-circle"></span> Login
				</a>
			</div>
		</div>
	</div>

	<!-- Cards  -->
	<div class="container" style="padding: 2%">
		<!-- Row 1 -->
		<div class="row mb-5">
			<div class="col-md-3">
				<div class="card">
					<div class="card-body">
						<h5 class="card-title">Java</h5>
						<p class="card-text">Java is a powerful general-purpose
							programming language. It is used to develop desktop and mobile
							applications, big data processing, embedded systems, and so on...</p>
						<a href="#" class="btn primary-background text-white">Read
							More...</a>
					</div>
				</div>
			</div>
			<div class="col-md-3">
				<div class="card">
					<div class="card-body">
						<h5 class="card-title">Java</h5>
						<p class="card-text">Java is a powerful general-purpose
							programming language. It is used to develop desktop and mobile
							applications, big data processing, embedded systems, and so on...</p>
						<a href="#" class="btn primary-background text-white">Read
							More...</a>
					</div>
				</div>
			</div>
			<div class="col-md-3">
				<div class="card">
					<div class="card-body">
						<h5 class="card-title">Java</h5>
						<p class="card-text">Java is a powerful general-purpose
							programming language. It is used to develop desktop and mobile
							applications, big data processing, embedded systems, and so on...</p>
						<a href="#" class="btn primary-background text-white">Read
							More...</a>
					</div>
				</div>
			</div>
			<div class="col-md-3">
				<div class="card">
					<div class="card-body">
						<h5 class="card-title">Java</h5>
						<p class="card-text">Java is a powerful general-purpose
							programming language. It is used to develop desktop and mobile
							applications, big data processing, embedded systems, and so on...</p>
						<a href="#" class="btn primary-background text-white">Read
							More...</a>
					</div>
				</div>
			</div>
		</div>

		<!-- Row 2 -->
		<div class="row">
			<div class="col-md-3">
				<div class="card">
					<div class="card-body">
						<h5 class="card-title">Java</h5>
						<p class="card-text">Java is a powerful general-purpose
							programming language. It is used to develop desktop and mobile
							applications, big data processing, embedded systems, and so on...</p>
						<a href="#" class="btn primary-background text-white">Read
							More...</a>
					</div>
				</div>
			</div>
			<div class="col-md-3">
				<div class="card">
					<div class="card-body">
						<h5 class="card-title">Java</h5>
						<p class="card-text">Java is a powerful general-purpose
							programming language. It is used to develop desktop and mobile
							applications, big data processing, embedded systems, and so on...</p>
						<a href="#" class="btn primary-background text-white">Read
							More...</a>
					</div>
				</div>
			</div>
			<div class="col-md-3">
				<div class="card">
					<div class="card-body">
						<h5 class="card-title">Java</h5>
						<p class="card-text">Java is a powerful general-purpose
							programming language. It is used to develop desktop and mobile
							applications, big data processing, embedded systems, and so on...</p>
						<a href="#" class="btn primary-background text-white">Read
							More...</a>
					</div>
				</div>
			</div>
			<div class="col-md-3">
				<div class="card">
					<div class="card-body">
						<h5 class="card-title">Java</h5>
						<p class="card-text">Java is a powerful general-purpose
							programming language. It is used to develop desktop and mobile
							applications, big data processing, embedded systems, and so on...</p>
						<a href="#" class="btn primary-background text-white">Read
							More...</a>
					</div>
				</div>
			</div>
		</div>
	</div>

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
	<script src="js/myjs.js" type="text/javascript"></script>
</body>
</html>
