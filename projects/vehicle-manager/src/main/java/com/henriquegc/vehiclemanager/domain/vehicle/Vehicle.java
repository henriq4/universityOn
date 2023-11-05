package com.henriquegc.vehiclemanager.domain.vehicle;

import javax.persistence.*;

@Entity
public class Vehicle {

  @Id
  @GeneratedValue(strategy = GenerationType.IDENTITY)
  private String id;

  @Column
  private String brand;

  @Column
  private String model;

  @Column(unique = true)
  private String plate;

  public Vehicle() {}

  public Vehicle(String brand, String model, String plate) {
    this.brand = brand;
    this.model = model;
    this.plate = plate;
  }

  public String getId() {
    return id;
  }

  public void setId(String id) {
    this.id = id;
  }

  public String getBrand() {
    return brand;
  }

  public void setBrand(String brand) {
    this.brand = brand;
  }

  public String getModel() {
    return model;
  }

  public void setModel(String model) {
    this.model = model;
  }

  public String getPlate() {
    return plate;
  }

  public void setPlate(String plate) {
    this.plate = plate;
  }
}
