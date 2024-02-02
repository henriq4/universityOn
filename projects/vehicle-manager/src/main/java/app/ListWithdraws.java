package app;

import javafx.collections.FXCollections;
import javafx.fxml.FXML;
import javafx.scene.control.ListView;
import model.VehicleUse;
import util.Dao;

import java.io.IOException;
import java.util.List;

public class ListWithdraws {
  @FXML
  private ListView<String> withdraws;

  private Dao<VehicleUse> dao;

  @FXML
  private void initialize() {
    dao = new Dao(VehicleUse.class);
    List<VehicleUse> withdrawsList = dao.getAll();
    List<String> withdraws = FXCollections.observableArrayList();
    for (VehicleUse withdraw : withdrawsList) {
      withdraws.add(withdraw.getDriver() + " " + withdraw.getVehicle() + " " + withdraw.getWithdraw() + " " + withdraw.getDevolution());
    }
    this.withdraws.getItems().addAll(withdraws);
  }

  @FXML
  private void goToMenu() throws IOException {
    App.setRoot("menu");
  }
}
