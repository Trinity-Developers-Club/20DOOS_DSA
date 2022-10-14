from doctest import Example


def print_rangoli(size):
    # your code goes here
    length = size*2-1
    width = (size*2-1) + (size*2-2)
    lst = []
    for i in range(length//2+1):
        char = 97+size-1
        str=""
        tlist=[]
        for j in range(i+1):
            tlist.append(chr(char))
            char = char-1
        char=char+1
        for j in range(i):
            char=char+1
            tlist.append(chr(char))
        str = "-".join(tlist)
        lst.append(str.center(width,"-"))
    mainstr = "\n".join(lst) 
    lst.reverse()
    mainstr = mainstr +"\n"+ "\n".join(lst[1:])
    print(mainstr)
            
            
if __name__ == '__main__':
    n = int(input())
    print_rangoli(n)



# Examples
'''
size 3

----c----
--c-b-c--
c-b-a-b-c
--c-b-c--
----c----


#size 5

--------e--------
------e-d-e------
----e-d-c-d-e----
--e-d-c-b-c-d-e--
e-d-c-b-a-b-c-d-e
--e-d-c-b-c-d-e--
----e-d-c-d-e----
------e-d-e------
--------e--------


#size 10

------------------j------------------
----------------j-i-j----------------
--------------j-i-h-i-j--------------
------------j-i-h-g-h-i-j------------
----------j-i-h-g-f-g-h-i-j----------
--------j-i-h-g-f-e-f-g-h-i-j--------
------j-i-h-g-f-e-d-e-f-g-h-i-j------
----j-i-h-g-f-e-d-c-d-e-f-g-h-i-j----
--j-i-h-g-f-e-d-c-b-c-d-e-f-g-h-i-j--
j-i-h-g-f-e-d-c-b-a-b-c-d-e-f-g-h-i-j
--j-i-h-g-f-e-d-c-b-c-d-e-f-g-h-i-j--
----j-i-h-g-f-e-d-c-d-e-f-g-h-i-j----
------j-i-h-g-f-e-d-e-f-g-h-i-j------
--------j-i-h-g-f-e-f-g-h-i-j--------
----------j-i-h-g-f-g-h-i-j----------
------------j-i-h-g-h-i-j------------
--------------j-i-h-i-j--------------
----------------j-i-j----------------
------------------j------------------

'''