<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Register</title>
<!-- Compiled and minified CSS -->
<link rel="stylesheet"
	href="https://cdnjs.cloudflare.com/ajax/libs/materialize/1.0.0/css/materialize.min.css">

<!-- Compiled and minified JavaScript -->
<script
	src="https://cdnjs.cloudflare.com/ajax/libs/materialize/1.0.0/js/materialize.min.js"></script>

</head>
<body style="background: url(img/1.jpg); background-size: cover;">
	<div class="container">
		<div class="row">
			<div class="col m6 offset-m3">
				<div class="card" style="border-radius: 15px;">
					<div class="card-content">
						<h3 style="margin-top: 10px;" class="center-align">Register
							Here</h3>
						<h6 class="center-align" id="msg"></h6>
						<div class="form center-align">
							<!-- Creating form -->
							<form action="Register" method="POST" id="myform">
								<input type="text" name="username" placeholder="Enter Username">
								<input type="password" name="password" placeholder="Password">
								<input type="email" name="email" placeholder="Email">
								<div class="file-field input-field">
									<div class="btn">
										<span>File</span> <input type="file" name="image">
									</div>
									<div class="file-path-wrapper">
										<input class="file-path validate" type="text">
									</div>
								</div>
								<button type="submit" class="btn green" style="margin-top: 10px">Submit</button>
							</form>
						</div>

						<div class="loader center-align"
							style="margin-top: 20px; display: none">
							<div class="preloader-wrapper small active">
								<div class="spinner-layer spinner-green-only">
									<div class="circle-clipper left">
										<div class="circle"></div>
									</div>
									<div class="gap-patch">
										<div class="circle"></div>
									</div>
									<div class="circle-clipper right">
										<div class="circle"></div>
									</div>
								</div>
							</div>
							<h6>Please wait..</h6>
						</div>
					</div>
				</div>
			</div>
		</div>
	</div>

	<script src="https://code.jquery.com/jquery-3.6.0.min.js"
		integrity="sha256-/xUj+3OJU5yExlq6GSYGSHk7tPXikynS7ogEvDej/m4="
		crossorigin="anonymous">
		
	</script>

	<script type="text/javascript">
		$(document).ready(function() {
			console.log("Page is ready...")
			$("#myform").on('submit', function(event) {
				event.preventDefault();
				//var f = $(this).serialize(); // serialize only for string/text data
				
				let f = new FormData(this);
				
				console.log(f);
				$(".loader").show();
				$(".form").hide();
				$.ajax({
					url : "Register",
					data : f,
					type : 'POST',
					success : function(data, textStatus, jqXHR) {
						console.log(data);
						console.log("Success... ");
						$(".loader").hide();
						$(".form").show();
						if (data.trim() === 'pass') {
							$('#msg').html("Registered Successfully !!!");
							$('#msg').addClass('green-text');
						} else {
							$('#msg').html("Something Went Wrong :(");
							$('#msg').addClass('red-text');
						}
					},
					error : function(jqXHR, textStatus, errotThrown) {
						console.log(data);
						console.log("Failure... ");
						$(".loader").hide();
						$(".form").show();
						$('#msg').html("Something Went Wrong :(");
						$('#msg').addClass('red-text');
					},
					processData: false,
					contentType: false
				})
			})
		})
	</script>
</body>
</html>