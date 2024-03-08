int range_sum(int n, int result = 0) {
  if (n == 0) return result;

  result += n;
  n -= 1;

  return range_sum(n, result);
}

int exponent(int num, int power, int result = 0) {
  if ((power - 1) == 0) return result;
  if (result == 0) result = num;

  result = result * num;
  power -= 1;

  return exponent(num, power, result);
}
