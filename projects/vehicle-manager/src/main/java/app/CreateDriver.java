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
    private TextField name;

    @FXML
    private TextField address;

    @FXML
    private TextField cnh;

    @FXML
    private TextField category;

    @FXML
    private TextField section;


    @FXML
    private void createDriver(){
        Driver driver = new Driver();

        driver.setName(name.getText());
        driver.setAddress(address.getText());
        driver.setCnh(Long.valueOf(cnh.getText()));
        driver.setCategory(category.getText());
        driver.setSection(section.getText());

        Dao<Driver> dao = new Dao(Driver.class);
        dao.insert(driver);

        cleanInputs();

        Alert alert = new Alert(AlertType.CONFIRMATION);
        alert.setContentText("Motorista cadastrado");
        alert.show();
    }

    @FXML
    private void cleanInputs(){
        name.setText("");
        address.setText("");
        cnh.setText("");
        category.setText("");
        section.setText("");
    }

    @FXML
    private void goToMenu() throws IOException{
        App.setRoot("menu");
    }

}
