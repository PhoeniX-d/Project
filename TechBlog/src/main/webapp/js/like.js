/**
 * 
 */
function doLike(pid, uid) {
	const likeObject = {
		postid : pid,
		userid : uid,
		operation : 'like'
	}

	$.ajax({
		url : "LikeServlet",
		data : likeObject,
		type : 'POST',
		success : function(data, textStatus, jqXHR) {
			if (data.trim() === 'success') {
				let counter = $('.like-counter-' + pid).html();
				counter++;
				$('.like-counter-' + pid).html(" " + counter);
			}
		},
		error : function(jqXHR, textStatus, errorThrown) {
		}
	})
}