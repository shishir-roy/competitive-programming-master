'''
x = int(input('Enter an integer: '))
y = int(input('Enter another integer: '))
formatStr = '{0} + {1} = {2}; {0} * {1} = {3}.'
equations = formatStr.format(x, y, x+y, x*y)
print(equations)
name= input('enter yout name: ')
print('Hello ',name, '!',sep='')
a = 5
b = 9
setStr = 'The set is {{{}, {}}}.'.format(a, b)
print(setStr)
y=input('enter second number: ')
x=input('enter first number: ')
tx=int(x);
ty=int(y);
#print("the sum of two number is ",tx+ty,sep='')
print("the summation of {} and {} is {} \n".format(tx,ty,tx+ty))
person=input("enter the name of the person")
gret="hi {}".format(person)
print(gret)
'''

#import queue
q = queue.Queue()

for i in range(5):
    q.put(i)
while not q.empty():
    print(q.get(), end=' ')
print()