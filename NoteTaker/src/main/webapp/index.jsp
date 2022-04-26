<!doctype html>
<html lang="en">
<head>
<!-- Required meta tags -->
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">

<!-- Bootstrap CSS -->
<%@include file="all_jspcss.jsp"%>
<title>Note-Taker Home</title>
</head>
<body>

	<div class="container">
		<%@include file="navbar.jsp"%>
	</div>

	<div class="card py-5 m-4 mx-auto">
		<img alt="" class="img-fluid mx-auto m-10" style="max-width: 500px;"
			src="img/notes.png">
		<h1 class="text-primary text-uppercase text-center mt-3">
			<b>start taking your notes</b>
		</h1>
		<div class="container text-center">
			<a href="addnotes.jsp"><button
					class="btn btn-outline-primary text center">Take Note</button></a>

		</div>
	</div>

</body>
</html>