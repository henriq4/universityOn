package com.henriquegc.vehiclemanager.domain.user;

public class User {
  private Long id;

  private String name;

  private String address;

  private String login;

  private String password;

  public User(String name, String address, String login, String password) {
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
