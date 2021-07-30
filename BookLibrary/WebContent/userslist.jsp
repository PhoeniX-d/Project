<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>

<!doctype html>
<html lang="en">

<head>
<meta charset="utf-8">
<meta name="viewport"
	content="width=device-width, initial-scale=1, shrink-to-fit=no">
<link rel="stylesheet"
	href="https://cdn.jsdelivr.net/npm/bootstrap@4.6.0/dist/css/bootstrap.min.css">

<link rel="stylesheet"
	href="https://cdn.datatables.net/1.10.25/css/dataTables.bootstrap4.min.css">

<script src="https://code.jquery.com/jquery-3.6.0.js"></script>

<script
	src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/2.9.2/umd/popper.min.js"></script>

<script
	src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.min.js"></script>

<script
	src="https://cdn.datatables.net/1.10.25/js/jquery.dataTables.min.js"></script>

<script
	src="https://cdn.datatables.net/1.10.25/js/dataTables.bootstrap4.min.js"></script>

<title>Users</title>
</head>

<body>
	<nav class="navbar navbar-expand-lg navbar-dark bg-dark">
		<span class="navbar-brand mb-0 h1">List of Users</span>
		<button class="navbar-toggler" type="button" data-toggle="collapse"
			data-target="#navbarSupportedContent"
			aria-controls="navbarSupportedContent" aria-expanded="false"
			aria-label="Toggle navigation">
			<span class="navbar-toggler-icon"></span>
		</button>

		<div class="collapse navbar-collapse" id="navbarSupportedContent">
			<ul class="navbar-nav mr-auto"></ul>
			<div class="form-inline my-2 my-lg-0">
				<ul class="navbar-nav mr-auto"></ul>
				<a href="login.jsp" class="btn btn-outline-success my-2 my-sm-0">Login</a>
			</div>
		</div>
	</nav>
	<div class="row">
		<div class="container">
			<br>
			<table class="table table-bordered mydatatable" style="width: 100%">
				<thead>
					<tr>
						<th>Name</th>
						<th>Mail</th>
						<th>Mobile</th>
					</tr>
				</thead>
				<tbody>
					<c:forEach var="user" items="${listUsers}">
						<tr>
							<td><c:out value="${user.uName}" /></td>
							<td><c:out value="${user.uEmail}" /></td>
							<c:set var="uMob" value="${user.uMob}" />
							<c:choose>
								<c:when test="${uMob eq '-1'}">
									<td><c:out value="-" /></td>
								</c:when>
								<c:otherwise>
									<td><c:out value="${user.uMob}" /></td>
								</c:otherwise>
							</c:choose>
						</tr>
					</c:forEach>
				</tbody>
				<tfoot>
					<tr>
						<th>Name</th>
						<th>Mail</th>
						<th>Mobile</th>
					</tr>
				</tfoot>
			</table>
		</div>
	</div>
	<script type="text/javascript">
		$('.mydatatable').DataTable({
			pagingType : 'full_numbers',
			lengthMenu : [ [ 5, 10, 15, -1 ], [ 5, 10, 15, "All" ] ],
			scrollY : 400,
			scrollX : true,
			scrollCollapse : true
		});
	</script>
</body>

</html>