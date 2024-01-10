package app;

import java.io.IOException;

import app.App;
import javafx.application.Platform;
import javafx.fxml.FXML;


public class Menu {

    @FXML
    private void cadastrarMotorista() throws IOException {
        App.setRoot("createDriver");
    }

    @FXML
    private void cadastrarOperador() throws IOException {
        App.setRoot("novoOperador");
    }

    @FXML
    private void excluirMotorista() throws IOException{
        App.setRoot("deleteDriver");
    }

    @FXML
    private void retirarVeiculo() throws IOException{
        App.setRoot("withdrawVehicle");
    }

    @FXML
    private void sair(){
        Platform.exit();
        System.exit(0);
    }

}
