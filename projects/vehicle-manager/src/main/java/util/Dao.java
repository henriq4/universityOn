package util;

import exception.DeleteException;
import model.Operator;

import java.util.List;
import javax.persistence.EntityManager;
import javax.persistence.EntityTransaction;
import javax.persistence.TypedQuery;
import javax.persistence.criteria.CriteriaQuery;

public class Dao<T extends Persistivel> {

    private final Class<T> objClass;
    EntityManager manager;

    public Dao(Class<T> objClass) {
        this.objClass = objClass;
    }

    public T update(T obj) {
        manager = JpaUtil.getEntityManager();
        manager.getTransaction().begin();
        obj = manager.merge(obj);
        manager.getTransaction().commit();
        manager.close();
        return obj;
    }

    public T getById(Object id) {
        T obj;
        manager = JpaUtil.getEntityManager();
        obj = manager.find(objClass, id);
        manager.close();
        return obj;
    }

    public void delete(T obj) throws DeleteException {
        manager = JpaUtil.getEntityManager();
        EntityTransaction tx = manager.getTransaction();
        tx.begin();
        try {
            T temp = manager.find(objClass, obj.getId());
            manager.remove(temp);
            tx.commit();
        } catch (Exception e) {
            throw new DeleteException();
        } finally {
            manager.close();
        }
    }

    public void insert(T obj) {
        manager = JpaUtil.getEntityManager();
        EntityTransaction tx = manager.getTransaction();
        tx.begin();
        manager.persist(obj);
        tx.commit();
    }

    public List<T> getAll() {
        manager = JpaUtil.getEntityManager();
        CriteriaQuery<T> query
                = manager.getCriteriaBuilder().createQuery(objClass);
        query.select(query.from(objClass));
        List<T> lista = manager.createQuery(query).getResultList();
        manager.close();
        return lista;
    }
}
