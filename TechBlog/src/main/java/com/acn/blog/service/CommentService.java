package com.acn.blog.service;

import java.util.List;

import com.acn.blog.beans.CommentBean;

public interface CommentService {
	Integer addComments(CommentBean commentBean) throws Exception;

	Integer countCommentsOnPost(Integer pid) throws Exception;

	Boolean isPostCommentedByUser(Integer pid, Integer uid) throws Exception;

	Boolean deleteComment(Integer pid, Integer uid) throws Exception;

	List<CommentBean> getAllCommentsOnPost(Integer pid) throws Exception;
}
