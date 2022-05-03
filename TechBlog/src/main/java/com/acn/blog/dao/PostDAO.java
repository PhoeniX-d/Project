package com.acn.blog.dao;

import java.util.List;

import com.acn.blog.beans.PostBean;

public interface PostDAO {
	Integer addPost(PostBean postBean) throws Exception;

	PostBean getPostByPid(Integer pid) throws Exception;

	List<PostBean> getAllPosts() throws Exception;

	List<PostBean> getPostsByCid(Integer cid) throws Exception;
}
