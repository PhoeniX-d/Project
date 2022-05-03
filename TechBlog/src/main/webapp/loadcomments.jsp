<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>
<%@ page
	import="com.acn.blog.beans.*, com.acn.blog.service.*, com.acn.blog.utility.*, java.util.List , java.text.DateFormat"%>
<div class="row">
	<div class="container mt-2">
		<p style="font-weight: bold; font-style: italic;">Recent Comments</p>
	</div>

	<%
		UserBean currUser = (UserBean) session.getAttribute("currentuser");
		if (currUser == null) {
			response.sendRedirect("login.jsp");
		}
		CommentService commentService = Factory.getCommentService();
		UserService userService = Factory.getUserService();
		Integer pid = Integer.parseInt(request.getParameter("pid"));
		List<CommentBean> commentBeans = commentService.getAllCommentsOnPost(pid);
		for (CommentBean commentBean : commentBeans) {
	%>
	<div class="col-sm-12 mb-2">
		<div class="card my-2 border border-info border-1">
			<div class="row g-0">
				<div class="col-md-4">
					<%
						UserBean userBean = userService.getUserById(commentBean.getCuserId());
					%>
					<div class="container-fluid text-center">
						<img src="profiles/<%=userBean.getProfile()%>"
							class="img-fluid my-4"
							style="width: 100%; max-width: 75px; border-radius: 50%;"
							onerror="this.onerror=null; this.src='profiles/default.png'">
					</div>
				</div>
				<div class="col-md-8">
					<div class="card-body">
						<p class="card-title text-primary">
							<%=userBean.getName()%></p>
						<p class="card-text"><%=commentBean.getComments()%></p>
						<p class="card-text">
							<small class="text-muted"><%=DateFormat.getDateTimeInstance().format(commentBean.getTimeStamp())%></small>
						</p>
					</div>
				</div>
			</div>
		</div>
		<%
			}
		%>
	</div>
</div>