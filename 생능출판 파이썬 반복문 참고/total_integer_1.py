input_val = int(input())

#sum = 0, count = 1 => 안됨
total, count = 0, 1
while count <= input_val:
  
  total += count                   #튜플 언패킹(# total과 count를 동시에 갱신
  count += 1                       #total, count = total + count, count + 1)
  
print(total + input_val)

