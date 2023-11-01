package com.henriquegc.vehiclemanager.util;

import com.henriquegc.vehiclemanager.domain.user.User;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class DaoTest {

  @Test
  void inserir() {
    User user = new User("Henrqiue", "Bandeirantes/PR", "henrique", "1234");

    Dao<User> dao = new Dao<User>(User.class);
    dao.inserir(user);
  }
}
