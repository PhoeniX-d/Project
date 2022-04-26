<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>
<%@ page
	import="com.acn.todo.bean.NoteBean, com.acn.todo.service.NoteService, com.acn.todo.utility.*, java.util.List"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/fmt" prefix="fmt"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Show All Notes</title>
<%@include file="all_jspcss.jsp"%>
</head>
<body>
	<div class="container">
		<%@include file="navbar.jsp"%>
		<br>
		<h1 class="text-uppercase">All Notes :</h1>
		<br>

		<div class="row">
			<div class="col-12"></div>
		</div>
		<%
			NoteService service = Factory.getNoteService();
			List<NoteBean> notes = null;
			try {
				notes = service.getNotes();
			} catch (Exception e) {
				e.printStackTrace();
			}
			if (notes != null) {
				for (NoteBean note : notes) {
		%>
		<div class="card mt-3">
			<img class="card-img-top m-4 mx-auto" style="max-width: 75px;"
				alt="note_image" src="img/notes.png">
			<div class="card-body px-5">
				<h4 class="card-title">
					<b> <%=note.getTitle()%></b>
				</h4>
				<h6 class="card-subtitle mb-2 text-primary">
					<b> <fmt:formatDate pattern="dd-MMM-yyyy"
							value="<%=note.getAddedDate()%>" />
					</b>
				</h6>
				<p class="card-text">
					<%=note.getContent()%>
				</p>
				<div class="container text-center mt-2">
					<a href="DeleteServlet?noteid=<%=note.getId()%>"
						class="btn btn-danger">Delete</a> <a
						href="updatenote.jsp?noteid=<%=note.getId()%>"
						class="btn btn-primary">Update</a>
				</div>
			</div>
		</div>
		<%
			}
			}
		%>
	</div>
</body>
</html>