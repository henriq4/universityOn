package util;

import domain.Vaca;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;
import util.Dao;

/**
 *
 * @author Usuário
 */
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
        Vaca vaca = new Vaca();
        vaca.setName("Lili");
        vaca.setRaca("Jersey");
        Dao<Vaca> dao = new Dao(Vaca.class);
        dao.inserir(vaca);
    }

}