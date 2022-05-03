<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Registration</title>
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

	<main
		class="d-flex align-items-center primary-background banner-background"
		style="padding-bottom:125px">
	<div class="container">
		<div class="col-md-6 offset-md-3">
			<div class="card">
				<div class="card-header text-center primary-background text-white">
					<span class="fa fa-3x fa-user-plus"></span><br /> Register Here
				</div>
				<div class="card-body">
					<form id="regform" action="RegisterServlet" method="POST">
						<div class="mb-3">
							<label for="username" class="form-label">Enter Username</label> <input
								type="text" class="form-control" id="username" name="username"
								placeholder="User Name">
						</div>

						<div class="mb-3">
							<label for="gender">Select Gender</label><br /> <input
								type="radio" name="gender" id="male" value="male"> <label
								for="male"> Male &nbsp &nbsp</label> <input type="radio"
								name="gender" id="female" value="female"> <label
								for="female"> Female </label>
						</div>

						<div class="mb-3">
							<label for="mobileno" class="form-label">Mobile No</label> <input
								type="text" class="form-control" id="mobileno" name="mobileno"
								placeholder="Enter Mobile No.">
						</div>

						<div class="mb-3">
							<label for="email" class="form-label">Email address</label> <input
								type="email" class="form-control" id="email" name="email"
								aria-describedby="emailHelp" placeholder="Enter Email Address">
							<div id="emailHelp" class="form-text">We'll never share
								your email with anyone else.</div>
						</div>

						<div class="mb-3">
							<label for="password" class="form-label">Password</label> <input
								type="password" class="form-control" id="password"
								name="password">
						</div>

						<div class="mb-3 form-check">
							<input type="checkbox" class="form-check-input" id="terms"
								name="terms"> <label class="form-check-label"
								for="terms">Agree Terms & Conditions</label>
						</div>
						<div class="container text-center" id="loader"
							style="display: none;">
							<span class="fa fa-refresh fa-spin fa-3x"></span><br />
							<h4>Please Wait...</h4>
						</div>
						<div class="container text-center">
							<button id="submitbtn" type="submit"
								class="btn primary-background text-white">Submit</button>
						</div>
					</form>
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
	<script src="js/myjs.js" type="text/javascript"></script>
	<!-- Sweet Alert -->
	<script
		src="https://cdnjs.cloudflare.com/ajax/libs/sweetalert/2.1.2/sweetalert.min.js"
		integrity="sha512-AA1Bzp5Q0K1KanKKmvN/4d3IRKVlv9PYgwFPvm32nPO6QS8yH1HO7LbgB1pgiOxPtfeg5zEn2ba64MUcqJx6CA=="
		crossorigin="anonymous" referrerpolicy="no-referrer"></script>
	<script>
		$(document).ready(function() {
			$('#regform').on('submit', function(event) {

				event.preventDefault();

				let form = new FormData(this);

				$('#submitbtn').hide();
				$('#loader').show();

				// Send to RegisterServlet via Ajax
				$.ajax({
					url : "RegisterServlet",

					type : 'POST',

					data : form,

					success : function(data, textStatus, jqXHR) {
						console.log(data)
						
						$("#submitbtn").show();
						$("#loader").hide();
						
						if(data.trim() === "Success"){
							swal("Good job!", "You Registerd Successfully!", "success", {
								  button: "Login",
							})
							.then((value) => {
									window.location = "login.jsp"
							});
						}
						else{
							swal(data);
						}

					},

					error : function(jqXHR, textStatus, errorThrown) {
						console.log(jqXHR)
						$("#submitbtn").show();
						$("#loader").hide();
						swal("Sorry !!!", "Cannot Registered", "error");
					},

					processData : false,

					contentType : false
				});
			})
		});
	</script>
</body>
</html>