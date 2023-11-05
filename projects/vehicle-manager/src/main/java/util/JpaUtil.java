package util;

import javafx.event.Event;

import java.io.Serializable;
import java.util.Date;
import java.util.List;
import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.Persistence;

public class JpaUtil implements Serializable {
    private static final EntityManagerFactory factory;
    static {
        factory = Persistence.createEntityManagerFactory("veiculosPU");
    }
    
    public static EntityManager getEntityManager() {
        return factory.createEntityManager();
    }

    public static void close() {
        factory.close();
    }
    
}


