<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>
<%@ page
	import="com.acn.blog.beans.*, com.acn.blog.service.*, com.acn.blog.utility.*, java.util.List"%>
<!-- Cards  -->
<div class="row">
	<%
		UserBean userBean = (UserBean) session.getAttribute("currentuser");
		if (userBean == null) {
			response.sendRedirect("login.jsp");
		}
		LikeService likeService = Factory.getLikeService();
		PostService postservice = Factory.getPostService();
		CommentService commentService = Factory.getCommentService();
		Integer cid = Integer.parseInt(request.getParameter("cid"));
		List<PostBean> postBeans = null;
		if (cid == 0) {
			postBeans = postservice.getAllPosts();
		} else {
			postBeans = postservice.getPostsByCid(cid);
		}
		if (postBeans.size() == 0) {
			out.print("<h6 class='display-6 text-center text-info' >No posts available!!!</h6>");
		}
		for (PostBean postBean : postBeans) {
	%>
	<div class="col-md-6 mb-3">
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
				<a href="postdetails.jsp?pid=<%=pid%>"
					class="btn btn-sm btn-outline-info text-white">Read More..</a> <a
					href="#" onClick="doLike(<%=pid%>, <%=userBean.getId()%>)"
					class="btn btn-sm btn-outline-info text-white"> <i
					class="fa fa-thumbs-o-up"></i><span class="like-counter-<%=pid%>">
						<%=likeService.countLikesOnPost(pid)%></span>
				</a>
				<button type="button"
					class="btn btn-sm btn-outline-info  text-white" id="commentbtn">
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