package com.acn.blog.dao;

import com.acn.blog.beans.LikeBean;

public interface LikeDAO {
	Integer addLikes(LikeBean likeBean) throws Exception;

	Integer countLikesOnPost(Integer pid) throws Exception;

	Boolean isPostLikedByUser(Integer pid, Integer uid) throws Exception;

	Boolean deleteLike(Integer pid, Integer uid) throws Exception;
}
