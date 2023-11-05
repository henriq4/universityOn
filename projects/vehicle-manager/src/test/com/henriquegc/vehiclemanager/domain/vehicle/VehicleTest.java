package com.henriquegc.vehiclemanager.domain.vehicle;

import com.henriquegc.vehiclemanager.util.Dao;
import org.junit.jupiter.api.Test;

public class VehicleTest {

  @Test
  void inserir() {
    Vehicle vehicle = new Vehicle("Ford", "Fiesta", "ABC-1234");

    Dao<Vehicle> dao = new Dao<Vehicle>(Vehicle.class);
    dao.inserir(vehicle);
  }
}
