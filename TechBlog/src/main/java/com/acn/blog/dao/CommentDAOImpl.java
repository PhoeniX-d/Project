package com.acn.blog.dao;

import java.util.ArrayList;
import java.util.List;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.NoResultException;
import javax.persistence.Query;
import javax.persistence.TypedQuery;

import com.acn.blog.beans.CommentBean;
import com.acn.blog.entity.CommentEntity;
import com.acn.blog.utility.BlogUtility;

public class CommentDAOImpl implements CommentDAO {

	@Override
	public Integer addComments(CommentBean commentBean) throws Exception {
		Integer CommentId = null;
		EntityManager entityManager = null;
		try {
			EntityManagerFactory entityManagerFactory = BlogUtility.getEntityManagerFactory();
			entityManager = entityManagerFactory.createEntityManager();

			CommentEntity commentEntity = new CommentEntity();
			commentEntity.setCpostId(commentBean.getCpostId());
			commentEntity.setCuserId(commentBean.getCuserId());
			commentEntity.setComments(commentBean.getComments());

			entityManager.getTransaction().begin();
			entityManager.persist(commentEntity);
			entityManager.getTransaction().commit();

			CommentId = commentEntity.getCid();

		} catch (Exception exception) {
			throw exception;
		} finally {
			if (entityManager != null) {
				entityManager.close();
			}
		}
		return CommentId;
	}

	@Override
	public Integer countCommentsOnPost(Integer pid) throws Exception {
		Integer CommentsCount = null;
		EntityManager entityManager = null;
		try {
			EntityManagerFactory entityManagerFactory = BlogUtility.getEntityManagerFactory();
			entityManager = entityManagerFactory.createEntityManager();
			Query query = entityManager.createQuery("SELECT COUNT(*) FROM CommentEntity c WHERE c.cpostId = ?1");
			query.setParameter(1, pid);
			try {
				Object object = query.getSingleResult();
				CommentsCount = ((Long) object).intValue();
			} catch (NoResultException nre) {
			}
		} catch (Exception exception) {
			throw exception;
		} finally {
			if (entityManager != null) {
				entityManager.close();
			}
		}
		return CommentsCount;
	}

	@Override
	public Boolean isPostCommentedByUser(Integer pid, Integer uid) throws Exception {
		Boolean isPostCommentdByUser = false;
		EntityManager entityManager = null;
		try {
			EntityManagerFactory entityManagerFactory = BlogUtility.getEntityManagerFactory();
			entityManager = entityManagerFactory.createEntityManager();
			TypedQuery<CommentEntity> query = entityManager.createQuery(
					"SELECT c FROM CommentEntity c WHERE c.cpostId = ?1 AND c.cuserId = ?2", CommentEntity.class);
			query.setParameter(1, pid);
			query.setParameter(2, uid);
			try {
				CommentEntity commentEntity = query.getSingleResult();
				if (commentEntity != null) {
					isPostCommentdByUser = true;
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
		return isPostCommentdByUser;
	}

	@Override
	public Boolean deleteComment(Integer pid, Integer uid) throws Exception {
		Boolean isCommentDeleted = false;
		EntityManager entityManager = null;
		try {
			EntityManagerFactory entityManagerFactory = BlogUtility.getEntityManagerFactory();
			entityManager = entityManagerFactory.createEntityManager();
			TypedQuery<CommentEntity> query = entityManager.createQuery(
					"DELETE FROM CommentEntity c WHERE c.cpostId = ?1 AND c.cuserId = ?2", CommentEntity.class);
			query.setParameter(1, pid);
			query.setParameter(2, uid);
			try {
				Integer count = query.executeUpdate();
				if (count != 0)
					isCommentDeleted = true;
			} catch (NoResultException nre) {
			}
		} catch (Exception exception) {
			throw exception;
		} finally {
			if (entityManager != null) {
				entityManager.close();
			}
		}
		return isCommentDeleted;
	}

	@Override
	public List<CommentBean> getAllCommentsOnPost(Integer pid) throws Exception {
		List<CommentBean> commentBeans = null;
		List<CommentEntity> commentEntities = null;
		EntityManager entityManager = null;
		try {
			EntityManagerFactory entityManagerFactory = BlogUtility.getEntityManagerFactory();
			entityManager = entityManagerFactory.createEntityManager();
			TypedQuery<CommentEntity> query = entityManager
					.createQuery("SELECT c FROM CommentEntity c WHERE c.cpostId = ?1", CommentEntity.class);
			query.setParameter(1, pid);
			try {
				commentEntities = query.getResultList();
				commentBeans = new ArrayList<CommentBean>();
				for (CommentEntity commentEntity : commentEntities) {
					CommentBean commentBean = new CommentBean();
					commentBean.setCid(commentEntity.getCid());
					commentBean.setCuserId(commentEntity.getCuserId());
					commentBean.setCpostId(commentEntity.getCpostId());
					commentBean.setComments(commentEntity.getComments());
					commentBean.setTimeStamp(commentEntity.getTimeStamp());
					commentBeans.add(commentBean);
				}
			} catch (NoResultException nre) {

			}

		} catch (Exception exception) {
			throw exception;
		}

		return commentBeans;
	}

}
