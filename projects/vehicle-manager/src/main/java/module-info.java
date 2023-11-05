module app {
    requires javafx.controls;
    requires javafx.fxml;
    
    requires java.persistence;
    requires org.hibernate.orm.core;
    requires org.postgresql.jdbc;

    opens app to javafx.fxml;
 
    exports app;
    exports util;
}


