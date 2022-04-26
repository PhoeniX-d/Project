package com.acn.todo.utility;

import javax.persistence.EntityManagerFactory;
import javax.persistence.Persistence;

public class NoteTakerUtility {

	/**
	 * The entity manager factory.
	 */
	private static EntityManagerFactory entityManagerFactory;

	/**
	 * Builds the entity manager factory.
	 *
	 * @return the entity manager factory
	 */
	private static EntityManagerFactory buildEntityManagerFactory() {
		try {
			entityManagerFactory = Persistence.createEntityManagerFactory("Note-Taker");
			return entityManagerFactory;
		} catch (Throwable ex) {
			// Make sure you log the exception, as it might be swallowed
			System.err.println("Initialization of EntityManagerFactory failed." + ex);
			throw new RuntimeException(ex);
		}
	}

	/**
	 * Gets the entity manager factory.
	 *
	 * @return the entity manager factory
	 */
	public static EntityManagerFactory getEntityManagerFactory() {
		if (entityManagerFactory == null) {
			entityManagerFactory = buildEntityManagerFactory();
		}
		return entityManagerFactory;
	}

	/**
	 * Close entity manager factory.
	 */
	public static void closeEntityManagerFactory() {

		if (entityManagerFactory != null && entityManagerFactory.isOpen() == true) {
			entityManagerFactory.close();
		}
	}

}
