package app;

import java.io.IOException;

import app.App;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.TextField;
import model.Operator;
import util.Dao;
import util.DaoOperator;

public class Login {

    @FXML
    private TextField login;

    @FXML
    private TextField password;

    @FXML
    private void login() throws IOException {
        DaoOperator dao = new DaoOperator();
        Operator temp = dao.login(login.getText(), password.getText());

        if (temp == null) {
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setContentText("Login ou senha inválidos");
            alert.show();
        } else {
            App.setRoot("menu");
        }

    }

}
