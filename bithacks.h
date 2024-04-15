// Bit Twiddling Hacks
// https://graphics.stanford.edu/~seander/bithacks.html

#include <climits>

namespace bithacks {

/*
 * Check if two integers have opposite signs.
 *
 *
 * @param x The first integer.
 * @param y The second integer.
 * @return True if the integers have opposite signs, false otherwise.
 */
  bool has_opposite_signs(const int x, const int y) {
    return (x ^ y) < 0;
  }

/*
 * Check if an integer is a power of 2.
 *
 * @param x The integer.
 * @return True if the integer is a power of 2, false otherwise.
 */
  bool is_power_of_2(const int x) {
    return x && !(x & (x - 1));
  }

/*
 * Counts the numbers of set bits in an integer.
 *
 * @param x The integer.
 * @return The number of set bits in the integer.
 */
  int pop_count(int x) {
    int count = 0;
    while (x) {
      x &= x - 1; // clear the least significant bit set
      count++;
    }
    return count;
  }

/*
 * Count the consecutive zero bits (trailing) on the right linearly.
 *
 * @param v The input to count trailing zero bits.
 * @return The number of trailing zero bits in the input.
 */
  int count_trailing_zero_bits(unsigned int v) {
    int c;
    if (v) {
      v = (v ^ (v - 1)) >> 1;
      for (c = 0; v; c++) {
        v >>= 1;
      }
    } else {
      c = CHAR_BIT * sizeof(v);
    }
    return c;
  }

/*
 * Interleave bits the obvious way.
 *
 * @param x The first integer.
 * @param y The second integer.
 * @return The interleaved bits of x and y.
 */
unsigned int interleave_bits(const unsigned short x, const unsigned short y) {
  unsigned int z = 0;
  for (int i = 0; i < sizeof(x) * CHAR_BIT; i++) {
    z |= (x & 1U << i) << i | (y & 1U << i) << (i + 1);
  }
  return z;
}

/*
 * Determine if a word has a zero byte.
 *
 * @param v The 32-bit word to check if any 8-bit byte in it is 0.
 * @return True if the word has a zero byte, false otherwise.
 */
bool has_zero_byte(const unsigned int v) {
  return ((v - 0x01010101UL) & ~v & 0x80808080UL) != 0;
}

  /*
   * Determine if a word has a byte equal to n.
   *
   * @param x The 32-bit word to check if any 8-bit byte in it is n.
   * @param n The byte value to check for.
   * @return True if the word has a byte equal to n, false otherwise.
   */
  bool has_value(const unsigned int x, const unsigned char n) {
    return has_zero_byte(x ^ (~0UL / 255 * n));
  }


/*
* Determine if a word has a byte greater than n.
*
* @param x The 32-bit word to check if any 8-bit byte in it is greater than n.
* @param n The byte value to check for.
* @return True if the word has a byte greater than n, false otherwise.
*/
bool has_greater(const unsigned int x, const unsigned char n) {
  return has_zero_byte((x + 0x7f7f7f7fUL - n) & ~x & 0x80808080UL);
}

  /*
   * Determine if a word has a byte less than n.
   *
   * @param x The 32-bit word to check if any 8-bit byte in it is less than n.
   * @param n The byte value to check for.
   * @return True if the word has a byte less than n, false otherwise.
   */
  bool has_less(const unsigned int x, const unsigned char n) {
    return has_zero_byte((x + ~0UL / 255 * (127 - n) | x) & ~0UL / 255 * 128);
  }

  /*
   * Compute the lexicographically next bit permutation.
   *
   * @param v The current permutation of bits.
   * @return The next permutation of bits.
   */
  unsigned int next_permutation(unsigned int v) {
    unsigned int t = v | (v - 1);
    return (t + 1) | (((~t & -~t) - 1) >> (__builtin_ctz(v) + 1));
  }

}
