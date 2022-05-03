package com.acn.blog.service;

import java.util.List;

import com.acn.blog.beans.CommentBean;
import com.acn.blog.dao.CommentDAO;
import com.acn.blog.utility.Factory;

public class CommentServiceImpl implements CommentService {

	private CommentDAO commentDao;

	@Override
	public Integer addComments(CommentBean commentBean) throws Exception {
		commentDao = Factory.getCommentDAO();
		return commentDao.addComments(commentBean);
	}

	@Override
	public Integer countCommentsOnPost(Integer pid) throws Exception {
		commentDao = Factory.getCommentDAO();
		return commentDao.countCommentsOnPost(pid);
	}

	@Override
	public Boolean isPostCommentedByUser(Integer pid, Integer uid) throws Exception {
		commentDao = Factory.getCommentDAO();
		return commentDao.isPostCommentedByUser(pid, uid);
	}

	@Override
	public Boolean deleteComment(Integer pid, Integer uid) throws Exception {
		commentDao = Factory.getCommentDAO();
		return commentDao.deleteComment(pid, uid);
	}

	@Override
	public List<CommentBean> getAllCommentsOnPost(Integer pid) throws Exception {
		commentDao = Factory.getCommentDAO();
		return commentDao.getAllCommentsOnPost(pid);
	}

}
