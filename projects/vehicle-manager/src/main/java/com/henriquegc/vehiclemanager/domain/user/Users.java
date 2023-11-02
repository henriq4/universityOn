package com.henriquegc.vehiclemanager.domain.user;

import javax.persistence.*;

@Entity
public class Users {
  @Id
  private int id;

  @Column
  private String name;

  @Column
  private String address;

  @Column
  private String login;

  @Column
  private String password;

  public Users() {}

  public Users(int id, String name, String address, String login, String password) {
    this.id = id;
    this.name = name;
    this.address = address;
    this.login = login;
    this.password = password;
  }

  public String getName() {
    return name;
  }

  public void setName(String name) {
    this.name = name;
  }

  public String getAddress() {
    return address;
  }

  public void setAddress(String address) {
    this.address = address;
  }

  public String getLogin() {
    return login;
  }

  public void setLogin(String login) {
    this.login = login;
  }

  public String getPassword() {
    return password;
  }

  public void setPassword(String password) {
    this.password = password;
  }
}
