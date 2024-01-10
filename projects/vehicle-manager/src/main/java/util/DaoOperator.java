
package util;

import model.Operator;

import java.io.Serializable;
import javax.persistence.EntityManager;
import javax.persistence.TypedQuery;

public class DaoOperator implements Serializable{
    EntityManager manager;

    public Operator login(String login, String password) {
        Operator temp = null;
        try {
          manager = JpaUtil.getEntityManager();
          System.out.println("Login: " + login + " Senha: " + password);
          String sql = "SELECT o FROM Operator o WHERE o.login = :login AND o.password = :password";
          TypedQuery<Operator> query = manager.createQuery(sql, Operator.class);
          query.setParameter("login", login);
          query.setParameter("password", password);
          System.out.println("Query: " + query.toString());
            temp = query.getSingleResult();
        } catch (Exception e) {
            temp = null;
        }
        return temp;
    }

    public boolean alreadyExists(String login) {
        Operator temp = null;
        boolean existe = false;
        manager = JpaUtil.getEntityManager();
        String sql = "SELECT o FROM Operator o WHERE o.login = :login";
        TypedQuery<Operator> query = manager.createQuery(sql, Operator.class);
        query.setParameter("login", login);
        try {
            temp = query.getSingleResult();
            existe = true;
        } catch (Exception e) {
            temp = null;
        } finally {
            manager.close();
        }
        return existe;
    }

}
