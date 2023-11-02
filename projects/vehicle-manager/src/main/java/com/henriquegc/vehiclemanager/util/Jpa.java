package com.henriquegc.vehiclemanager.util;

import java.io.Serializable;
import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.Persistence;

  public class Jpa {
    private static final EntityManagerFactory factory;
    static {
      factory = Persistence.createEntityManagerFactory("com.henriquegc.vehiclemanager");
    }

    public static EntityManager getEntityManager() {
      return factory.createEntityManager();
    }
    public static void close() {
      factory.close();
    }
}
