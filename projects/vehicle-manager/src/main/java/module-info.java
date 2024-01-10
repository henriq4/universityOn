open module app {
    requires javafx.controls;
    requires javafx.fxml;

    requires java.persistence;
    requires java.sql;
    requires org.hibernate.orm.core;
    requires org.postgresql.jdbc;

    exports app;
    exports exception;
    exports model;
    exports util;
}


