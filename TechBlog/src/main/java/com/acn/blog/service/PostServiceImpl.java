package com.acn.blog.service;

import java.util.List;

import com.acn.blog.beans.PostBean;
import com.acn.blog.dao.PostDAO;
import com.acn.blog.utility.Factory;

public class PostServiceImpl implements PostService {

	private PostDAO postDao;

	@Override
	public Integer addPost(PostBean postBean) throws Exception {
		postDao = Factory.getPostDAO();
		return postDao.addPost(postBean);
	}

	@Override
	public List<PostBean> getAllPosts() throws Exception {
		postDao = Factory.getPostDAO();
		return postDao.getAllPosts();
	}

	@Override
	public List<PostBean> getPostsByCid(Integer cid) throws Exception {
		postDao = Factory.getPostDAO();
		return postDao.getPostsByCid(cid);
	}

	@Override
	public PostBean getPostByPid(Integer pid) throws Exception {
		postDao = Factory.getPostDAO();
		return postDao.getPostByPid(pid);
	}

}
