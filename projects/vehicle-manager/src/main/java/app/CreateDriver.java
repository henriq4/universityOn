package app;

import java.io.IOException;

import app.App;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.TextField;
import model.Driver;
import util.Dao;

public class CreateDriver {
    @FXML
    private TextField campoNome;

    @FXML
    private TextField campoEndereco;

    @FXML
    private TextField campoCnh;

    @FXML
    private TextField campoCategoria;

    @FXML
    private TextField campoSetor;


    @FXML
    private void cadastrarMotorista(){
        Driver motorista = new Driver();
        motorista.setName(campoNome.getText());
        motorista.setAddress(campoEndereco.getText());
        motorista.setCnh(Long.valueOf(campoCnh.getText()));
        motorista.setCategory(campoCategoria.getText());
        motorista.setSetor(campoSetor.getText());
        Dao<Driver> dao = new Dao(Driver.class);
        dao.inserir(motorista);
        limparCampos();
        Alert alert = new Alert(AlertType.CONFIRMATION);
        alert.setContentText("Motorista cadastrado");
        alert.show();
    }

    @FXML
    private void limparCampos(){
        campoNome.setText("");
        campoEndereco.setText("");
        campoCnh.setText("");
        campoCategoria.setText("");
        campoSetor.setText("");
    }

    @FXML
    private void voltarAoMenu() throws IOException{
        App.setRoot("menu");
    }

}
