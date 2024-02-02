package app;

import java.io.IOException;
import java.util.List;

import app.App;
import exception.DeleteException;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.ChoiceBox;
import javafx.scene.control.ComboBox;
import javafx.scene.control.TextField;
import model.Driver;
import model.Vehicle;
import model.VehicleUse;
import util.Dao;

public class WithdrawVehicle {
//
//  @FXML
//  private ComboBox<Driver> drivers;
//
//  @FXML
//  private ComboBox<Vehicle> vehicles;
//
//
//  private ObservableList<Driver> getDriversObservable;
//  private  ObservableList<Vehicle> getVehicleObservable;
//
//  private List<Driver> getDrivers;
//  private List<Vehicle> getVehicle;
//
//  private Dao<Driver> daoDriver;
//
//  private Dao<Vehicle> daoVehicle;
//
//  private Dao<VehicleUse> daoVehicleUse;
//
//  @FXML
//  private void initialize() {
//    daoDriver = new Dao(Driver.class);
//    daoVehicle = new Dao(Vehicle.class);
//
//    daoVehicleUse = new Dao(VehicleUse.class);
//
//    getDrivers = daoDriver.getAll();
//    getVehicle = daoVehicle.getAll();
//
//    getDriversObservable = FXCollections.observableArrayList(getDrivers);
//    getVehicleObservable = FXCollections.observableArrayList(getVehicle);
//
//    drivers.setItems(getDriversObservable);
//  }
//
//  @FXML
//  private void withdrawVehicle() {
//    Driver tempDriver = drivers.getSelectionModel().getSelectedItem();
//    Vehicle tempVehicle = vehicles.getSelectionModel().getSelectedItem();
//
//    try {
//      VehicleUse vehicleUse = new VehicleUse();
//      vehicleUse.setDriver(tempDriver);
//      vehicleUse.setVehicle(tempVehicle);
//      daoVehicleUse.insert(vehicleUse);
//      } catch (Exception e) {
//        Alert alert = new Alert(AlertType.ERROR);
//        alert.setContentText("Não foi possível retirar o veículo");
//        alert.show();
//    }
//  }

  @FXML
  private void goToMenu() throws IOException{
    App.setRoot("menu");
  }

}
