<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>
<%@ page
	import="com.acn.blog.beans.*, com.acn.blog.service.*, com.acn.blog.utility.*, java.util.List, java.text.*"%>
<%@ page isErrorPage="true" errorPage="errorpage.jsp"%>
<%
	UserBean user = (UserBean) session.getAttribute("currentuser");
	if (user == null) {
		response.sendRedirect("login.jsp");
	}
%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>User Profile</title>
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
	clip-path: polygon(30% 0%, 70% 0%, 100% 0, 100% 90%, 74% 100%, 43% 92%, 0 100%, 0 0
		);
}

body {
	background: url(images/background.jpg);
	background-size: cover;
	background-attachment: fixed;
}
</style>
<script src="js/like.js" type="text/javascript"></script>
</head>
<body>

	<!-- Navbar -->
	<nav class="navbar navbar-expand-lg navbar-dark primary-background">
	<div class="container-fluid">
		<a class="navbar-brand" href="index.jsp"><span
			class="fa fa-graduation-cap"></span> Tech-Blog</a>
		<button class="navbar-toggler" type="button" data-bs-toggle="collapse"
			data-bs-target="#navbarSupportedContent"
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
				<li class="nav-item"><a class="nav-link" href="#!"
					data-bs-toggle="modal" data-bs-target="#addpost-modal"><span
						class="fa fa-newspaper-o"></span> Add Post</a></li>
			</ul>
			<ul class="navbar-nav mr-right">
				<!-- Link trigger modal -->
				<li class="nav-item"><a class="nav-link active"
					aria-current="page" href="#!" data-bs-toggle="modal"
					data-bs-target="#profile-modal"><span class="fa fa-user-circle"></span>
						<%=user.getName()%></a></li>
				<li class="nav-item"><a class="nav-link" aria-current="page"
					href="LogoutServlet"><span class="fa fa-sign-out"></span>
						Logout</a></li>
			</ul>
		</div>
	</div>
	</nav>
	<!-- End Of Navbar -->

	<!-- Start of Main -->
	<main style="padding:1%;">
	<div class="conatiner-fluid">
		<div class="row">
			<!-- First column -->
			<div class="col-md-2">
				<!-- Categories -->
				<div class="list-group">
					<a href="#" onclick="getPosts(0, this)"
						class="list-group-item list-group-item-action active cat-link"
						aria-current="true"> All Categories </a>
					<!-- Categories from DB -->
					<%
						CategoryService service = Factory.getCategoryService();
						List<CategoryBean> categoryBeans = service.getAllCategories();
						for (CategoryBean categoryBean : categoryBeans) {
					%>
					<a href="#" onclick="getPosts(<%=categoryBean.getCid()%>, this)"
						class="list-group-item list-group-item-action cat-link"><%=categoryBean.getCname()%></a>
					<%
						}
					%>
				</div>
			</div>

			<!-- Second column -->
			<div class="col-md-10">
				<!-- Posts -->
				<div class="container text-center" id="loader">
					<i class="fa fa-refresh fa-4x fa-spin"></i>
					<h3 class="mt-3">Loading...</h3>
				</div>
				<!-- Posts from DB -->
				<div class="container-fluid" id="postcontainer"></div>
			</div>
		</div>
	</div>
	</main>
	<!-- End of Main -->

	<!-- Profile Modal -->
	<div class="modal fade" id="profile-modal" tabindex="-1" s
		aria-labelledby="exampleModalLabel" aria-hidden="true">
		<div class="modal-dialog">
			<div class="modal-content">
				<div class="modal-header primary-background text-white align-center">
					<h5 class="modal-title" id="exampleModalLabel">MyProfile</h5>
					<button type="button" class="btn-close" data-bs-dismiss="modal"
						aria-label="Close"></button>
				</div>
				<div class="modal-body">
					<div class="container text-center">
						<img src="profiles/<%=user.getProfile()%>" class="img-fluid"
							style="border-radius: 50%; max-width: 150px;"><br />
						<h5 class="modal-title">
							<b><%=user.getName()%></b>
						</h5>
						<!-- User Details -->
						<div id="profile-details">
							<table class="table table-borderless text-start">
								<tbody>
									<tr>
										<th scope="row">ID</th>
										<td>: <%=user.getId()%></td>
									</tr>
									<tr>
										<th scope="row">Email</th>
										<td>: <%=user.getEmail()%></td>
									</tr>
									<tr>
										<th scope="row">Gender</th>
										<td>: <%
											if (user.getGender() == 'M') {
										%>MALE <%
											} else {
										%>FEMALE<%
											}
										%>
										</td>
									</tr>
									<tr>
										<th scope="row">Mobile No</th>
										<td>: <%=user.getMobileno()%></td>
									</tr>
									<tr>
										<th scope="row">Registered on</th>
										<td>: <%=DateFormat.getDateInstance().format(user.getCreateDate())%></td>
									</tr>
								</tbody>
							</table>
						</div>

						<!-- Profile Edit -->
						<div id="profile-edit" style="display: none">
							<h3 class="mt-2">Edit User Details</h3>
							<form id="editform" action="EditServlet" method="POST"
								enctype="multipart/form-data">
								<table class="table table-borderless text-start">
									<tbody>
										<tr>
											<th scope="row">ID:</th>
											<td><%=user.getId()%></td>
										</tr>
										<tr>
											<th scope="row">Email:</th>
											<td><input type="email"
												class="form-control form-control-sm" name="email"
												value="<%=user.getEmail()%>"></td>
										</tr>
										<tr>
											<th scope="row">Name:</th>
											<td><input type="ename"
												class="form-control form-control-sm" name="name"
												value="<%=user.getName()%>"></td>
										</tr>
										<tr>
											<th scope="row">Password:</th>
											<td><input type="password"
												class="form-control form-control-sm" name="password"
												value="<%=user.getPassword()%>"></td>
										</tr>
										<tr>
											<th scope="row">Gender:</th>
											<td>
												<%
													if (user.getGender() == 'M') {
												%>MALE <%
													} else {
												%>FEMALE<%
													}
												%>
											</td>
										</tr>
										<tr>
											<th scope="row">Mobile No:</th>
											<td><input type="text"
												class="form-control form-control-sm" name="mobileno"
												value="<%=user.getMobileno()%>"></td>
										</tr>

										<tr>
											<th scope="row">Profile Pic:</th>
											<td><input type="file"
												class="form-control form-control-sm" name="profilepic"
												value="<%=user.getMobileno()%>"></td>
										</tr>
									</tbody>
								</table>
								<div class="container text-center">
									<button type="submit" class="btn primary-background text-white">Save</button>
								</div>
							</form>
						</div>

					</div>
				</div>
				<div class="modal-footer">
					<button type="button" class="btn btn-secondary"
						data-bs-dismiss="modal">Close</button>
					<button id="edit-profile-button" type="button"
						class="btn primary-background text-white">Edit</button>
				</div>
			</div>
		</div>
	</div>
	<!-- End of Profile Modal -->

	<!-- Start of Add Post Modal -->
	<!-- Modal -->
	<div class="modal fade" id="addpost-modal" tabindex="-1"
		aria-labelledby="exampleModalLabel" aria-hidden="true">
		<div class="modal-dialog">
			<div class="modal-content">
				<div class="modal-header primary-background text-white align-center">
					<h5 class="modal-title" id="exampleModalLabel">Add Your Post
						Here</h5>
					<button type="button" class="btn-close" data-bs-dismiss="modal"
						aria-label="Close"></button>
				</div>
				<div class="modal-body">
					<form action="AddPostServlet" method="POST" id="addpost-form">
						<div class="form-group">
							<select class="form-control" name="cid">
								<option selected disabled>--- SELECT CATEGORY---</option>
								<%
									service = Factory.getCategoryService();
									categoryBeans = service.getAllCategories();
									for (CategoryBean categoryBean : categoryBeans) {
								%>
								<option value="<%=categoryBean.getCid()%>"><%=categoryBean.getCname()%></option>
								<%
									}
								%>
							</select>
						</div>
						<div class="form-group">
							<input type="text" name="title" placeholder="Title Here"
								class="form-control">
						</div>
						<div class="form-group">
							<textarea name="content" placeholder="Content Here"
								class="form-control" style="height: 250px;"></textarea>
						</div>
						<div class="form-group">
							<textarea name="code" placeholder="Code Here(if Any)"
								class="form-control" style="height: 250px;"></textarea>
						</div>
						<div class="form-group">
							<label>Select Picture for Post</label><br /> <input type="file"
								name="pic">
						</div>
						<div class="container text-center">
							<button type="submit" class="btn primary-background text-white">
								Post</button>
							<button type="button" class="btn btn-secondary"
								data-bs-dismiss="modal">Close</button>
						</div>
					</form>
				</div>
			</div>
		</div>
	</div>
	<!-- End of Add Post Modal -->

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
	<script
		src="https://cdnjs.cloudflare.com/ajax/libs/sweetalert/2.1.2/sweetalert.min.js"
		integrity="sha512-AA1Bzp5Q0K1KanKKmvN/4d3IRKVlv9PYgwFPvm32nPO6QS8yH1HO7LbgB1pgiOxPtfeg5zEn2ba64MUcqJx6CA=="
		crossorigin="anonymous" referrerpolicy="no-referrer"></script>
	<script type="text/javascript">
		$(document).ready(function() {
			let editStatus = false;
			$('#edit-profile-button').click(function() {
				if (editStatus == false) {
					$('#profile-details').hide();
					$('#profile-edit').show();
					editStatus = true;
					$(this).text("Back");
				} else {
					$('#profile-details').show();
					$('#profile-edit').hide();
					editStatus = false;
					$(this).text("Edit");
				}
			})
		});
	</script>

	<!-- Add Post JS -->
	<script type="text/javascript">
		$(document).ready(function(e) {
			// Forward Data via Ajax
			$("#addpost-form").on("submit", function(event) {
				// This code gets executed when we submit add post form
				event.preventDefault();
				let form = new FormData(this);

				// Now requesting to AddPost
				$.ajax({
					url : "AddPostServlet",
					type : "POST",
					data : form,
					success : function(data, textStatus, jqXHR) {
						// success
						if(data.trim() === "success"){
							swal("Good job!", "Your Post Submitted Successfully!", "success").then((value) => {
									window.location = "profile.jsp"
							});
						}
						else{
							swal("Sorry !!!", "Something went wrong, try again", "error");
						}
					},
					error : function(jqXHR, textStatus, errorThrown) {
						// Error
						swal("Sorry !!!", "Something went wrong, try again", "error");
					},
					processData : false,
					contentType : false
				})

			})
		})
	</script>
	<!-- Edit User Details JS -->
	<script type="text/javascript">
		$(document).ready(function(e) {
			// Forward Data via Ajax
			$("#editform").on("submit", function(event) {
				// This code gets executed when we submit add post form
				event.preventDefault();
				let form = new FormData(this);

				// Now requesting to AddPost
				$.ajax({
					url : "EditServlet",
					type : "POST",
					data : form,
					success : function(data, textStatus, jqXHR) {
						// success
						console.log(data.trim());
						if(data.trim() === "success"){
							swal("Good job!", "Your Profile Updated Successfully!", "success").then((value) => {
									window.location = "profile.jsp"
							});
						}
						else{
							swal("Sorry !!!", "Something went wrong, try again", "error");
						}
					},
					error : function(jqXHR, textStatus, errorThrown) {
						// Error
						swal("Sorry !!!", "Something went wrong, try again", "error");
					},
					processData : false,
					contentType : false
				})

			})
		})
	</script>

	<!-- Loading Post Using Ajax -->
	<script type="text/javascript">
		function getPosts(categoryId, activelink){
			$("#loader").show();
			$("#postcontainer").hide();
			$(".cat-link").removeClass('active');
			
			$.ajax({
				url: "loadposts.jsp",
				data: {cid:categoryId},
				success: function(data, textStatus, jqXHR){
					$("#loader").hide();
					$("#postcontainer").show();
					$("#postcontainer").html(data);
					$(activelink).addClass('active');
				}
			})
		}
	
		$(document).ready(function(f){
			let allPostRefs = $('.cat-link')[0];
			getPosts(0, allPostRefs);
		})
	</script>
</body>
</html>