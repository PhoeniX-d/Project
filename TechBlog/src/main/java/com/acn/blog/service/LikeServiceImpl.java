package com.acn.blog.service;

import com.acn.blog.beans.LikeBean;
import com.acn.blog.dao.LikeDAO;
import com.acn.blog.utility.Factory;

public class LikeServiceImpl implements LikeService {

	LikeDAO likeDao = null;

	@Override
	public Integer addLikes(LikeBean likeBean) throws Exception {
		likeDao = Factory.getLikeDAO();
		return likeDao.addLikes(likeBean);
	}

	@Override
	public Integer countLikesOnPost(Integer pid) throws Exception {
		likeDao = Factory.getLikeDAO();
		return likeDao.countLikesOnPost(pid);
	}

	@Override
	public Boolean isPostLikedByUser(Integer pid, Integer uid) throws Exception {
		likeDao = Factory.getLikeDAO();
		return likeDao.isPostLikedByUser(pid, uid);
	}

	@Override
	public Boolean deleteLike(Integer pid, Integer uid) throws Exception {
		likeDao = Factory.getLikeDAO();
		return likeDao.deleteLike(pid, uid);
	}

}
