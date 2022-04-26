package com.acn.todo.dao;

import java.util.Date;
import java.util.LinkedList;
import java.util.List;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.NoResultException;
import javax.persistence.TypedQuery;

import com.acn.todo.bean.NoteBean;
import com.acn.todo.entity.NoteEntity;
import com.acn.todo.utility.NoteTakerUtility;

public class NoteDAOImpl implements NoteDAO {

	public Integer addNote(NoteBean note) throws Exception {
		Integer noteId = null;
		EntityManager entityManager = null;
		try {
			EntityManagerFactory entityManagerFactory = NoteTakerUtility.getEntityManagerFactory();
			entityManager = entityManagerFactory.createEntityManager();

			// populating NoteEntity object for NoteEntity
			NoteEntity noteEntity = new NoteEntity();
			noteEntity.setTitle(note.getTitle());
			noteEntity.setContent(note.getContent());
			noteEntity.setAddedDate(note.getAddedDate());

			// begin
			entityManager.getTransaction().begin();
			// persist
			entityManager.persist(noteEntity);
			// commit
			entityManager.getTransaction().commit();

			noteId = noteEntity.getId();
		} catch (Exception exception) {
			throw exception;
		} finally {
			if (entityManager != null) {
				entityManager.close();
			}
		}
		return noteId;
	}

	public List<NoteBean> getNotes() throws Exception {
		List<NoteBean> notes = new LinkedList<NoteBean>();
		List<NoteEntity> notesEntities = null;
		EntityManager entityManager = null;
		try {
			EntityManagerFactory entityManagerFactory = NoteTakerUtility.getEntityManagerFactory();
			entityManager = entityManagerFactory.createEntityManager();
			TypedQuery<NoteEntity> query = entityManager.createQuery("SELECT n FROM NoteEntity n", NoteEntity.class);
			try {
				notesEntities = query.getResultList();
			} catch (NoResultException nre) {
			}
			for (NoteEntity noteEntity : notesEntities) {
				NoteBean beanNote = new NoteBean();
				beanNote.setId(noteEntity.getId());
				beanNote.setTitle(noteEntity.getTitle());
				beanNote.setContent(noteEntity.getContent());
				beanNote.setAddedDate(noteEntity.getAddedDate());
				notes.add(beanNote);
			}

		} catch (Exception exception) {
			throw exception;
		} finally {
			if (entityManager != null) {
				entityManager.close();
			}
		}
		return notes;
	}

	public void deleteNote(Integer noteId) throws Exception {
		EntityManager entityManager = null;
		try {
			EntityManagerFactory entityManagerFactory = NoteTakerUtility.getEntityManagerFactory();
			entityManager = entityManagerFactory.createEntityManager();
			NoteEntity noteEntity = entityManager.find(NoteEntity.class, noteId);
			if (noteEntity != null) {
				entityManager.getTransaction().begin();
				entityManager.remove(noteEntity);
				entityManager.getTransaction().commit();
			}
		} catch (Exception exception) {
			throw exception;
		} finally {
			if (entityManager != null) {
				entityManager.close();
			}
		}
	}

	public void updateNote(NoteBean note) throws Exception {
		EntityManager entityManager = null;
		try {
			EntityManagerFactory entityManagerFactory = NoteTakerUtility.getEntityManagerFactory();
			entityManager = entityManagerFactory.createEntityManager();
			NoteEntity noteEntity = entityManager.find(NoteEntity.class, note.getId());
			if (noteEntity != null) {
				entityManager.getTransaction().begin();
				noteEntity.setId(note.getId());
				noteEntity.setTitle(note.getTitle());
				noteEntity.setContent(note.getContent());
				noteEntity.setAddedDate(new Date());
				entityManager.persist(noteEntity);
				entityManager.getTransaction().commit();
			}
		} catch (Exception exception) {
			throw exception;
		} finally {
			if (entityManager != null) {
				entityManager.close();
			}
		}

	}

	public NoteBean getNoteById(Integer noteId) throws Exception {
		NoteBean note = null;
		EntityManager entityManager = null;
		try {
			EntityManagerFactory entityManagerFactory = NoteTakerUtility.getEntityManagerFactory();
			entityManager = entityManagerFactory.createEntityManager();
			NoteEntity noteEntity = entityManager.find(NoteEntity.class, noteId);
			if (noteEntity != null) {
				note = new NoteBean();
				note.setId(noteEntity.getId());
				note.setTitle(noteEntity.getTitle());
				note.setContent(noteEntity.getContent());
				note.setAddedDate(noteEntity.getAddedDate());
			}
		} catch (Exception exception) {
			throw exception;
		} finally {
			if (entityManager != null) {
				entityManager.close();
			}
		}
		return note;
	}

}
