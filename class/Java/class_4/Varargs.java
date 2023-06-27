class Varargs {
    public static int maior(int ...args) {
        int maior = 0;

        for(int i = 0; i < args.length; i++) {
            if (i == 0) {
                maior = args[i];
                continue;
            }

            if (args[i] > maior) {
                maior = args[i];
            }
        }

        return maior;
    }
}
