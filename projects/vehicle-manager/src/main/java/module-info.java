module com.henriquegc.vehiclemanager {
  requires javafx.controls;
  requires javafx.fxml;
  requires java.persistence;
  requires org.hibernate.orm.core;
  requires org.postgresql.jdbc;

  opens com.henriquegc.vehiclemanager to javafx.fxml;
  exports com.henriquegc.vehiclemanager;

}
