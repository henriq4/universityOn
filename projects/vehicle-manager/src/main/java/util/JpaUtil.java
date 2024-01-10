package util;

import java.io.Serializable;
import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.Persistence;

public class JpaUtil implements Serializable {
    private static final EntityManagerFactory factory;

    static {
      try {
        factory = Persistence.createEntityManagerFactory("vehicles");
      }
      catch (Throwable ex) {
        System.err.println("Initial SessionFactory creation failed." + ex);
        throw new ExceptionInInitializerError(ex);
      }
    }

    public static EntityManager getEntityManager() {
        return factory.createEntityManager();
    }
    public static void close() {
        factory.close();
    }

}

