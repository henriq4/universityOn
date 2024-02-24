package model;

import java.io.Serializable;
import java.time.LocalDate;
import java.util.Date;
import java.util.Objects;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import javax.persistence.Table;
import javax.persistence.Temporal;
import javax.persistence.TemporalType;
import util.Persistivel;

@Entity
@Table(name = "vehicle_use")

public class VehicleUse implements Serializable, Persistivel {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Integer id;

    @JoinColumn(name = "vehicle", referencedColumnName = "id")
    @ManyToOne
    private Vehicle vehicle;

    @JoinColumn(name = "driver", referencedColumnName = "id")
    @ManyToOne
    private Driver driver;

    @Column
    @Temporal(TemporalType.DATE)
    private LocalDate withdraw;

    @Column
    @Temporal(TemporalType.DATE)
    private LocalDate devolution;

    public VehicleUse() {
    }

    public VehicleUse(Vehicle vehicle, Driver driver, LocalDate withdraw, LocalDate devolution) {
        this.vehicle = vehicle;
        this.driver = driver;
        this.withdraw = withdraw;
        this.devolution = devolution;
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public Vehicle getVehicle() {
        return vehicle;
    }

    public void setVehicle(Vehicle vehicle) {
        this.vehicle = vehicle;
    }

    public Driver getDriver() {
        return driver;
    }

    public void setDriver(Driver driver) {
        this.driver = driver;
    }

    public LocalDate getWithdraw() {
        return withdraw;
    }

    public void setWithdraw(LocalDate withdraw) {
        this.withdraw = withdraw;
    }

    public LocalDate getDevolution() {
        return devolution;
    }

    public void setDevolution(LocalDate devolution) {
        this.devolution = devolution;
    }

    @Override
    public String toString() {
        return vehicle + " | " + driver;
    }

}
