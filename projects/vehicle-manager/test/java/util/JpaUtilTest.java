package util;

import org.junit.jupiter.api.*;

import javax.persistence.EntityManager;

import static org.junit.jupiter.api.Assertions.assertNotNull;

public class JpaUtilTest {

    public JpaUtilTest() {
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
    public void testConnection(){
        EntityManager em = JpaUtil.getEntityManager();
        assertNotNull(em);
    }

    @Test
    void getEntityManager() {
    }

    @Test
    void close() {
    }
}
