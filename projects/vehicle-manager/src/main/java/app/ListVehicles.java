package app;

import javafx.collections.FXCollections;
import javafx.fxml.FXML;
import javafx.scene.control.ListView;
import model.Vehicle;
import util.Dao;

import java.io.IOException;
import java.util.List;

public class ListVehicles {
  @FXML
  private ListView<String> vehicles;

  private Dao<Vehicle> dao;

  @FXML
  private void initialize() {
    dao = new Dao(Vehicle.class);
    List<Vehicle> vehiclesList = dao.getAll();
    List<String> vehicles = FXCollections.observableArrayList();
    for (Vehicle vehicle : vehiclesList) {
      vehicles.add(vehicle.getBrand() + " " + vehicle.getModel() + " " + vehicle.getPlate());
    }
    this.vehicles.getItems().addAll(vehicles);
  }

    @FXML
    private void goToMenu() throws IOException {
        App.setRoot("menu");
    }
}
