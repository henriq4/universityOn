open module com.henriquegc.vehiclemanager {
  requires javafx.controls;
  requires javafx.fxml;
  requires java.persistence;
  requires org.hibernate.orm.core;
  requires org.postgresql.jdbc;

  exports com.henriquegc.vehiclemanager;
}
