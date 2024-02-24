package app;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.ComboBox;
import javafx.scene.control.DatePicker;
import javafx.scene.control.ListView;
import model.Driver;
import model.Vehicle;
import model.VehicleUse;
import util.Dao;

import java.io.Console;
import java.io.IOException;
import java.time.LocalDate;
import java.util.List;
import java.util.Objects;
import java.util.stream.Stream;

public class GetWithdrawVehicle {
  @FXML
  private ListView<String> drivers;

  @FXML
  private ComboBox<Vehicle> vehicles;

  @FXML
  private DatePicker datePicker;

  private Dao<Vehicle> daoVehicle;

  private Dao<VehicleUse> daoVehicleUse;

  @FXML
  private void initialize() {
    daoVehicle = new Dao(Vehicle.class);
    daoVehicleUse = new Dao(VehicleUse.class);

    List<Vehicle> getVehicles = daoVehicle.getAll();
    ObservableList<Vehicle> getVehiclesObservable = FXCollections.observableArrayList(getVehicles);
    vehicles.setItems(getVehiclesObservable);
  }

  @FXML
  private void getWithdrawVehicleDriver() {
    Vehicle vehicle = vehicles.getSelectionModel().getSelectedItem();
    LocalDate date = datePicker.getValue();

    List<String> drivers = FXCollections.observableArrayList();

    try {
      List<VehicleUse> vehiclesUseList = daoVehicleUse.getAll();

      for (VehicleUse vehicleUse : vehiclesUseList) {
        if (String.valueOf(vehicle).equals(String.valueOf(vehicleUse.getVehicle()))) {
          if (String.valueOf(vehicleUse.getWithdraw()).equals(String.valueOf(date))) {
            drivers.add(vehicleUse.getDriver().getName() + " " + vehicleUse.getDriver().getCnh());
          }

         else if (String.valueOf(vehicleUse.getDevolution()).equals(String.valueOf(date))) {
            drivers.add(vehicleUse.getDriver().getName() + " " + vehicleUse.getDriver().getCnh());
          }

          else if (date.isAfter(vehicleUse.getWithdraw()) && date.isBefore(vehicleUse.getDevolution())) {
            drivers.add(vehicleUse.getDriver().getName() + " " + vehicleUse.getDriver().getCnh());
          }
        }
      }

      this.drivers.getItems().addAll(drivers);

      if (drivers.isEmpty()) {
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setContentText("Nenhum motorista retirou o veículo na data selecionada");
        alert.show();
      }
    } catch (Exception e) {
      Alert alert = new Alert(Alert.AlertType.ERROR);
      alert.setContentText("Ocorreu um erro na busca pelo veículo");
      alert.show();
    }
  }

  @FXML
  private void goToMenu() throws IOException{
    App.setRoot("menu");
  }

}
