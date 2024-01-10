package app;

import java.io.IOException;
import java.util.List;

import app.App;
import exception.DeleteException;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.ComboBox;
import model.Driver;
import util.Dao;

public class DeleteDriver {

    @FXML
    private ComboBox<Driver> drivers;

    private ObservableList<Driver> getDriversObservable;
    private List<Driver> getDrivers;

    private Dao<Driver> dao;

    @FXML
    private void initialize() {
        dao = new Dao(Driver.class);
        getDrivers = dao.getAll();
        getDriversObservable = FXCollections.observableArrayList(getDrivers);
        drivers.setItems(getDriversObservable);
    }

    @FXML
    private void deleteDriver() {
        Driver temp = drivers.getSelectionModel().getSelectedItem();

        try {
          dao.delete(temp);
        } catch (DeleteException e) {
          Alert alert = new Alert(Alert.AlertType.ERROR);
          alert.setContentText("Não foi possível excluir o motorista");
          alert.show();
        }

        getDrivers = dao.getAll();
        getDriversObservable = FXCollections.observableArrayList(getDrivers);
        drivers.setItems(getDriversObservable);
    }

    @FXML
    private void goToMenu() throws IOException {
        App.setRoot("menu");
    }

}
