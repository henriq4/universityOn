class InstacedTimes {
  private static int objectQuantity = 0;

  InstacedTimes() {
    objectQuantity++;
  }

  public int objectQuantity() {
    return objectQuantity;
  }
}
