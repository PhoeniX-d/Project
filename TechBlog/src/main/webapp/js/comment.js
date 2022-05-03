/**
 * 
 */
function doComment(pid, uid) {
	let comment = document.getElementById("comments").value;
	const commentObject = {
		postid : pid,
		userid : uid,
		comments : comment,
		operation : 'comment'
	}
	$.ajax({
		url : "CommentServlet",
		data : commentObject,
		type : 'POST',
		success : function(data, textStatus, jqXHR) {
			if (data.trim() === 'success') {
				let counter = $('.comment-counter-' + pid).html();
				counter++;
				$('.comment-counter-' + pid).html(" " + counter);
			}
		},
		error : function(jqXHR, textStatus, errorThrown) {
		}
	})
}
