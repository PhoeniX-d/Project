package com.acn.blog.dao;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.NoResultException;
import javax.persistence.Query;
import javax.persistence.TypedQuery;

import com.acn.blog.beans.LikeBean;
import com.acn.blog.entity.LikeEntity;
import com.acn.blog.utility.BlogUtility;

public class LikeDAOImpl implements LikeDAO {

	@Override
	public Integer addLikes(LikeBean likeBean) throws Exception {
		Integer likeId = null;
		EntityManager entityManager = null;
		try {
			EntityManagerFactory entityManagerFactory = BlogUtility.getEntityManagerFactory();
			entityManager = entityManagerFactory.createEntityManager();

			LikeEntity likeEntity = new LikeEntity();
			likeEntity.setPostId(likeBean.getPostId());
			likeEntity.setUserId(likeBean.getUserId());

			entityManager.getTransaction().begin();
			entityManager.persist(likeEntity);
			entityManager.getTransaction().commit();

			likeId = likeEntity.getLikeId();

		} catch (Exception exception) {
			throw exception;
		} finally {
			if (entityManager != null) {
				entityManager.close();
			}
		}
		return likeId;
	}

	@Override
	public Integer countLikesOnPost(Integer pid) throws Exception {
		Integer likesCount = null;
		EntityManager entityManager = null;
		try {
			EntityManagerFactory entityManagerFactory = BlogUtility.getEntityManagerFactory();
			entityManager = entityManagerFactory.createEntityManager();
			Query query = entityManager.createQuery("SELECT COUNT(*) FROM LikeEntity l WHERE l.postId = ?1");
			query.setParameter(1, pid);
			try {
				Object object = query.getSingleResult();
				likesCount = ((Long) object).intValue();
			} catch (NoResultException nre) {
			}
		} catch (Exception exception) {
			throw exception;
		} finally {
			if (entityManager != null) {
				entityManager.close();
			}
		}
		return likesCount;
	}

	@Override
	public Boolean isPostLikedByUser(Integer pid, Integer uid) throws Exception {
		Boolean isPostLikedByUser = false;
		EntityManager entityManager = null;
		try {
			EntityManagerFactory entityManagerFactory = BlogUtility.getEntityManagerFactory();
			entityManager = entityManagerFactory.createEntityManager();
			TypedQuery<LikeEntity> query = entityManager
					.createQuery("SELECT l FROM LikeEntity l WHERE l.postId = ?1 AND l.userId = ?2", LikeEntity.class);
			query.setParameter(1, pid);
			query.setParameter(2, uid);
			try {
				LikeEntity likeEntity = query.getSingleResult();
				if (likeEntity != null) {
					isPostLikedByUser = true;
				}
			} catch (NoResultException nre) {
			}
		} catch (Exception exception) {
			throw exception;
		} finally {
			if (entityManager != null) {
				entityManager.close();
			}
		}
		return isPostLikedByUser;
	}

	@Override
	public Boolean deleteLike(Integer pid, Integer uid) throws Exception {
		Boolean isLikeDeleted = false;
		EntityManager entityManager = null;
		try {
			EntityManagerFactory entityManagerFactory = BlogUtility.getEntityManagerFactory();
			entityManager = entityManagerFactory.createEntityManager();
			TypedQuery<LikeEntity> query = entityManager
					.createQuery("DELETE FROM LikeEntity l WHERE l.postId = ?1 AND l.userId = ?2", LikeEntity.class);
			query.setParameter(1, pid);
			query.setParameter(2, uid);
			try {
				Integer count = query.executeUpdate();
				if (count != 0)
					isLikeDeleted = true;
			} catch (NoResultException nre) {
			}
		} catch (Exception exception) {
			throw exception;
		} finally {
			if (entityManager != null) {
				entityManager.close();
			}
		}
		return isLikeDeleted;
	}

}
