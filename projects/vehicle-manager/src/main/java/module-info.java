module com.henriquegc.vehiclemanager {
  requires javafx.controls;
  requires javafx.fxml;


  opens com.henriquegc.vehiclemanager to javafx.fxml;
  exports com.henriquegc.vehiclemanager;
}
