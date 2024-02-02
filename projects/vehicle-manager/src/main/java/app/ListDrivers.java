package app;

import javafx.collections.FXCollections;
import javafx.fxml.FXML;
import javafx.scene.control.ListView;
import model.Driver;
import util.Dao;

import java.util.List;

public class ListDrivers {
  @FXML
  private ListView<String> drivers;

  private Dao<Driver> dao;

  @FXML
  private void initialize() {
    dao = new Dao(Driver.class);
    List<Driver> driversList = dao.getAll();
    List<String> drivers = FXCollections.observableArrayList();
    for (Driver driver : driversList) {
      drivers.add(driver.getName() + " " + driver.getCnh());
    }
    this.drivers.getItems().addAll(drivers);
  }
}
