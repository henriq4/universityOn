package model;

import java.io.Serializable;
import java.util.Objects;
import javax.persistence.Column;
import javax.persistence.DiscriminatorValue;
import javax.persistence.Entity;
import javax.persistence.Table;

import util.Persistivel;

@Entity
@Table(name = "driver")
@DiscriminatorValue("driver")
public class Driver extends Person implements Serializable, Persistivel {

  @Column
  private Long cnh;

  @Column(length = 5)
  private String category;

  @Column(length = 15)
  private String setor;

  public Driver() {
  }

  public Driver(Long cnh, String category, String setor, String nome, String endereco) {
    super(nome, endereco);
    this.cnh = cnh;
    this.category = category;
    this.setor = setor;
  }

  public Long getCnh() {
    return cnh;
  }

  public void setCnh(Long cnh) {
    this.cnh = cnh;
  }

  public String getCategory() {
    return category;
  }

  public void setCategory(String category) {
    this.category = category;
  }

  public String getSetor() {
    return setor;
  }

  public void setSetor(String setor) {
    this.setor = setor;
  }

  @Override
  public int hashCode() {
    int hash = 3;
    hash = 53 * hash + Objects.hashCode(this.cnh);
    return hash;
  }

  @Override
  public boolean equals(Object obj) {
    if (this == obj) {
      return true;
    }
    if (obj == null) {
      return false;
    }
    if (getClass() != obj.getClass()) {
      return false;
    }
    final Driver other = (Driver) obj;
    return Objects.equals(this.cnh, other.cnh);
  }

  @Override
  public String toString() {
    return this.getName();
  }

}
