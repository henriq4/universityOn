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
    private void withdrawVehicle() throws IOException{
        App.setRoot("withdrawVehicle");
    }

    @FXML
    private void exit(){
        Platform.exit();
        System.exit(0);
    }

}
