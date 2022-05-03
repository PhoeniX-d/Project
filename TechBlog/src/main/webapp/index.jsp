<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>
<%@ page
	import="com.acn.blog.beans.*, com.acn.blog.service.*, com.acn.blog.utility.*, java.util.List"%>
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
<link rel="stylesheet"
	href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
<link href="css/mystyle.css" rel="stylesheet" type="text/css">
<style>
.banner-background {
	clip-path: polygon(30% 0%, 70% 0%, 100% 0, 100% 90%, 74% 100%, 43% 92%, 0 100%, 0 0
		);
}
</style>
</head>
<body>

	<!-- Navbar -->
	<%@include file="general_navbar.jsp"%>

	<!-- Banner -->
	<div class="container-fluid p-0 m-0 banner-background">
		<div class="jumbotron primary-background text-white">
			<div class="container" style="padding: 1.5%">
				<h3 class="display-4">Welcome to Technical Blog</h3>
				<p>A technical blogger is a content writer that focuses on
					delivering high-quality articles that engages their audience and
					brings traffic to their business' website. They often write about
					topics that their target audience are interested about and provide
					value from their background technical knowledge or with a little
					research.
				<p>This blog contains posts various categories which you will
					find helpful</p>
				<a href="login.jsp" class="btn btn-outline-light"> <span
					class="fa fa-external-link-square"></span> Start Reading
				</a>
			</div>
		</div>
	</div>

	<!-- Cards  -->
	<div class="container-fluid" style="padding: 5%;">
		<div class="row">
			<%
				LikeService likeService = Factory.getLikeService();
				PostService postservice = Factory.getPostService();
				CommentService commentService = Factory.getCommentService();
				;
				List<PostBean> postBeans = null;
				postBeans = postservice.getAllPosts();
				if (postBeans.size() == 0) {
					out.print("<h6 class='display-6 text-center text-info'>No posts available!!!</h6>");
				}
				for (PostBean postBean : postBeans) {
			%>
			<div class="col-md-4 mb-3">
				<div class="card">
					<%
						Integer pid = postBean.getPid();
					%>
					<div class="text-center">
						<img src="blogpics/<%=postBean.getPic()%>" class="card-img-top"
							class="img-fluid"
							style="width: 100%; max-width: 150px; border-radius: 25%; padding: 1%;"
							onerror="this.onerror=null; this.src='blogpics/default.png'">
					</div>
					<div class="card-body">
						<b class="card-title text-primary"><%=postBean.getTitle()%></b>
						<p class="card-text"><%=postBean.getContent()%></p>
					</div>
					<div class="card-footer text-end text-end primary-background">
						<a href="login.jsp" class="btn btn-sm btn-outline-info text-white">Read
							More..</a> <a href="#!"
							class="btn btn-sm btn-outline-info text-white"
							data-toggle="tooltip" data-placement="bottom" title="Total Likes"><i
							class="fa fa-thumbs-o-up"></i><span class="like-counter-<%=pid%>">
								<%=likeService.countLikesOnPost(pid)%>
						</span></a>
						<button type="button"
							class="btn btn-sm btn-outline-info  text-white" id="commentbtn"
							data-toggle="tooltip" data-placement="bottom"
							title="Total Comments">
							<i class="fa fa-comments"></i><span
								class="comment-counter-<%=pid%>"> <%=commentService.countCommentsOnPost(pid)%></span>
						</button>
					</div>
				</div>
			</div>
			<%
				}
			%>
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
</body>
</html>
