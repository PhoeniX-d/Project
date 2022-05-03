package com.acn.blog.dao;

import java.util.ArrayList;
import java.util.List;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.NoResultException;
import javax.persistence.TypedQuery;

import com.acn.blog.beans.CategoryBean;
import com.acn.blog.entity.CategoryEntity;
import com.acn.blog.utility.BlogUtility;

public class CategoryDAOImpl implements CategoryDAO {

	@Override
	public List<CategoryBean> getAllCategories() throws Exception {
		List<CategoryBean> categoryBeans = null;
		List<CategoryEntity> categoryEntities = null;
		EntityManager entityManager = null;
		try {
			EntityManagerFactory entityManagerFactory = BlogUtility.getEntityManagerFactory();
			entityManager = entityManagerFactory.createEntityManager();
			TypedQuery<CategoryEntity> query = entityManager.createQuery("SELECT c FROM CategoryEntity c",
					CategoryEntity.class);
			try {
				categoryEntities = query.getResultList();
				categoryBeans = new ArrayList<CategoryBean>();
				for (CategoryEntity categoryEntity : categoryEntities) {
					CategoryBean categoryBean = new CategoryBean();
					categoryBean.setCid(categoryEntity.getCid());
					categoryBean.setCname(categoryEntity.getCname());
					categoryBean.setCdescription(categoryEntity.getCdescription());	
					categoryBeans.add(categoryBean);
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

		return categoryBeans;
	}

}
