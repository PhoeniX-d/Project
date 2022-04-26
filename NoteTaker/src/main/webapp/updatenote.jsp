<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>
<%@ page
	import="com.acn.todo.bean.NoteBean,com.acn.todo.service.NoteService,com.acn.todo.utility.*,java.util.List"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Update Note</title>
<%@include file="all_jspcss.jsp"%>
</head>
<body>
	<div class="container">
		<%@include file="navbar.jsp"%>
		<br>
		<h1 class="text-uppercase">Update Page :</h1>
		<br>
		<%
			Integer noteId = null;
			NoteBean note = null;
			NoteService service = Factory.getNoteService();
			try {
				noteId = Integer.parseInt(request.getParameter("noteid").trim());
				note = service.getNoteById(noteId);

			} catch (Exception e) {
				e.printStackTrace();
			}
			if (note != null) {
		%>

		<!-- This is form to add notes -->
		<form action="UpdateServlet" method="POST">
			<input value="<%=note.getId()%>" name="noteid" type="hidden" />
			<div class="form-group">
				<h5>
					<label for="title">Add Title</label>
				</h5>
				<input type="text" name="title" class="form-control" id="title"
					placeholder="Enter Title" value="<%=note.getTitle()%>" required>
			</div>

			<div class="form-group">
				<h5>
					<label for="content">Add Content</label>
				</h5>
				<textarea id="content" name="content" placeholder="Add Content"
					class="form-control" style="height: 300px;" required><%=note.getContent()%></textarea>
			</div>
			<div class="container text-center">
				<button type="submit" class="btn btn-success">Save Note</button>
			</div>
		</form>
		<%
			}
		%>
	</div>
</body>
</html>