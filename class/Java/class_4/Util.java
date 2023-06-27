class Util {
    public static boolean ehPar(int n) {
        if (n % 2 == 0) {
            return true;
        }

        return false;
    }

    public static boolean ehNegativo(int n) {
        if (n < 0) {
            return true;
        }

        return false;
    }

    public static int maior(int x, int y) {
        return x >= y ? x : y;
    }
}
