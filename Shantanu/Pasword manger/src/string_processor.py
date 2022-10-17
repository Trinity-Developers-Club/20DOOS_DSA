# Simple enough encryptor, decryptor
# expose enc_string(s), dec_string(s)

charsetA = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
charsetB = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"

keyA = 14
keyB = 121

def f(i):
  return (i % keyA) + (i & 1) + 1

def g(i):
  return (i % keyB) + (i & 1) + 1

def id_of(c):
  i = ord(c)
  if ord("a") <= i and i <= ord("z"): return i - ord('a')
  if ord("A") <= i and i <= ord("Z"): return i - ord('A') + 26
  if ord("0") <= i and i <= ord("9"): return i - ord('0') + 52
  return -1

def enc(c, i):
  x = f(i) * ord(c) + g(i)
  y = x % len(charsetA)
  x = x // len(charsetA)
  res = str(charsetA[x] + charsetB[y])
  # print(c, i, res)
  return res

def dec(s, i):
  x, y = id_of(s[0]), id_of(s[1]) 
  x = x * len(charsetA) + y
  x -= g(i)
  x //= f(i)
  res = chr(x)
  # print(s, i, res)
  return res

class StringProcessor:
  @staticmethod
  def enc_string (s):
    res = ""
    for i in range(len(s)):
      res += enc(s[i], len(s) - i)
    return res

  @staticmethod
  def dec_string (s):
    res = ""
    assert(len(s) % 2 == 0)
    k = len(s) // 2
    for i in range(k):
      res += dec(s[2 * i] + s[2 * i + 1], k - i)
    return res
