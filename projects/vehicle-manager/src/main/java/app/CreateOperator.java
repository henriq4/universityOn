package app;

import java.io.IOException;

import app.App;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.TextField;
import model.Operator;
import util.Dao;

public class CreateOperator {
    @FXML
    private TextField name;

    @FXML
    private TextField address;

    @FXML
    private TextField login;

    @FXML
    private TextField password;


    @FXML
    private void createOperator(){
        Operator operator = new Operator();

        operator.setName(name.getText());
        operator.setAddress(address.getText());
        operator.setLogin(login.getText());
        operator.setPassword(password.getText());

        Dao<Operator> dao = new Dao(Operator.class);
        dao.insert(operator);

        cleanInputs();

        Alert alert = new Alert(AlertType.CONFIRMATION);
        alert.setContentText("Operador cadastrado");
        alert.show();
    }

    @FXML
    private void cleanInputs(){
        name.setText("");
        address.setText("");
        login.setText("");
        password.setText("");
    }

    @FXML
    private void goToMenu() throws IOException{
        App.setRoot("menu");
    }

}

