package app;

import java.io.IOException;

import app.App;
import javafx.application.Platform;
import javafx.fxml.FXML;


public class Menu {

    @FXML
    private void createDriver() throws IOException {
        App.setRoot("createDriver");
    }

    @FXML
    private void deleteDriver() throws IOException{
        App.setRoot("deleteDriver");
    }

    @FXML
    private void createVehicle() throws IOException{
        App.setRoot("createVehicle");
    }

    @FXML
    private void createOperator() throws IOException{
        App.setRoot("createOperator");
    }

    @FXML
    private void withdrawVehicle() throws IOException{
        App.setRoot("withdrawVehicle");
    }

  @FXML
  private void listVehicles() throws IOException {
    App.setRoot("listVehicles");
  }

  @FXML
  private void listDrivers() throws IOException {
    App.setRoot("listDrivers");
  }

  @FXML
  private void listWithdraws() throws IOException {
    App.setRoot("listWithdraws");
  }

  @FXML
  private void withdrawDevolution() throws IOException {
    App.setRoot("withdrawDevolution");
  }

  @FXML
  private void getWithdrawVehicle() throws IOException {
    App.setRoot("getWithdrawVehicle");
  }

    @FXML
    private void exit(){
        Platform.exit();
        System.exit(0);
    }

}
