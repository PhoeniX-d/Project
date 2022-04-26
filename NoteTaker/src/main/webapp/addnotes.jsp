<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Add Notes</title>
<%@include file="all_jspcss.jsp"%>
</head>
<body>
	<div class="container">
		<%@include file="navbar.jsp"%>
		<br>
		<h1 class="text-uppercase">Add some note :</h1>
		<br>
		<!-- This is form to add notes -->
		<form action="SaveNoteServlet" method="POST">
			<div class="form-group">
				<h5><label for="title">Add Title</label></h5>
				<input 
				type="text" 
				name="title"
				class="form-control" 
				id="title" 
				placeholder="Enter Title" 
				required>
			</div>

			<div class="form-group">
				<h5><label for="content">Add Content</label></h5>
				<textarea 
				id="content" 
				name="content" 
				placeholder="Add Content"
				class="form-control" 
				style="height: 300px;" 
				required></textarea>
			</div>
			<div class="container text-center">
				<button type="submit" class="btn btn-primary">Add</button>
			</div>
		</form>
	</div>
</body>
</html>