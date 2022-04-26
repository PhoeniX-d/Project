package com.acn.register.dao;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;

import com.acn.register.bean.UserBean;
import com.acn.register.entity.UserEntity;
import com.acn.register.utility.UserUtility;

public class UserDAOImpl implements UserDAO {

	public Integer addUser(UserBean user) throws Exception {
		Integer UserId = null;
		EntityManager entityManager = null;
		try {
			EntityManagerFactory entityManagerFactory = UserUtility.getEntityManagerFactory();
			entityManager = entityManagerFactory.createEntityManager();

			// populating UserEntity object for UserEntity
			UserEntity userEntity = new UserEntity();
			userEntity.setName(user.getName());
			userEntity.setPassword(user.getPassword());
			userEntity.setEmail(user.getEmail());
			userEntity.setImage(user.getImage());

			// begin
			entityManager.getTransaction().begin();
			// persist
			entityManager.persist(userEntity);
			// commit
			entityManager.getTransaction().commit();

			UserId = userEntity.getId();
		} catch (Exception exception) {
			throw exception;
		} finally {
			if (entityManager != null) {
				entityManager.close();
			}
		}
		return UserId;
	}

	// public List<UserBean> getUsers() throws Exception {
	// List<UserBean> Users = new LinkedList<UserBean>();
	// List<UserEntity> UsersEntities = null;
	// EntityManager entityManager = null;
	// try {
	// EntityManagerFactory entityManagerFactory =
	// UserTakerUtility.getEntityManagerFactory();
	// entityManager = entityManagerFactory.createEntityManager();
	// TypedQuery<UserEntity> query = entityManager.createQuery("SELECT n FROM
	// UserEntity n", UserEntity.class);
	// try {
	// UsersEntities = query.getResultList();
	// } catch (NoResultException nre) {
	// }
	// for (UserEntity UserEntity : UsersEntities) {
	// UserBean beanUser = new UserBean();
	// beanUser.setId(UserEntity.getId());
	// beanUser.setTitle(UserEntity.getTitle());
	// beanUser.setContent(UserEntity.getContent());
	// beanUser.setAddedDate(UserEntity.getAddedDate());
	// Users.add(beanUser);
	// }
	//
	// } catch (Exception exception) {
	// throw exception;
	// } finally {
	// if (entityManager != null) {
	// entityManager.close();
	// }
	// }
	// return Users;
	// }
	//
	// public void deleteUser(Integer UserId) throws Exception {
	// EntityManager entityManager = null;
	// try {
	// EntityManagerFactory entityManagerFactory =
	// UserTakerUtility.getEntityManagerFactory();
	// entityManager = entityManagerFactory.createEntityManager();
	// UserEntity UserEntity = entityManager.find(UserEntity.class, UserId);
	// if (UserEntity != null) {
	// entityManager.getTransaction().begin();
	// entityManager.remove(UserEntity);
	// entityManager.getTransaction().commit();
	// }
	// } catch (Exception exception) {
	// throw exception;
	// } finally {
	// if (entityManager != null) {
	// entityManager.close();
	// }
	// }
	// }
	//
	// public void updateUser(UserBean User) throws Exception {
	// EntityManager entityManager = null;
	// try {
	// EntityManagerFactory entityManagerFactory =
	// UserTakerUtility.getEntityManagerFactory();
	// entityManager = entityManagerFactory.createEntityManager();
	// UserEntity UserEntity = entityManager.find(UserEntity.class, User.getId());
	// if (UserEntity != null) {
	// entityManager.getTransaction().begin();
	// UserEntity.setId(User.getId());
	// UserEntity.setTitle(User.getTitle());
	// UserEntity.setContent(User.getContent());
	// UserEntity.setAddedDate(new Date());
	// entityManager.persist(UserEntity);
	// entityManager.getTransaction().commit();
	// }
	// } catch (Exception exception) {
	// throw exception;
	// } finally {
	// if (entityManager != null) {
	// entityManager.close();
	// }
	// }
	//
	// }
	//
	// public UserBean getUserById(Integer UserId) throws Exception {
	// UserBean User = null;
	// EntityManager entityManager = null;
	// try {
	// EntityManagerFactory entityManagerFactory =
	// UserTakerUtility.getEntityManagerFactory();
	// entityManager = entityManagerFactory.createEntityManager();
	// UserEntity UserEntity = entityManager.find(UserEntity.class, UserId);
	// if (UserEntity != null) {
	// User = new UserBean();
	// User.setId(UserEntity.getId());
	// User.setTitle(UserEntity.getTitle());
	// User.setContent(UserEntity.getContent());
	// User.setAddedDate(UserEntity.getAddedDate());
	// }
	// } catch (Exception exception) {
	// throw exception;
	// } finally {
	// if (entityManager != null) {
	// entityManager.close();
	// }
	// }
	// return User;
	// }

}
