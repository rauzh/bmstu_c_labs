from ctypes import c_int, c_void_p, POINTER, CDLL
from tkinter import Button, Entry, Label, Tk, StringVar, END, messagebox

lib = CDLL('lib.dll')

_fibonacci_arr_fill = lib.fibonacci_arr_fill
_fibonacci_arr_fill.argtypes = (POINTER(c_int), c_int)
_fibonacci_arr_fill.restype = c_void_p

_get_unique_arr = lib.get_unique_arr
_get_unique_arr.argtypes = (POINTER(c_int), c_int, POINTER(c_int), c_int)
_get_unique_arr.restype = c_int

def fibonacci_arr_fill(array, n):
    arr = (c_int * n)(*array)
    _fibonacci_arr_fill(arr, n)

    return list(arr)


def get_unique_arr(array):
    n = len(array)
    arr = (c_int * n)(*array)

    n_res = 0
    res_arr = (c_int * n_res)()
    n_res = _get_unique_arr(arr, n, res_arr, n_res)

    res_arr = (c_int * n_res)(*res_arr)
    _get_unique_arr(arr, n, res_arr, n_res)

    arr_res = []

    for i in range(n_res):
        arr_res.append(res_arr[i])

    return arr_res


def fill_fib():
    n_str = input_n.get()

    if (len(n_str) == n_str.count(" ")):
        messagebox.showerror("Ошибка!", "Вы не ввели число")
        return

    try:
        n = int(n_str)
    except:
        result_win.delete(0, END)
        messagebox.showerror("Ошибка!", "Число эл-тов массива должно быть целым числом > 0 😵")
        return

    arr = [0 for i in range(n)]

    new_arr = fibonacci_arr_fill(arr, n)

    arr_str = ' '.join(str(num) for num in new_arr)
    result_win.delete(0, END)
    result_win.insert(END, arr_str)



def unique(): 
    arr_str = input_arr_for_unique.get()

    if (len(arr_str) == arr_str.count(" ")):
        messagebox.showerror("Ошибка!", "Вы не ввели массив")
        return

    try:
        arr = [int(num) for num in arr_str.split()]
    except:
        result_win.delete(0, END)
        messagebox.showerror("Ошибка!", "Вы ввели не только числа!")
        return

    new_arr = get_unique_arr(arr)

    if (len(new_arr) == 0):
        messagebox.showerror("Ошибка!", "Не были найдены полные квадраты")
        return

    arr_str = ' '.join(str(num) for num in new_arr)
    result_win.delete(0, END)
    result_win.insert(END, arr_str)


if __name__ == '__main__':
    task = Tk()
    task.title('C libs in Python (lab_12)')
    task.geometry('900x700')

    # Unique
    input_arr_for_unique_text = Label(text = 'Array for making it unique', font = ('Arial Bold', 24))
    input_arr_for_unique_text.place(x = 100, y = 50, width = 700, height = 30)

    arr_for_unique = StringVar()
    input_arr_for_unique = Entry(task, textvariable = arr_for_unique, font = ('Arial Bold', 16))
    input_arr_for_unique.place(x = 85, y = 100, width = 700, height = 40)

    button_arr_for_unique= Button(task, text = 'Make unique', font = ('Arial Bold', 12), command = lambda: unique())
    button_arr_for_unique.place(x = 200, y = 150, width = 500, height = 70)


    # Fibonacci
    input_arr_for_cycle = Label(text = 'Filling array with fibonacci numbers', font = ('Arial Bold', 24))
    input_arr_for_cycle.place(x = 100, y = 300, width = 700, height = 30)

    input_n_text = Label(text = 'Number of array elements', font = ('Arial Bold', 16))
    input_n_text.place(x = 100, y = 360, width = 700, height = 30)

    n = StringVar()
    input_n = Entry(task, textvariable = n, font = ('Arial Bold', 16))
    input_n.place(x = 85, y = 400, width = 700, height = 40)

    button_arr_fib = Button(task, text = 'Fill array', font = ('Arial Bold', 12), command = lambda: fill_fib())
    button_arr_fib.place(x = 200, y = 450, width = 500, height = 70)


    # Result
    result_text = Label(text = 'Result:', font = ('Arial Bold', 16))
    result_text.place(x = 15, y = 600, width = 150, height = 40)
    result_win = Entry(task, font = ('Arial Bold', 16))
    result_win.place(x = 150, y = 600, width = 700, height = 40)

    task.mainloop()
