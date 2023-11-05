package com.henriquegc.vehiclemanager.util;

import com.henriquegc.vehiclemanager.domain.user.Users;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class DaoTest {

  @Test
  void inserir() {
    Users user = new Users("Henrique", "Rua 1", "henrique", "123");

    Dao<Users> dao = new Dao<Users>(Users.class);
    dao.inserir(user);
  }
}
