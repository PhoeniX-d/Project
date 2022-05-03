package com.acn.blog.utility;

import java.io.File;
import java.io.FileOutputStream;
import java.io.InputStream;

import javax.persistence.EntityManagerFactory;
import javax.persistence.Persistence;

public class BlogUtility {

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
			entityManagerFactory = Persistence.createEntityManagerFactory("TechBlog");
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

	public static Boolean deleteFile(String path) {
		Boolean isFileDeleted = false;
		try {
			File file = new File(path);
			isFileDeleted = file.delete();
		} catch (Exception e) {
			e.printStackTrace();
		}
		return isFileDeleted;
	}

	public static Boolean saveFile(InputStream is, String path) {
		Boolean isFileSaved = false;
		try {
			byte[] data = new byte[is.available()];
			is.read(data);
			FileOutputStream fos = new FileOutputStream(path);
			fos.write(data);
			fos.flush();
			fos.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
		return isFileSaved;
	}
}
