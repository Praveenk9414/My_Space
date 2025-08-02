s = "    hi there how      u doing   "

lst = s.strip().split()

print(lst)
print(' '.join(lst[::-1]))