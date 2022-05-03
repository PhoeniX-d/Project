package com.acn.blog.dao;

import java.util.ArrayList;
import java.util.List;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.NoResultException;
import javax.persistence.TypedQuery;

import com.acn.blog.beans.PostBean;
import com.acn.blog.entity.PostEntity;
import com.acn.blog.utility.BlogUtility;

public class PostDAOImpl implements PostDAO {

	@Override
	public Integer addPost(PostBean postBean) throws Exception {
		Integer postId = null;
		EntityManager entityManager = null;
		try {
			EntityManagerFactory entityManagerFactory = BlogUtility.getEntityManagerFactory();
			entityManager = entityManagerFactory.createEntityManager();
			PostEntity postEntity = new PostEntity();

			// Populate data
			postEntity.setCid(postBean.getCid());
			postEntity.setCode(postBean.getCode());
			postEntity.setContent(postBean.getContent());
			postEntity.setPic(postBean.getPic());
			postEntity.setTitle(postBean.getTitle());
			postEntity.setUid(postBean.getUid());

			// begin
			entityManager.getTransaction().begin();
			// persist
			entityManager.persist(postEntity);
			// commit
			entityManager.getTransaction().commit();

			postId = postEntity.getPid();

		} catch (Exception exception) {
			throw exception;
		} finally {
			if (entityManager != null) {
				entityManager.close();
			}
		}
		return postId;
	}

	@Override
	public List<PostBean> getAllPosts() throws Exception {
		List<PostBean> postBeans = null;
		List<PostEntity> postEntities = null;
		EntityManager entityManager = null;
		try {
			EntityManagerFactory entityManagerFactory = BlogUtility.getEntityManagerFactory();
			entityManager = entityManagerFactory.createEntityManager();
			TypedQuery<PostEntity> query = entityManager.createQuery("SELECT p FROM PostEntity p ORDER BY p.pid DESC",
					PostEntity.class);
			try {
				postEntities = query.getResultList();
				postBeans = new ArrayList<PostBean>();
				for (PostEntity postEntity : postEntities) {
					PostBean postBean = convertEntityToBean(postEntity);
					postBeans.add(postBean);
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

		return postBeans;
	}

	@Override
	public List<PostBean> getPostsByCid(Integer cid) throws Exception {
		List<PostBean> postBeans = null;
		List<PostEntity> postEntities = null;
		EntityManager entityManager = null;
		try {
			EntityManagerFactory entityManagerFactory = BlogUtility.getEntityManagerFactory();
			entityManager = entityManagerFactory.createEntityManager();
			TypedQuery<PostEntity> query = entityManager
					.createQuery("SELECT p FROM PostEntity p WHERE p.cid = ?1 ORDER BY p.pid DESC", PostEntity.class);
			query.setParameter(1, cid);
			try {
				postEntities = query.getResultList();
				postBeans = new ArrayList<PostBean>();
				for (PostEntity postEntity : postEntities) {
					PostBean postBean = convertEntityToBean(postEntity);
					postBeans.add(postBean);
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

		return postBeans;
	}

	private PostBean convertEntityToBean(PostEntity postEntity) {
		PostBean postBean = new PostBean();
		postBean.setCid(postEntity.getCid());
		postBean.setCode(postEntity.getCode());
		postBean.setContent(postEntity.getContent());
		postBean.setPid(postEntity.getPid());
		postBean.setUid(postEntity.getUid());
		postBean.setPic(postEntity.getPic());
		postBean.setTitle(postEntity.getTitle());
		postBean.setPostedDate(postEntity.getPostedDate());
		return postBean;
	}

	@Override
	public PostBean getPostByPid(Integer pid) throws Exception {
		PostBean postBean = null;
		EntityManager entityManager = null;
		try {
			EntityManagerFactory entityManagerFactory = BlogUtility.getEntityManagerFactory();
			entityManager = entityManagerFactory.createEntityManager();
			TypedQuery<PostEntity> query = entityManager.createQuery("SELECT p FROM PostEntity p WHERE p.pid = ?1",
					PostEntity.class);
			query.setParameter(1, pid);
			try {
				PostEntity postEntity = query.getSingleResult();
				postBean = convertEntityToBean(postEntity);
			} catch (NoResultException nre) {
			}
		} catch (Exception exception) {
			throw exception;
		} finally {
			if (entityManager != null) {
				entityManager.close();
			}
		}
		return postBean;
	}
}
