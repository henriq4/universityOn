package app;

import java.io.IOException;
import java.time.LocalDate;
import java.util.List;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.scene.control.Alert.AlertType;
import model.Driver;
import model.Vehicle;
import model.VehicleUse;
import util.Dao;

public class WithdrawDevolution {

  @FXML
  private ComboBox<VehicleUse> withdraws;

  private ObservableList<VehicleUse> getWithdrawsObservable;

  private List<VehicleUse> getWithdraws;

  @FXML
  private DatePicker dateDevolution;

  private Dao<VehicleUse> daoVehicleUse;

  @FXML
  private void initialize() {
    daoVehicleUse = new Dao(VehicleUse.class);

    getWithdraws = daoVehicleUse.getAll();

    getWithdrawsObservable = FXCollections.observableArrayList(getWithdraws);

    withdraws.setItems(getWithdrawsObservable);
  }

  @FXML
  private void withdrawDevolution() {
    VehicleUse withdraw = withdraws.getSelectionModel().getSelectedItem();
    LocalDate date = dateDevolution.getValue();

    try {
      withdraw.setDevolution(date);
      daoVehicleUse.update(withdraw);

      Alert alert = new Alert(AlertType.CONFIRMATION);
      alert.setContentText("Veículo devolvido com sucesso!");
      alert.show();
    } catch (Exception e) {
      Alert alert = new Alert(AlertType.ERROR);
      alert.setContentText("Não foi possível devolver o veículo");
      alert.show();
    }
  }

  @FXML
  private void goToMenu() throws IOException{
    App.setRoot("menu");
  }

}
