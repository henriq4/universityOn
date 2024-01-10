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
    private ComboBox<Driver> comboMotoristas;

    private ObservableList<Driver> listaOb;
    private List<Driver> lista;
    private Dao<Driver> dao;

    @FXML
    private void initialize() {
        dao = new Dao(Driver.class);
        lista = dao.listarTodos();
        listaOb = FXCollections.observableArrayList(lista);
        comboMotoristas.setItems(listaOb);
    }

    @FXML
    private void excluirMotorista() {
        Driver temp = comboMotoristas.getSelectionModel().getSelectedItem();

        try {
          dao.excluir(temp);
        } catch (DeleteException e) {
          Alert alert = new Alert(Alert.AlertType.ERROR);
          alert.setContentText("Não foi possível excluir o motorista");
          alert.show();
        }
        // atualiza a lista
        lista = dao.listarTodos();
        listaOb = FXCollections.observableArrayList(lista);
        comboMotoristas.setItems(listaOb);
    }

    @FXML
    private void voltarAoMenu() throws IOException {
        App.setRoot("menu");
    }

}
