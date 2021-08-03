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

<script src="https://code.jquery.com/jquery-3.5.1.js"></script>
<script type="text/javascript"
	src="https://cdn.datatables.net/1.10.25/js/jquery.dataTables.min.js"></script>
<script type="text/javascript"
	src="//cdn.datatables.net/buttons/1.7.1/js/dataTables.buttons.min.js">
	
</script>
<script
	src="https://cdn.datatables.net/buttons/1.7.1/js/buttons.colVis.min.js"></script>

<script type="text/javascript"
	src="https://cdnjs.cloudflare.com/ajax/libs/jszip/3.1.3/jszip.min.js">
	
</script>
<script type="text/javascript"
	src="https://cdnjs.cloudflare.com/ajax/libs/pdfmake/0.1.53/pdfmake.min.js">
	
</script>
<script type="text/javascript"
	src="https://cdnjs.cloudflare.com/ajax/libs/pdfmake/0.1.53/vfs_fonts.js">
	
</script>
<script type="text/javascript"
	src="https://cdn.datatables.net/buttons/1.7.1/js/buttons.html5.min.js">
	
</script>
<script type="text/javascript"
	src="https://cdn.datatables.net/buttons/1.7.1/js/buttons.print.min.js">
	
</script>
<script type="text/javascript"
	src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/2.9.2/umd/popper.min.js"></script>

<script type="text/javascript"
	src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.min.js"></script>

<script type="text/javascript"
	src="https://cdn.datatables.net/1.10.25/js/dataTables.bootstrap4.min.js"></script>

<title>Books</title>
</head>

<body>
	<%
		response.setHeader("Cache-Control", "no-cache");
	response.setHeader("Cache-Control", "no-store");
	response.setHeader("Pragma", "no-cache");
	response.setDateHeader("Expires", 0);

	if (session.getAttribute("session_user") == null && session.getAttribute("session_pwd") == null)
		response.sendRedirect("login.jsp");
	%>
	<nav class="navbar navbar-expand-lg navbar-dark bg-dark">
		<span class="navbar-brand mb-0 h1">${message}</span>
		<button class="navbar-toggler" type="button" data-toggle="collapse"
			data-target="#navbarSupportedContent"
			aria-controls="navbarSupportedContent" aria-expanded="false"
			aria-label="Toggle navigation">
			<span class="navbar-toggler-icon"></span>
		</button>

		<div class="collapse navbar-collapse" id="navbarSupportedContent">
			<ul class="navbar-nav mr-auto">
				<li class="nav-item"><a class="nav-link"
					href="<%=request.getContextPath()%>/welcome.jsp">Home </a></li>
				<li class="nav-item active"><a
					class="btn btn-outline-secondary my-2 my-sm-0" href="#">MyBooks<span
						class="sr-only">(current)</span>
				</a></li>
			</ul>
			<div class="form-inline my-2 my-lg-0">
				<ul class="navbar-nav mr-auto">
					<li class="nav-item"><a class="nav-link"
						href="<%=request.getContextPath()%>/updateform.jsp">Edit
							Profile<span class="sr-only">(current)</span>
					</a></li>
				</ul>
				<a href="<%=request.getContextPath()%>/logout"
					class="btn btn-outline-danger my-2 my-sm-0">Logout</a>
			</div>
		</div>
	</nav>
	<div class="container">
		<br>
		<div class="container text-center">
			<a href="<%=request.getContextPath()%>/addbook.jsp"
				class="btn btn-success">Add New Book</a>
		</div>
		<br>
		<table class="table table-bordered mydatatable" style="width: 100%">
			<thead>
				<tr>
					<th>ID</th>
					<th>Name</th>
					<th>Author</th>
					<th>Category</th>
					<th>Language</th>
					<th>Price</th>
					<th>Pages</th>
					<th>Action</th>
				</tr>
			</thead>
			<tbody>
				<c:forEach var="book" items="${listBooks}">
					<tr>
						<td><c:out value="${book.bId}" /></td>
						<td><c:out value="${book.bName}" /></td>
						<td><c:out value="${book.bAuthor}" /></td>
						<td><c:out value="${book.bCategory}" /></td>
						<td><c:out value="${book.bLang}" /></td>
						<c:set var="bPrice" value="${book.bPrice}" />
						<c:choose>
							<c:when test="${bPrice eq '-1'}">
								<td><c:out value="-" /></td>
							</c:when>
							<c:otherwise>
								<td><c:out value="${bPrice}" /></td>
							</c:otherwise>
						</c:choose>
						<c:set var="bPages" value="${book.bPageCounts}" />
						<c:choose>
							<c:when test="${bPages eq '-1'}">
								<td><c:out value="-" /></td>
							</c:when>
							<c:otherwise>
								<td><c:out value="${bPages}" /></td>
							</c:otherwise>
						</c:choose>
						<td><a href="./editBookInfo?bid=${book.bId}">Edit </a>
							&nbsp;&nbsp; <a href="./deleteBook?bid=${book.bId}">Delete</a>&nbsp;&nbsp;
							<a
							href="./viewAuthor?bid=${book.bId}&bname=${book.bName}&bauthor=${book.bAuthor}">View
								Author</a></td>
					</tr>
				</c:forEach>
			</tbody>
			<tfoot style="display:">
				<tr>
					<th>ID</th>
					<th>Name</th>
					<th>Author</th>
					<th>Category</th>
					<th>Language</th>
					<th>Price</th>
					<th>Pages</th>
					<th>Action</th>
				</tr>
			</tfoot>
		</table>
	</div>
	<script type="text/javascript">
	$(document).ready(function() {
    $('.mydatatable').DataTable( {
    	"lengthMenu" : [ [ 5, 10, 15, -1 ],[ 5, 10, 15, "All" ] ],
    	dom : "<'row'<'col-sm-3'l><'col-sm-5 text-center'B><'col-sm-4'f>>"
			+ "<'row'<'col-sm-12'rt>>"
			+ "<'row'<'col-sm-5'i><'col-sm-7'p>>",
			buttons : [ 
					{
					extend : 'excel',
					text : 'Save as Excel',
					exportOptions : {
						columns : [ 0, 1, 2, 3, 4, 5, 6 ]
					}
				}, {
					extend : 'pdf',
					text : 'Save as PDF',
					exportOptions : {
						columns : [ 0, 1, 2, 3, 4, 5, 6 ]
					}
				}, ],
    	scrollX : 400,
    	scrollY : true,
        initComplete: function () {
            this.api().columns(4).every( function () {
                var column = this;
                	var select = $('<select><option value="">Language</option></select>')
                    .appendTo( $(column.header()).empty() )
                    .on( 'change', function () {
                        var val = $.fn.dataTable.util.escapeRegex(
                            $(this).val()
                        );
 
                        column
                            .search( val ? '^'+val+'$' : '', true, false )
                            .draw();
                    } );
 
                column.data().unique().sort().each( function ( d, j ) {
                    select.append( '<option value="'+d+'">'+d+'</option>' )
                } );
            } );
        }
    } );
} );
	</script>
</body>

</html>