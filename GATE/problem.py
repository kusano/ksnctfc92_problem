def conv(w):
  return (w
    .replace("O", "0")
    .replace("L", "1")
    .replace("Z", "2")
    .replace("E", "3")
    .replace("A", "4")
    .replace("S", "5")
    .replace("G", "6")
    .replace("T", "7")
    .replace("Q", "9"))

for w in [
  "GATE",
  "SELF",
  "DEFENCE",
  "FORCES",
  "WELCOME_TO_KSNCTF_C92",
]:
  print w, "->", conv(w)
