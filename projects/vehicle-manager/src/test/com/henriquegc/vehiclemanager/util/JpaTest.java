package com.henriquegc.vehiclemanager.util;

import org.junit.jupiter.api.Test;

import javax.persistence.EntityManager;

import static org.junit.jupiter.api.Assertions.*;

class JpaTest {

  @Test
  void getEntityManager() {
    EntityManager em = Jpa.getEntityManager();
    assertNotNull(em);
  }

  @Test
  void close() {
  }
}
