package com.acn.blog.dao;

import java.util.List;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.NoResultException;
import javax.persistence.TypedQuery;

import com.acn.blog.beans.UserBean;
import com.acn.blog.entity.UserEntity;
import com.acn.blog.utility.BlogUtility;

public class UserDAOImpl implements UserDAO {

	public Integer insertUser(UserBean userBean) throws Exception {
		Integer userId = null;
		EntityManager entityManager = null;
		try {
			EntityManagerFactory entityManagerFactory = BlogUtility.getEntityManagerFactory();
			entityManager = entityManagerFactory.createEntityManager();

			// populating userEntity object for userEntity
			UserEntity userEntity = new UserEntity();
			userEntity.setName(userBean.getName());
			userEntity.setGender(userBean.getGender());
			userEntity.setEmail(userBean.getEmail());
			userEntity.setPassword(userBean.getPassword());
			userEntity.setMobileno(userBean.getMobileno());
			if (userBean.getProfile() != null) {
				userEntity.setProfile(userBean.getProfile());
			}

			// begin
			entityManager.getTransaction().begin();
			// persist
			entityManager.persist(userEntity);
			// commit
			entityManager.getTransaction().commit();

			userId = userEntity.getId();
		} catch (Exception exception) {
			throw exception;
		} finally {
			if (entityManager != null) {
				entityManager.close();
			}
		}
		return userId;
	}

	public List<UserBean> getAllUsers() throws Exception {

		return null;
	}

	public Boolean deleteUser(Integer userId) throws Exception {

		return null;
	}

	public Boolean updateUser(UserBean bean) throws Exception {

		return null;
	}

	public UserBean getUserByEmailAndPassword(String email, String password) throws Exception {
		UserBean userBean = null;
		UserEntity userEntity = null;
		EntityManager entityManager = null;
		try {
			EntityManagerFactory entityManagerFactory = BlogUtility.getEntityManagerFactory();
			entityManager = entityManagerFactory.createEntityManager();

			TypedQuery<UserEntity> query = entityManager.createQuery(
					"SELECT u FROM UserEntity u WHERE u.email=:email AND u.password=:password", UserEntity.class);
			query.setParameter("email", email);
			query.setParameter("password", password);
			try {
				Object object = query.getSingleResult();
				userEntity = (UserEntity) object;
				if (userEntity != null) {

					// Populating userEntity object for userEntity
					userBean = new UserBean();
					userBean.setId(userEntity.getId());
					userBean.setName(userEntity.getName());
					userBean.setGender(userEntity.getGender());
					userBean.setEmail(userEntity.getEmail());
					userBean.setPassword(userEntity.getPassword());
					userBean.setMobileno(userEntity.getMobileno());
					userBean.setCreateDate(userEntity.getCreateDate());
					userBean.setProfile(userEntity.getProfile());

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
		return userBean;
	}

}
