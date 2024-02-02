package util;

import model.Operator;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;

public class DaoTest {

    public DaoTest() {
    }

    @BeforeAll
    public static void setUpClass() {
    }

    @AfterAll
    public static void tearDownClass() {
    }

    @BeforeEach
    public void setUp() {
    }

    @AfterEach
    public void tearDown() {
    }

    @Test
    public void testInserir(){
        Operator operator = new Operator();
        operator.setName("Teste");
        operator.setAddress("Teste");
        operator.setLogin("teste");
        operator.setPassword("teste");
        Dao<Operator> dao = new Dao(Operator.class);
        dao.insert(operator);
    }
}
